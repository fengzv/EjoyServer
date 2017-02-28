#pragma once
#include "Dll_Common.h"
#include "IRecordSet.h"

class DLL_EXPORT IDataBase
{
public:
	virtual ~IDataBase() {};




	/*
	 * @desc ��ʼ�����ݿ�
	 * @param szIp ���ݿ�ip��ַ
	 * @param port ���ݿ�˿�
	 * @param szUser ���ݿ��û���
	 * @param szPass ���ݿ�����
	 * @param db �������ݿ���
	 * @return ���ӳɹ�����true,����ʧ�ܷ���false
	 *	
	 */
	virtual bool Initialize(const char* szIp,int port,const char* szUser,const char* szPass,const char* db) = 0;


	/*
	 * @desc ͬ����ѯ
	 * @param sql ��ѯsql���
	 * @return ���ؽ����
	 *	
	 */
	virtual IRecordSet* Query(const char* sql) = 0;


	/*
	 * @desc �޷��ؽ����sql��䣬
	 * @param sql sql���
	 * @return Ӱ����
	 * @mark �ýӿ�����ִ��sql��䣬�޽���������֣�update,insert,delete
	 */
	virtual int DirectQuery(const char* sql) = 0;



	/*
	 *	@desc �ر����ݿ�����
	 */
	virtual void Close() = 0;

};