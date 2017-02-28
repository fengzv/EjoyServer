#pragma once
#include "Dll_Common.h"
#include "IField.h"



class DLL_EXPORT IRecordSet
{
protected:
	virtual ~IRecordSet() {};


public:

	/*
	 * @desc ��ȡ���������
	 * @return ����
	 *	
	 */
	virtual int GetRowCount()	=	0;


	/*
	 * @desc ��ȡ��һ��
	 * @return ����һ�У�����true������false
	 *	
	 */
	virtual	IField* NextRow()		= 0;


};





