#include <iostream>
#include <windows.h>
#include <graphics.h>		// 引用了EasyX
#include <conio.h>
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
        cout << "不如先读读那个叫Readme的文件" << endl;
        system("pause");
        return 0;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (hProcess == NULL) {
        cerr << "Failed to open process. Error code: " << GetLastError() << endl;
        cout << "不如先读读那个叫Readme的文件" << endl;
        system("pause");
        return 0;
    }
    cout << "Successfully opened process." << endl;


    initgraph(320, 480);
    setbkcolor(WHITE);
    cleardevice();
    ExMessage m;
    uintptr_t temp1;
    
    //const wchar_t esc[] = L"按exc退出";
    //outtextxy(0, 0, esc);
    settextcolor(GREEN);
    settextstyle(20, 0, _T("抗锯齿效果"));
    outtextxy(0,0,L"不如先读读那个叫Readme的文件");
    settextcolor(RED);
    outtextxy(20, 40, L"按钮点亮");
    outtextxy(20, 80, L"锁护盾");
    outtextxy(20, 120, L"秒杀");
    outtextxy(20, 160, L"免费总统商城");
    outtextxy(20, 200, L"进入竞技场");
    outtextxy(20, 240, L"获得物品增加");
    outtextxy(20, 280, L"速刷无尽");
    settextcolor(GREEN);
    setfillcolor(YELLOW);
    short Size = 19;
    fillrectangle(0, 40, Size, 40 + Size);
    fillrectangle(0, 80, Size, 80 + Size);
    fillrectangle(0, 120, Size, 120 + Size);
    fillrectangle(0, 160, Size, 160 + Size);
    fillrectangle(0, 200, Size, 200 + Size);
    fillrectangle(0, 240, Size, 240 + Size);
    fillrectangle(0,280, Size,280+ Size);
    setfillcolor(CYAN);

    while (true)
    {
        Sleep(10);
        m = getmessage(EX_MOUSE | EX_KEY);
        cout << m.x << "," << m.y << endl;

        switch (m.message)
        {
        case WM_LBUTTONDOWN:
             cout << "lb is pressed" << endl; 
             if (m.x >= 0 && m.x <= Size) {
                 if (m.y >= 40 && m.y <= 40 + Size) {
                     fillrectangle(0, 40, Size, 40 + Size);
                     ScanAddress(hProcess, 搜索按钮点亮, 0);
                     WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &修改按钮点亮, sizeof(修改按钮点亮), 0);
                     outtextxy(20, 40, L"按钮点亮");
                 }
                 if (m.y >= 80 && m.y <= 80 + Size) {
                     fillrectangle(0, 80, Size, 80 + Size);
                     ScanAddress(hProcess, 搜索锁护盾, 0);
                     WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &修改锁护盾, sizeof(修改锁护盾), 0);
                     outtextxy(20, 80, L"锁护盾");
                 }
                 if (m.y >= 120 && m.y <= 120 + Size) {
                     fillrectangle(0, 120, Size, 120 + Size);
                     ScanAddress(hProcess, 搜索秒杀, 0);
                     WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &修改秒杀, sizeof(修改秒杀), 0);
                     outtextxy(20, 120, L"秒杀");
                 }
                 if (m.y >= 160 && m.y <= 160 + Size) {
                     fillrectangle(0, 160, Size, 160 + Size);
                     ScanAddress(hProcess, 搜索免费总统, 0);
                     WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &修改免费总统, sizeof(修改免费总统), 0);
                     ScanAddress(hProcess, 搜索免费总统, 0);
                     WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &修改免费总统, sizeof(修改免费总统), 0);
                     outtextxy(20, 160, L"免费总统商城");
                 }
                 if (m.y >= 200 && m.y <= 200 + Size) {
                     fillrectangle(0, 200, Size, 200 + Size);
                     ScanAddress(hProcess, 搜索进入竞技场, 0);
                     WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &修改进入竞技场1, sizeof(修改进入竞技场1), 0);
                     temp1 = hanshu_dizhi + 103;
                     WriteProcessMemory(hProcess, (LPVOID)temp1, &修改进入竞技场2, sizeof(修改进入竞技场2), 0);
                     outtextxy(20, 200, L"进入竞技场");
                 }
                 if (m.y >= 240 && m.y <= 240 + Size) {
                     fillrectangle(0, 240, Size, 240 + Size);
                     ScanAddress(hProcess, 搜索获得物品增加, 0);
                     WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &修改获得物品增加, sizeof(修改获得物品增加), 0);
                     outtextxy(20, 240, L"获得物品增加");
                 }
                 if (m.y >= 280 && m.y <= 280 + Size) {
                     fillrectangle(0, 280, Size, 280 + Size);
                     ScanAddress(hProcess, 搜索速刷无尽, 0);
                     WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &修改速刷无尽, sizeof(修改速刷无尽), 0);
                     outtextxy(20, 280, L"速刷无尽");
                 }
             }
            break;
        case WM_KEYDOWN:
            if (m.vkcode == VK_ESCAPE) {
                return 0;
            }
            break;
        }
    }

    system("pause");
    return 0;
}