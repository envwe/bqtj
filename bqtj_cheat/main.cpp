#include <iostream>
#include <windows.h>
#include <graphics.h> // 引用了EasyX
#include <conio.h>
#include "GetProcessIdByName.hpp"
#include "FindMemByMarkCode.hpp"
#include "MarkCode.h"

using namespace std;

int main() {
    wstring processName = L"bqtj.exe";
    DWORD pid = GetProcessIdByName(processName);
    if (pid != 0) {
        wcout << "Process Name: " << processName << endl;
        cout << "Process PID: " << pid << endl;
    } else {
        cout << "Process not found." << endl;
        cout << "Please read the Readme file." << endl;
        system("pause");
        return 0;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (hProcess == NULL) {
        cerr << "Failed to open process. Error code: " << GetLastError() << endl;
        cout << "Please read the Readme file." << endl;
        system("pause");
        return 0;
    }
    cout << "Successfully opened process." << endl;

    initgraph(320, 480);
    setbkcolor(WHITE);
    cleardevice();
    ExMessage m;
    uintptr_t temp1;

    // const wchar_t esc[] = L"按exc退出";
    // outtextxy(0, 0, esc);
    settextcolor(GREEN);
    settextstyle(20, 0, _T("Anti-aliasing"));
    outtextxy(0, 0, L"Please read the Readme file.");
    settextcolor(RED);
    outtextxy(20, 40, L"Button Light");
    outtextxy(20, 80, L"Lock Shield");
    outtextxy(20, 120, L"One Hit Kill");
    outtextxy(20, 160, L"Free President Shop");
    outtextxy(20, 200, L"Enter Arena");
    outtextxy(20, 240, L"Increase Item Gain");
    outtextxy(20, 280, L"Quick Endless Mode");
    settextcolor(GREEN);
    setfillcolor(YELLOW);
    short Size = 19;
    fillrectangle(0, 40, Size, 40 + Size);
    fillrectangle(0, 80, Size, 80 + Size);
    fillrectangle(0, 120, Size, 120 + Size);
    fillrectangle(0, 160, Size, 160 + Size);
    fillrectangle(0, 200, Size, 200 + Size);
    fillrectangle(0, 240, Size, 240 + Size);
    fillrectangle(0, 280, Size, 280 + Size);
    setfillcolor(CYAN);

    while (true) {
        Sleep(10);
        m = getmessage(EX_MOUSE | EX_KEY);
        cout << m.x << "," << m.y << endl;

        switch (m.message) {
        case WM_LBUTTONDOWN:
            cout << "lb is pressed" << endl;
            if (m.x >= 0 && m.x <= Size) {
                if (m.y >= 40 && m.y <= 40 + Size) {
                    fillrectangle(0, 40, Size, 40 + Size);
                    ScanAddress(hProcess, searchButtonLight, 0);
                    WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &modifyButtonLight, sizeof(modifyButtonLight), 0);
                    outtextxy(20, 40, L"Button Light");
                }
                if (m.y >= 80 && m.y <= 80 + Size) {
                    fillrectangle(0, 80, Size, 80 + Size);
                    ScanAddress(hProcess, searchLockShield, 0);
                    WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &modifyLockShield, sizeof(modifyLockShield), 0);
                    outtextxy(20, 80, L"Lock Shield");
                }
                if (m.y >= 120 && m.y <= 120 + Size) {
                    fillrectangle(0, 120, Size, 120 + Size);
                    ScanAddress(hProcess, searchOneHitKill, 0);
                    WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &modifyOneHitKill, sizeof(modifyOneHitKill), 0);
                    outtextxy(20, 120, L"One Hit Kill");
                }
                if (m.y >= 160 && m.y <= 160 + Size) {
                    fillrectangle(0, 160, Size, 160 + Size);
                    ScanAddress(hProcess, searchFreePresident, 0);
                    WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &modifyFreePresident, sizeof(modifyFreePresident), 0);
                    ScanAddress(hProcess, searchFreePresident, 0);
                    WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &modifyFreePresident, sizeof(modifyFreePresident), 0);
                    outtextxy(20, 160, L"Free President Shop");
                }
                if (m.y >= 200 && m.y <= 200 + Size) {
                    fillrectangle(0, 200, Size, 200 + Size);
                    ScanAddress(hProcess, searchEnterArena, 0);
                    WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &modifyEnterArena1, sizeof(modifyEnterArena1), 0);
                    temp1 = hanshu_dizhi + 103;
                    WriteProcessMemory(hProcess, (LPVOID)temp1, &modifyEnterArena2, sizeof(modifyEnterArena2), 0);
                    outtextxy(20, 200, L"Enter Arena");
                }
                if (m.y >= 240 && m.y <= 240 + Size) {
                    fillrectangle(0, 240, Size, 240 + Size);
                    ScanAddress(hProcess, searchIncreaseItemGain, 0);
                    WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &modifyIncreaseItemGain, sizeof(modifyIncreaseItemGain), 0);
                    outtextxy(20, 240, L"Increase Item Gain");
                }
                if (m.y >= 280 && m.y <= 280 + Size) {
                    fillrectangle(0, 280, Size, 280 + Size);
                    ScanAddress(hProcess, searchQuickEndless, 0);
                    WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &modifyQuickEndless, sizeof(modifyQuickEndless), 0);
                    outtextxy(20, 280, L"Quick Endless Mode");
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

