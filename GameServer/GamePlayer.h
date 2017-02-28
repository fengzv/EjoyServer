#pragma once

#include "Game_Define.h"
#include "boost/asio.hpp"
#include "boost/array.hpp"





// ���ʵ����
class GamePlayer
{
public:
	GamePlayer(/*boost::asio::io_service& ios,*/int _id,int _conn_id);
	~GamePlayer(void);



	//
	int GetID()	{ return m_ID;}


	// �뿪��Ϸ
	int OnExit();

private:

	// Connection ID
	int m_ConnID;
	
	// �Լ�ID
	int m_ID;
};


typedef boost::shared_ptr<GamePlayer> GamePlayerPtr;
