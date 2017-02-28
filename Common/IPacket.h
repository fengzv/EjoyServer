#pragma once
#include <vector>
#include "Type_Common.h"


/*
* Packet�����ԭ��
* �������Ϳͻ���ͳһIPacket�ӿڣ����Ǵ���ӿڲ�ͬ����Ϊ�������Ϳͻ�����Ҫ�Ĳ�����ͬ
*
* Packet�����л��������л���msgID�������ô�������Ϊ�˶Գƣ��������ͳһ����
*
* ǰ��˰����干��һ�������ļ��������л��뷴���л��Ϲ��ã��ڴ����ϲ�һ������ǰ��˷ֿ�����
* ͨ��ǰ����е�PacketDefine_Handler.cpp���塣
*/



class PacketIStream;
class PacketOStream;


class IPacket
{
public:
	IPacket(void);
	virtual ~IPacket(void) = 0;

	enum { ID = 0 };

	// ��ȡ��ID
	virtual int GetID() const = 0;

	// �����л�
	virtual bool UnSerialize(PacketIStream& packet) = 0;
	
	// ���л�
	virtual bool Serialize(PacketOStream& packet) = 0;

	// ������
//#ifdef _SERVER_
//	virtual int OnHandle(ConnectionPtr conn_ptr,GamePlayerPtr gp_ptr) = 0;
//#elif _CLIENT_
//	virtual int OnHandle() = 0;
//#endif


private:
	std::vector<byte> m_buff;
};

