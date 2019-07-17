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
bool ListDirectoryContents(const char *sDir, HKEY current_key)
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
				printf("Directory: %s\n", sPath);
				current_key = createKey(fdFile.cFileName);
				ListDirectoryContents(sPath, current_key);
			}
			else {
				if (current_key == NULL)
				{
					current_key = createKey("");
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
	ListDirectoryContents("D:\\exemplu", NULL);
	system("pause");
}