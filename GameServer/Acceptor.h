#pragma once

#include "boost/asio.hpp"
#include "Connection.h"
#include <string>

class Acceptor
{
public:
	Acceptor(boost::asio::io_service& _ios);
	~Acceptor(void);

	/*
	 * @desc ��ʼ��
	 * @param addr ������ַ
	 * @param nPort �����Ķ˿�
	 * @return 
	 *	
	 */
	bool Init(std::string& addr, std::string& nPort );
	
	
	//
	void StartAccept();

	// 
	void handle_accept(const boost::system::error_code& e);


private:
	boost::asio::ip::tcp::acceptor m_acceptor;

	ConnectionPtr m_new_connection_ptr;
};

