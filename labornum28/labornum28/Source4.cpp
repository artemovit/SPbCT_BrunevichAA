#include <windows.h> 
#include <stdio.h> 
#pragma hdrstop 

void main()
{
	HANDLE hToken;
	LUID setcbnameValue;
	TOKEN_PRIVILEGES tkp;
	DWORD errcod;
	LPVOID lpMsgBuf;
	LPCTSTR msgptr;

	UCHAR InfoBuffer[1000];
	PTOKEN_PRIVILEGES ptgPrivileges = (PTOKEN_PRIVILEGES)InfoBuffer;
	DWORD dwInfoBufferSize;
	DWORD dwPrivilegeNameSize;
	DWORD dwDisplayNameSize;
	UCHAR ucPrivilegeName[500];
	UCHAR ucDisplayName[500];
	DWORD dwLangId;
	UINT i;

	if (!OpenProcessToken(GetCurrentProcess(),
		TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
	{
		puts("OpenProcessToken");
		return;
	}

	GetTokenInformation(hToken, TokenPrivileges, InfoBuffer,
		sizeof InfoBuffer, &dwInfoBufferSize);

	printf("Account privileges: \n\n");
	for (i = 0; i < ptgPrivileges->PrivilegeCount; i++)
	{
		dwPrivilegeNameSize = sizeof ucPrivilegeName;
		dwDisplayNameSize = sizeof ucDisplayName;
		LookupPrivilegeName(NULL, &ptgPrivileges->Privileges[i].Luid,
			(char*)ucPrivilegeName, &dwPrivilegeNameSize);
		LookupPrivilegeDisplayName(NULL, (char*)ucPrivilegeName,
			(char*)ucDisplayName, &dwDisplayNameSize, &dwLangId);
		printf("%s   (%s)\n", ucPrivilegeName, ucDisplayName);
	}

}