#define _WIN32_WINNT 0x0500 
#ifndef UNICODE 
#define UNICODE 
#endif 

#include <windows.h> 
#include <stdio.h> 
#include <sddl.h> 
#include <Aclapi.h> 

void main(void) {
    PSID pSid;
    PSECURITY_DESCRIPTOR pSD;
    PACL pDACL;
    LPTSTR StringSid = NULL;
    ULONG Error;
    HANDLE hFile;

    hFile = CreateFile(TEXT("MyFile.txt"), READ_CONTROL, 0, NULL, OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL, NULL);

    Error = GetSecurityInfo(hFile,
        SE_FILE_OBJECT,        // ��� ������� 
        OWNER_SECURITY_INFORMATION |
        DACL_SECURITY_INFORMATION,
        &pSid,                 // Sid ��������� 
        NULL,                  // Sid ������ 
        &pDACL, NULL,   // ������ ���� ������� 
        &pSD         // ���������� ������); 
    );
        if (Error != ERROR_SUCCESS) printf("GetSecurityInfo Error\n");


    if (!ConvertSidToStringSid(pSid, &StringSid)) /* ������ ��� ������ �������� ����  ������� */
        printf("Convert SID to string SID failed.");

    wprintf(L"StringSid %s\n", StringSid);

    LocalFree(pSD);
    LocalFree(StringSid);
}