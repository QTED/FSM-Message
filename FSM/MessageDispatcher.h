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
	//自动整理排序延迟消息，避免重复
	std::set<Telegram> PriorityQ;

	void Discharge(BaseGameEntity* pReceiver, const Telegram& msg);

	//单例
	MessageDispatcher();
	MessageDispatcher(const MessageDispatcher&);
	MessageDispatcher& operator=(const MessageDispatcher&);

public:
	static MessageDispatcher* Instance();

	//发送即时消息
	void DispatchMessage(double delay, int sender, int receiver, int msg, void* ExtraInfo);

	//发送延迟消息
	void DispatchDelyedMessage();
};

