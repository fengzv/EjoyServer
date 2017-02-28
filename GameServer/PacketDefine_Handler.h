#pragma once
#include "PacketDefine.h"
#include "InstanceMgr.h"

#include "Connection.h"
#include "GamePlayer.h"

/*
* ��Ϣ��handler��ƣ�ͨ������ʽʵ�����Σ�����ǰ���handler�Ĳ�����һ����
* ���������ٷ�װһ�㣬������ǰ���handler������
*/



#define PACKET_HANDLER(_class)															\
class _class##_Handler																	\
{																						\
public:																					\
	static int OnHandle(ConnectionPtr conn_ptr,GamePlayerPtr gp_ptr,IPacket* packet);	\
}

typedef int (*packet_handler_ptr)(ConnectionPtr conn_ptr,GamePlayerPtr gp_ptr,IPacket* packet);

class Packet_Handler_Proxy
{
public:
	Packet_Handler_Proxy(packet_handler_ptr handler_func):
		m_func(handler_func)
	{}


	int operator()(ConnectionPtr conn_ptr,GamePlayerPtr gp_ptr,IPacket* packet)
	{
		return (*m_func)(conn_ptr,gp_ptr,packet);
	}

private:
	packet_handler_ptr m_func;
};

typedef InstanceMgr<Packet_Handler_Proxy> HandlerMgrT;
extern HandlerMgrT sHandlerMgr;

// Server Handler ����
PACKET_HANDLER(LoginIn);
