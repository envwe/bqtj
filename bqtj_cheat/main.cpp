#include <iostream>
#include <windows.h>
#include <graphics.h>		// ������EasyX
#include <conio.h>
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
        cout << "�����ȶ����Ǹ���Readme���ļ�" << endl;
        system("pause");
        return 0;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (hProcess == NULL) {
        cerr << "Failed to open process. Error code: " << GetLastError() << endl;
        cout << "�����ȶ����Ǹ���Readme���ļ�" << endl;
        system("pause");
        return 0;
    }
    cout << "Successfully opened process." << endl;


    initgraph(320, 480);
    setbkcolor(WHITE);
    cleardevice();
    ExMessage m;
    uintptr_t temp1;
    
    //const wchar_t esc[] = L"��exc�˳�";
    //outtextxy(0, 0, esc);
    settextcolor(GREEN);
    settextstyle(20, 0, _T("�����Ч��"));
    outtextxy(0,0,L"�����ȶ����Ǹ���Readme���ļ�");
    settextcolor(RED);
    outtextxy(20, 40, L"��ť����");
    outtextxy(20, 80, L"������");
    outtextxy(20, 120, L"��ɱ");
    outtextxy(20, 160, L"�����ͳ�̳�");
    outtextxy(20, 200, L"���뾺����");
    outtextxy(20, 240, L"�����Ʒ����");
    outtextxy(20, 280, L"��ˢ�޾�");
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
                     ScanAddress(hProcess, ������ť����, 0);
                     WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &�޸İ�ť����, sizeof(�޸İ�ť����), 0);
                     outtextxy(20, 40, L"��ť����");
                 }
                 if (m.y >= 80 && m.y <= 80 + Size) {
                     fillrectangle(0, 80, Size, 80 + Size);
                     ScanAddress(hProcess, ����������, 0);
                     WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &�޸�������, sizeof(�޸�������), 0);
                     outtextxy(20, 80, L"������");
                 }
                 if (m.y >= 120 && m.y <= 120 + Size) {
                     fillrectangle(0, 120, Size, 120 + Size);
                     ScanAddress(hProcess, ������ɱ, 0);
                     WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &�޸���ɱ, sizeof(�޸���ɱ), 0);
                     outtextxy(20, 120, L"��ɱ");
                 }
                 if (m.y >= 160 && m.y <= 160 + Size) {
                     fillrectangle(0, 160, Size, 160 + Size);
                     ScanAddress(hProcess, ���������ͳ, 0);
                     WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &�޸������ͳ, sizeof(�޸������ͳ), 0);
                     ScanAddress(hProcess, ���������ͳ, 0);
                     WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &�޸������ͳ, sizeof(�޸������ͳ), 0);
                     outtextxy(20, 160, L"�����ͳ�̳�");
                 }
                 if (m.y >= 200 && m.y <= 200 + Size) {
                     fillrectangle(0, 200, Size, 200 + Size);
                     ScanAddress(hProcess, �������뾺����, 0);
                     WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &�޸Ľ��뾺����1, sizeof(�޸Ľ��뾺����1), 0);
                     temp1 = hanshu_dizhi + 103;
                     WriteProcessMemory(hProcess, (LPVOID)temp1, &�޸Ľ��뾺����2, sizeof(�޸Ľ��뾺����2), 0);
                     outtextxy(20, 200, L"���뾺����");
                 }
                 if (m.y >= 240 && m.y <= 240 + Size) {
                     fillrectangle(0, 240, Size, 240 + Size);
                     ScanAddress(hProcess, ���������Ʒ����, 0);
                     WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &�޸Ļ����Ʒ����, sizeof(�޸Ļ����Ʒ����), 0);
                     outtextxy(20, 240, L"�����Ʒ����");
                 }
                 if (m.y >= 280 && m.y <= 280 + Size) {
                     fillrectangle(0, 280, Size, 280 + Size);
                     ScanAddress(hProcess, ������ˢ�޾�, 0);
                     WriteProcessMemory(hProcess, (LPVOID)hanshu_dizhi, &�޸���ˢ�޾�, sizeof(�޸���ˢ�޾�), 0);
                     outtextxy(20, 280, L"��ˢ�޾�");
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