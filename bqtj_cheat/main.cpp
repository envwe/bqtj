#include <iostream>
#include <windows.h>


#include "GetProcessIdByName.hpp"
#include"FindMemByMarkCode.hpp"
#include"MarkCode.h"

using namespace std;



int main() {
	wstring processName = L"bqtj.exe";
    DWORD pid = GetProcessIdByName(processName);
    if (pid != 0) {
        wcout << "�������ƣ�" << processName << endl;
        cout << "����pid��" << pid << endl;
    }
    else {
        cout << "Process not found." << endl;
        system("pause");
        return 0;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (hProcess == NULL) {
        cerr << "Failed to open process. Error code: " << GetLastError() << endl;
        system("pause");
        return 0;
    }
    cout << "Successfully opened process." << endl;



    int shuru=-1;
    uintptr_t temp1;
    
    while (true)
    {
        system("cls");
        cout << "����Ա��α�ǹ����in20240128(���)" << endl;
        if (shuru != -1) {
            cout <<shuru<< ".�޸ĳɹ�" << endl;
        }
        cout << "���������ٰ��س���" << endl;
        cout << "0.�˳�����" << endl;
        cout << "1.��ť����" << endl;
        cout << "2.������(�Ȱ�һ�´���ȥ��һ��)" << endl;
        cout << "3.��ɱ(�ȴ�һ��,��������ʳ����ΪҲ���Լ�)" << endl;
        cout << "4.�����ͳ,�̳�(�ȿ���ť��������ͳ��ȥ��һ���̳�)" << endl;
        cout << "5.ǿ�ƽ��뾺����,���ӵ�" << endl;
        cin >> shuru;
        switch (shuru)
        {
        case 0:
            break;
        case 1:
            ScanAddress(hProcess, ������ť����, 0);
            WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &�޸İ�ť����, sizeof(�޸İ�ť����), 0);
            break;
        case 2:
            ScanAddress(hProcess, ����������, 0);
            WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &�޸�������, sizeof(�޸�������), 0);
            break;
        case 3:
            ScanAddress(hProcess, ������ɱ, 0);
            WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &�޸���ɱ, sizeof(�޸���ɱ), 0);
            break;
        case 4:
            ScanAddress(hProcess, ���������ͳ, 0);
            WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &�޸������ͳ, sizeof(�޸������ͳ), 0);
            ScanAddress(hProcess, ���������ͳ, 0);
            WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &�޸������ͳ, sizeof(�޸������ͳ), 0);
            break;
        case 5:
            ScanAddress(hProcess, �������뾺����, 0);
            WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &�޸Ľ��뾺����1, sizeof(�޸Ľ��뾺����1), 0);
            temp1 = hanshu_dizhi + 103;
            WriteProcessMemory(hProcess, (LPVOID)temp1, &�޸Ľ��뾺����2, sizeof(�޸Ľ��뾺����2), 0);
            break;
        case 114514:
            cout << "�ó�" << endl;
        default:
            cout << "δ�ҵ�" << endl;
            break;
        }

        if (shuru == 0) {
            break;
        }
    }

   
    

    system("pause");
    return 0;
}