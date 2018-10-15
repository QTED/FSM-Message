#pragma once
#include <set>
#include "Telegram.h"

class BaseGameEntity;

const double SEND_MESSAGE_IMMEDIATELY = 0.0f;
const int NO_ADDITIONAL_INFO = 0;

#define Dispatch MessageDispatcher::Instance()

class MessageDispatcher
{
private:
	//�Զ����������ӳ���Ϣ�������ظ�
	std::set<Telegram> PriorityQ;

	void Discharge(BaseGameEntity* pReceiver, const Telegram& msg);

	//����
	MessageDispatcher();
	MessageDispatcher(const MessageDispatcher&);
	MessageDispatcher& operator=(const MessageDispatcher&);

public:
	static MessageDispatcher* Instance();

	//���ͼ�ʱ��Ϣ
	void DispatchMessage(double delay, int sender, int receiver, int msg, void* ExtraInfo);

	//�����ӳ���Ϣ
	void DispatchDelyedMessage();
};

