#include <windows.h>
#include <iostream>
using namespace std;
int main()
{
	DWORD result;
	HKEY hk;
	result = RegCreateKeyEx(HKEY_CURRENT_USER, "software\\CSSO",0,0,REG_OPTION_NON_VOLATILE,KEY_WRITE,0, &hk,0);
	if (result == ERROR_SUCCESS)
		cout << "cheie creata";
	else
		cout << "d3d";
	system("pause");
	return 0;
}
