#include "PacketDefine.h"

#define DEFAULT_IMPL_PACKET(class) \
	int class::OnHandle() { return 0;}

// ������ʵ�ֵ�handle,����Ĭ�ϵĿ�ʵ��
DEFAULT_IMPL_PACKET(LoginIn);








// ����ʵ�ֵ�handle
int LoginRes::OnHandle()
{

	printf("login in success, o yeah");

	return 0;
}

