#include <iostream>
#include <windows.h>


using namespace std;
//�����ֱ�Ϊ�����̾���������롢ƫ�ơ���ȡ���ȡ���ʼɨ��λ���á�ɨ�����λ��
uintptr_t hanshu_dizhi; //��¼�������Ӧ�ĵ�ַ
uintptr_t ScanAddress(HANDLE process, const char* markCode, int nOffset, unsigned long dwReadLen = 4, uintptr_t StartAddr = 0x400000, uintptr_t EndAddr = 0x7FFFFFFF, int InstructionLen = 0)
{
	//************���������룬ת�����ֽ�*****************
	if (strlen(markCode) % 2 != 0) return 0;
	//�����볤��
	int len = strlen(markCode) / 2;  //��ȡ������ֽ���

	//��������ת����byte�� ������m_code ��
	BYTE* m_code = new BYTE[len];
	for (int i = 0; i < len; i++)
	{
		//��������ɵ����ַ���һ�ֻ����������͡�
		char c[] = { markCode[i * 2], markCode[i * 2 + 1], '\0' };
		//������nptr�ַ������ݲ���base��ת���ɳ�������
		m_code[i] = (BYTE)::strtol(c, NULL, 16);
	}
	//ÿ�ζ�ȡ��Ϸ�ڴ���Ŀ�Ĵ�С
	const DWORD pageSize = 4096;

	/* ���������� */
		//ÿҳ��ȡ4096���ֽ�
		BYTE * page = new BYTE[pageSize];
	uintptr_t tmpAddr = StartAddr;
	//�����������һ�����ȵı�ʶ
	int compare_one = 0;

	while (tmpAddr <= EndAddr)
	{
		::ReadProcessMemory(process, (LPCVOID)tmpAddr,page, pageSize, 0); //��ȡ0x400000���ڴ����ݣ�������page������ΪpageSize

		//�ڸ�ҳ�в���������
		for (int i = 0; i < pageSize; i++)
		{
			if (m_code[0] == page[i])//��һ���ֽ���������ĵ�һ���ֽ���ͬ��������
			{
				for (int j = 0; j < len - 1; j++)
				{
					if (m_code[j + 1] == page[i + j + 1])//�Ƚ�ÿһ���ֽڵĴ�С������ͬ���˳�
					{
						compare_one++;
					}
					else
					{
						compare_one = 0;
						break;
					}//����¸��Աȵ��ֽڲ���ȣ����˳���������Դ������
				}

				if ((compare_one + 1) == len)
				{
					// �ҵ������봦��
					//��ֵʱҪ����ʼֵ�������ͻ
					uintptr_t dwAddr = tmpAddr + i + nOffset;
					uintptr_t ullRet = 0;
					::ReadProcessMemory(process, (void*)dwAddr, &ullRet, dwReadLen, 0);
					//cout<<dwAddr<<endl;
					//�����dwAddr�Ѿ���Ӧ�����������ĵ�ַ
					//��ַ�����Ҳ��10����    ��Ҫת��Ϊ16���� 
					hanshu_dizhi = dwAddr;//��¼��ַ
					if (InstructionLen)
					{
						ullRet += dwAddr + dwReadLen;
					}

					return ullRet;
				}
			}
		}

		tmpAddr = tmpAddr + pageSize - len;//��һҳ����Ҫ��ǰһҳ��󳤶�len ��ʼ���ң�������ҳ�����м�������������������
	}

	return 0;
}
