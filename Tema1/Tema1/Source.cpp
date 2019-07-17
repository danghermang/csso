#include <windows.h>
#include <cstdio>

HKEY createKey(const char *fileName)
{
	DWORD result;
	HKEY hk;
	char sPath[2048];
	sprintf_s(sPath, "%s\\%s", "software\\CSSO", fileName);
	result = RegCreateKeyEx(HKEY_CURRENT_USER, sPath, 0, 0, REG_OPTION_NON_VOLATILE, KEY_WRITE, 0, &hk, 0);
	if (result == ERROR_SUCCESS) {
		printf("cheie creata\n");
		return hk;
	}
	printf("d3d");
	return NULL;
}
bool Parcurge(const char *sDir,HKEY current_key,const char* sDir2)
{
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;
	char sPath[2048];
	sprintf_s(sPath, "%s\\*.*", sDir);
	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
	{
		printf("Path not found: [%s]\n", sDir);
		return false;
	}

	do
	{
		if (strcmp(fdFile.cFileName, ".") != 0
			&& strcmp(fdFile.cFileName, "..") != 0)
		{
			sprintf_s(sPath, "%s\\%s", sDir, fdFile.cFileName);
			if (fdFile.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
//				char newfile[2048];
//				char *s = strstr(sPath, sDir2);
//				int position = s - sPath;
//				strncpy_s(newfile, sPath + position, strlen(sPath) - position);
				printf("Directory: %s\n", sPath);
				current_key=createKey(sPath);
				Parcurge(sPath,current_key,sDir2);
			}
			else {
				if (current_key==NULL)
				{
					current_key = createKey(sDir2);
				}
				DWORD filesize = (fdFile.nFileSizeHigh * (MAXDWORD + 1)) + fdFile.nFileSizeLow;
				printf("File: %s\t", sPath);
				printf("Size:%lld\n", filesize);
//				HKEY cheie = createKey(sPath, "", initdir);
				if (RegSetValueEx(current_key, fdFile.cFileName, 0, REG_DWORD, (const BYTE*)&filesize, sizeof(filesize)) == ERROR_SUCCESS)
					printf("CREAT valoare\n");
				else
					printf("EROARE CREAT VALOARE\n");
				
			}
		}
	} while (FindNextFile(hFind, &fdFile));
	FindClose(hFind);

	return true;
}

int main() {
	Parcurge("D:\\exemplu",NULL, "D:\\exemplu");
	system("pause");
}