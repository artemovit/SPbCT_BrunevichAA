#define _WIN32_WINNT 0x0500 

#define UNICODE 
#ifdef UNICODE 
#define _UNICODE 
#endif 


#include <windows.h> 
#include <stdio.h> 
#include <sddl.h> 


void main(void) {
    wchar_t UserName[256];
    int MaxUserNameLength = 256;

    SID Sid[1024];
    PSID pSid;
    LPTSTR StringSid;
    DWORD SidSize = 1024;
    SID_NAME_USE SidType;

    LPTSTR DomainName = NULL;
    DWORD DomainNameSize = 16; // ����� ����� ������ 


    HANDLE hHeap;
    hHeap = GetProcessHeap();
    pSid = &Sid[0];

    DomainName = (LPTSTR)HeapAlloc(hHeap, 0, DomainNameSize * sizeof(TCHAR));

    LookupAccountName(
        NULL,           // ��������� ��������� 
        UserName, pSid, &SidSize, DomainName, &DomainNameSize, &SidType);

    if (!ConvertSidToStringSid(pSid, &StringSid))   /* ������ ��� ������ �������� ����  ������� */
        printf("Convert SID to string SID failed.");
    wprintf(L"StringSid %s\n", StringSid);

    LocalFree(StringSid);
    HeapFree(hHeap, 0, DomainName);
}