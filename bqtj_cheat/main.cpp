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
        wcout << "进程名称：" << processName << endl;
        cout << "进程pid：" << pid << endl;
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
        cout << "万物皆薄の爆枪辅助in20240128(免费)" << endl;
        if (shuru != -1) {
            cout <<shuru<< ".修改成功" << endl;
        }
        cout << "输入数字再按回车：" << endl;
        cout << "0.退出辅助" << endl;
        cout << "1.按钮点亮" << endl;
        cout << "2.锁护盾(先挨一下打或进去等一会)" << endl;
        cout << "3.秒杀(先打一下,搭配锁盾食用因为也秒自己)" << endl;
        cout << "4.免费总统,商城(先开按钮点亮买总统再去买一下商城)" << endl;
        cout << "5.强制进入竞技场,军队等" << endl;
        cin >> shuru;
        switch (shuru)
        {
        case 0:
            break;
        case 1:
            ScanAddress(hProcess, 搜索按钮点亮, 0);
            WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &修改按钮点亮, sizeof(修改按钮点亮), 0);
            break;
        case 2:
            ScanAddress(hProcess, 搜索锁护盾, 0);
            WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &修改锁护盾, sizeof(修改锁护盾), 0);
            break;
        case 3:
            ScanAddress(hProcess, 搜索秒杀, 0);
            WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &修改秒杀, sizeof(修改秒杀), 0);
            break;
        case 4:
            ScanAddress(hProcess, 搜索免费总统, 0);
            WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &修改免费总统, sizeof(修改免费总统), 0);
            ScanAddress(hProcess, 搜索免费总统, 0);
            WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &修改免费总统, sizeof(修改免费总统), 0);
            break;
        case 5:
            ScanAddress(hProcess, 搜索进入竞技场, 0);
            WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &修改进入竞技场1, sizeof(修改进入竞技场1), 0);
            temp1 = hanshu_dizhi + 103;
            WriteProcessMemory(hProcess, (LPVOID)temp1, &修改进入竞技场2, sizeof(修改进入竞技场2), 0);
            break;
        case 114514:
            cout << "好臭" << endl;
        default:
            cout << "未找到" << endl;
            break;
        }

        if (shuru == 0) {
            break;
        }
    }

   
    

    system("pause");
    return 0;
}