#include <Windows.h>
#include <Tlhelp32.h>
#include <iostream>
#include <list>
using namespace std;
typedef struct {
    int PID;
    int PPID;
    char EXE[256];

} Process;

int process_tree_vector[300];

void set_token_priviledge() {
    HANDLE token_handle;
    TOKEN_PRIVILEGES token_privileges;
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &token_handle)) {
        DWORD e = GetLastError();
        printf("OpenProcessToken %d\n", e);
        return;
    }
    LUID lpLuid;
    if (!LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &lpLuid)) {
        DWORD e = GetLastError();
        printf("LookupPrivilegeValue %d\n", e);
        CloseHandle(token_handle);
        return;
    }
    token_privileges.PrivilegeCount = 1;
    token_privileges.Privileges[0].Luid = lpLuid;
    token_privileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    if (!AdjustTokenPrivileges(token_handle, FALSE, &token_privileges, sizeof(TOKEN_PRIVILEGES), NULL, NULL)) {
        DWORD e = GetLastError();
        printf("AdjustTokenPrivileges %d\n", e);
        CloseHandle(token_handle);
        return;
    }
    CloseHandle(token_handle);
}

void kill_tree_process(int n) {
    if (process_tree_vector[n] != NULL) {
        DWORD curr_process_id = process_tree_vector[n];
        PROCESSENTRY32 process_entry;
        memset(&process_entry, 0, sizeof(PROCESSENTRY32));
        process_entry.dwSize = sizeof(PROCESSENTRY32);
        HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (Process32First(hSnap, &process_entry))
        {
            BOOL check = TRUE;
            while (check)
            {
                //kill all children
                if (process_entry.th32ParentProcessID == curr_process_id)
                {
                    HANDLE child_process_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, process_entry.th32ProcessID);
                    if (child_process_handle)
                    {
                        TerminateProcess(child_process_handle, 1);
                        CloseHandle(child_process_handle);
                    }
                }
                check = Process32Next(hSnap, &process_entry);
            }
            //kill the parent too hahaha >:)
            HANDLE handle_process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, curr_process_id);
            if (handle_process)
            {
                TerminateProcess(handle_process, 1);
                cout << "Worked" << '\n';
                CloseHandle(handle_process);
            }
            else {
                cout << "Can't close this one" << '\n';
            }
        }
    }
    else if (n == 1) {
        cout << "Can't close system" << '\n';
    }
    else {
        cout << "Stop right there,criminal scum!(wrong tree)" << '\n';
    }
}

void compute_process_tree(int processId, std::list<Process> process_list, int level) {
    level++;
    for (auto v : process_list) {
        if (v.PPID == processId && v.PID != v.PPID) {
            for (auto x : process_list) {
                if (x.PID != v.PID) {
                    if (x.PID == processId) {
                        if (x.PPID == v.PID) {
                            for (int i = 0; i < level; ++i) {
                                printf("\t");
                            }
                            printf("%s %d\n", v.EXE, v.PID);
                        }
                        else {
                            for (int i = 0; i < level; ++i) {
                                printf("\t");
                            }
                            printf("%s %d\n", v.EXE, v.PID);
                            compute_process_tree(v.PID, process_list, level);
                        }
                    }
                }
            }
        }
    }
}

void print_process_tree(std::list<Process> process_list) {
    char message[30];
    int tree_counter = 1;
    int level=0;
    bool check;
    for (auto element : process_list) {
        check = true;
        if (element.PID == element.PPID) {
            sprintf(message, "Tree number %d\n:", tree_counter);
            process_tree_vector[tree_counter] = element.PID;
            printf("%s", message);
            printf("%s %d\n", element.EXE, element.PID);
            check = false;
            compute_process_tree(element.PID, process_list, level);
            printf("################################################################################\n");
            tree_counter++;
        }
        for (auto x : process_list) {
            if (element.PID != x.PID) {
                if (element.PPID == x.PID) {
                    if (element.PID == x.PPID) {
                        sprintf(message, "Tree number %d\n:", tree_counter);
                        process_tree_vector[tree_counter] = element.PID;
                        printf("%s", message);
                        printf("%s %d\n", element.EXE, element.PID);
                        check = false;
                        compute_process_tree(element.PID, process_list, level);
                        printf("################################################################################\n");
                        tree_counter++;
                    }
                    else {
                        check = false;
                    }
                }
            }
        }
        if (check) {
            sprintf(message, "Tree number %d\n:", tree_counter);
            process_tree_vector[tree_counter] = element.PID;
            printf("%s", message);
            printf("%s %d\n", element.EXE, element.PID);
            compute_process_tree(element.PID, process_list, level);
            printf("################################################################################\n");
            tree_counter++;
        }
    }

}

void read_file_and_print_tree() {
    const int length = 10000;
    TCHAR file_name[] = TEXT("Process_file");
    HANDLE handle_map_file = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, file_name);
    if (!handle_map_file)
    {
        DWORD e = GetLastError();
        printf("OpenFileMapping error %d\n", e);
        return;
    }
    char* buf = (char*)MapViewOfFile(handle_map_file, FILE_MAP_ALL_ACCESS, 0, 0, length);
    if (buf ==NULL)
    {
        DWORD e = GetLastError();
        printf("MapViewOfFile error %d\n", e);
        CloseHandle(handle_map_file);
        return;
    }
    std::list<Process> process_list;
    Process process;
    char current_pid[256];
    char parent_pid[256];
    char* token;
    int j;
    int i;
    token = strtok(buf, "@");
    token = strtok(NULL, "@");
    do {
        j = 0;
        i = 1;
        memset(&current_pid[0], 0, sizeof(current_pid));
        memset(&parent_pid[0], 0, sizeof(parent_pid));
        if (token != NULL) {
            while (*(token + i) != '>') {
                current_pid[j] = *(token + i);
                ++i;
                ++j;
            }
            process.PID = atoi(current_pid);
            while(*(token + i) != '<') {
                ++i;
            }
            j = 0;
            i++;
            while (*(token + i) != '>') {
                parent_pid[j] = *(token + i);
                ++i;
                ++j;
            }
            process.PPID = atoi(parent_pid);
            while (*(token + i) != '<') {
                ++i;
            }
            j = 0;
            i++;
            while (*(token + i) != '>') {
                process.EXE[j] = *(token + i);
                ++i;
                ++j;
            }
            process.EXE[j] = '\0';
            token = strtok(NULL, "@");
            process_list.push_back(process);
        }
    } while (token!=NULL);
    print_process_tree(process_list);
    CloseHandle(handle_map_file);
    UnmapViewOfFile(buf);
}

int main()
{
    set_token_priviledge();
    read_file_and_print_tree();
    int n;
    std::cout << "Number of tree: ";
    std::cin >> n;
    kill_tree_process(n);
    system("pause");
    return 0;
}
