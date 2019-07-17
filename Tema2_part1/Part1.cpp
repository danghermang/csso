#include <iostream>
#include <Windows.h>
#include <Tlhelp32.h>

void write_processes_to_map() {
    TCHAR map_file_name[] = TEXT("Process_file");
    PROCESSENTRY32 process_entry;
    const int length = 10000;
    HANDLE map_handle = CreateFileMapping(INVALID_HANDLE_VALUE, 0, PAGE_READWRITE, 0, length, map_file_name);
    if (map_handle == NULL)
    {
        printf("CreateFileMapping() error 0x%08x\n", GetLastError());
        return;
    }
    char* map_pointer = (char*)MapViewOfFile(map_handle, FILE_MAP_ALL_ACCESS, 0, 0, length);
    if (map_pointer == NULL)
    {
        printf("MapViewOfFile() error 0x%08x\n", GetLastError());
        CloseHandle(map_handle);
        return;
    }

    HANDLE snapshot_process_handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot_process_handle == INVALID_HANDLE_VALUE)
    {
        printf("CreateToolhelp32Snapshot failed.err = %d \n", GetLastError());
        CloseHandle(map_handle);
        UnmapViewOfFile(map_pointer);
        return;
    }

    process_entry.dwSize = sizeof(PROCESSENTRY32);

    if (!Process32First(snapshot_process_handle, &process_entry))
    {
        printf("Process32First failed. err = %d \n", GetLastError());
        CloseHandle(snapshot_process_handle);
        CloseHandle(map_handle);
        UnmapViewOfFile(map_pointer);
        return;
    }

    do
    {
        TCHAR message[length];
        sprintf(message, "@<%d><%d><%s>\n", process_entry.th32ProcessID, process_entry.th32ParentProcessID, process_entry.szExeFile);
        strcat(map_pointer, message);
        printf("%s\n", message);
    } while (Process32Next(snapshot_process_handle, &process_entry));
    system("pause");
    CloseHandle(snapshot_process_handle);
    CloseHandle(map_handle);
    UnmapViewOfFile(map_pointer);
}

int main()
{
    write_processes_to_map();
    return 0;
}

