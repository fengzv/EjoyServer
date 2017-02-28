#pragma once
#include "GameStruct/GS_Player.h"
#include "../DataCache/DataCache.h"




class Player
{
public:

	Player(int _id);
	~Player();

	int Load(dc_ptr _cache);



	
	// �ӻ�������
	int _LoadFromDC(dc_ptr _cache);



	/*
	 * @desc �����汻miss�󣬴����ݿ�����������
	 * @param _cache ����ʵ��
	 * @return ���ؽ��״̬
	 * @mark �ú����ɳ��򴥷�����Ҫ�������á������������ִ��ʱ���ڵ��߳�
	 *	Ҳ�ͱ�������������ǲ���һ���̵߳ġ�
	 */
	int _LoadFromDB(dc_ptr _cache);



private:
	int m_nID;
	tPlayerData m_Data;
};
