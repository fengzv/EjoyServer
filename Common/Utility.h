#pragma once
#include "Type_Common.h"
#include <vector>
#include <string>
#include <assert.h>

namespace Utility
{




	/*
	 *	@desc ��ȡָ��Ŀ¼�µ���ext_filterΪ��׺���ļ����ŵ�_vecFiles
	 *	@param dir ָ��Ŀ¼
	 *	@param [in/out] _vecFiles �ѵ����ļ����������
	 *	@param ext_filter �����ò���ָ���ĺ�׺�ļ�
	 *	@return �����ҵ����ļ�����
	 */
	int GetFilesWithExtInDir(const char* dir,std::vector<std::string>& _vecFiles,const char* ext_filter);


	/*
	 *	@desc ��������ת�����ַ���
	 *	@param pData ����������
	 *	@param nLength ���������ݳ���
	 *	@param pBuff ����ַ�������
	 *	@return �����ַ�������
	 */
	int Hex(void* pData,int nLength,char* pBuff);



	/*
	 * @desc ��16�����ַ���ת����2��������
	 * @param pBuff 16�����ַ���
	 * @param nLength 16�����ַ�������
	 * @param pData ���2�������ݻ���
	 * @return 2���Ƴ���
	 *	
	 */
	int UnHex(char* pBuff,int nLength,byte* pData);



	/*
	 *	@desc ת����16�����ַ�
	 *	@param _from ��ת��������
	 *	@return 
	 */
	inline char TranHex(byte _from)
	{
		switch (_from)
		{
		case 0:
			return '0';
		case 1:
			return '1';
		case 2:
			return '2';
		case 3:
			return '3';
		case 4:
			return '4';
		case 5:
			return '5';
		case 6:
			return '6';
		case 7:
			return '7';
		case 8:
			return '8';
		case 9:
			return '9';
		case 10:
			return 'A';
		case 11:
			return 'B';
		case 12:
			return 'C';
		case 13:
			return 'D';
		case 14:
			return 'E';
		case 15:
			return 'F';
		default:
			assert(false && "invalid num");
			return 0;
		}
	}
	
	/*
	 *	@desc ��16�����ַ�ת��������
	 */
	inline byte TranUnHex(char _from)
	{
		switch (_from)
		{
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		case 'A':
			return 10;
		case 'B':
			return 11;
		case 'C':
			return 12;
		case 'D':
			return 13;
		case 'E':
			return 14;
		case 'F':
			return 15;
		default:
			assert(false && "invalid char");
			return 0;
		}
	}

}

