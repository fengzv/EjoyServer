#pragma once
#include "Type_Common.h"
#include "boost/asio.hpp"
#include "boost/enable_shared_from_this.hpp"

/*
* �������ԭ��
* �ֲ��ֿ⣿����Ӧ�÷֣���Ϊȫ�ֿ��Լ���ҿ�
* key����������Zone_x:Server_x:TableName:PlayerID
* ����value����ƣ�hset�Ǹ������ѡ������ĸ��
*
*/




struct redisContext;

class CDataCacheImpl : public boost::enable_shared_from_this<CDataCacheImpl>
{
public:
	CDataCacheImpl(boost::asio::io_service& _ios);

	enum
	{
		DCI_E_NONE = -3,
		DCI_E_ERR = -2,
		DCI_E_BUSY = -1,
		DCI_E_SUCC = 0,
	};


	/*
	 * @desc ��ʼ�����ݻ���
	 * @param dc_ip ���ݻ��������IP
	 * @param port ���ݻ���������˿�
	 * @return �ɹ����
	 *	
	 */
	bool Initialize(const char* dc_ip,int port = 6379);



	/*
	 *	@desc ��ȡkey��value
	 *	@param key ��ȡ��key
	 *	@param data ����������
	 *	@param nlen �������
	 *	@return ��������״ֵ̬
	 */
	int CDataCacheImpl::Get( const char* key, char* data,int& nlen);



	/*
	 * @desc ��ȡ�����ص�
	 * @param _key ��ȡ���ݶ�Ӧ��key
	 * @return 
	 *	
	 */
	template<typename T,typename F>
	void PostLoad(T* ptr,F func)
	{
		if (!ptr)
		{
			return;
		}

		m_ios.post(boost::bind(func,ptr,shared_from_this()));
	}


	/*
	 *	@desc ����key��value
	 *	@param key ���õ�key
	 *	@param data value�������
	 *	@return ��������״ֵ̬
	 */
	int CDataCacheImpl::Set(const char* key,const char* data);


private:
	boost::asio::io_service& m_ios;
	redisContext* m_redis_ct;
};

typedef boost::shared_ptr<CDataCacheImpl> dc_ptr;