#include "PacketDefine_Handler.h"

/*
* ��������Handler�����������
*
*/

//
HandlerMgrT sHandlerMgr;


// 
#define PACKET_HANDLER_PTR(_class)										\
	new Packet_Handler_Proxy(&_class##_Handler::OnHandle)

#define INSTANCE_PACKET_HANDLER(_class)				\
	do { sHandlerMgr.AddInstance(_class::ID,PACKET_HANDLER_PTR(_class));  } while(0)




template<>
InstanceMgr<Packet_Handler_Proxy>::InstanceMgr()
{
	Instance();
}

template<>
void InstanceMgr<Packet_Handler_Proxy>::Instance()
{
	INSTANCE_PACKET_HANDLER(LoginIn);
}