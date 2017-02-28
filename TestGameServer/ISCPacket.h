#pragma once

class PacketIStream;
class PacketOStream;

class ISCPacket
{
public:
	ISCPacket(void);
	virtual ~ISCPacket(void) = 0;


	enum { ID = 0 };

	// ��ȡ��ID
	virtual int GetID() const = 0;

	// �����л�
	virtual bool UnSerialize(PacketIStream& packet) = 0;

	// ���л�
	virtual bool Serialize(PacketOStream& packet) = 0;

	// ������
	virtual int OnHandle() = 0;


};

