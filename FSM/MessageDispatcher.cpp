#include "MessageDispatcher.h"
#include "BaseGameEntity.h"
#include "EntityManager.h"
#include "Locations.h"
#include "MessageTypes.h"
#include "EntityNames.h"
#include "CrudeTimer.h"

#include <iostream>
using std::cout;

using std::set;


MessageDispatcher::MessageDispatcher()
{
}

void MessageDispatcher::Discharge(BaseGameEntity * pReceiver, const Telegram & msg)
{
	if (!pReceiver->HandleMessage(msg))
	{
		cout << "\n" << "消息未被处理";
	}
}


MessageDispatcher * MessageDispatcher::Instance()
{
	static MessageDispatcher instance;
	return &instance;
}

void MessageDispatcher::DispatchMessage(double delay, int sender, int receiver, int msg, void * ExtraInfo)
{
	//指向发送者与接收者的指针
	BaseGameEntity* pSender = EntityMgr->GetEntityFromID(sender);
	BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(receiver);

	//确保接收者存在
	if (pReceiver == nullptr)
	{
		cout << "\n" <<"没有找到接收者！ :" << receiver;
		return;
	}

	//创建消息
	Telegram telegram(0, sender, receiver, msg, ExtraInfo);

	//如果没延迟，立即发送消息
	if (delay <= 0.0f)
	{
		cout << "\n" << Clock->GetCurrentTime() << " :发送消息, " << GetNameOfEntity(pSender->ID()) << " 给 " << GetNameOfEntity(pReceiver->ID()) << "， 内容：" << MsgToStr(msg);

		//发送消息
		Discharge(pReceiver, telegram);
	}
	else
	{
		double CurrentTime = Clock->GetCurrentTime();

		telegram.DispatchTime = CurrentTime + delay;

		//将消息加入消息队列
		PriorityQ.insert(telegram);
		cout << "\n" << "消息延迟发送， " << Clock->GetCurrentTime() << "， 由 " << GetNameOfEntity(pSender->ID()) << " 给 " << GetNameOfEntity(pReceiver->ID()) << "， 内容：" << MsgToStr(msg);
	}
}

void MessageDispatcher::DispatchDelyedMessage()
{
	double CurrentTime = Clock->GetCurrentTime();

	while (!PriorityQ.empty() && 
		(PriorityQ.begin()->DispatchTime < CurrentTime) &&
		(PriorityQ.begin()->DispatchTime > 0))
	{
		//从队列中读取第一条消息
		const Telegram& telegram = *PriorityQ.begin();

		//找到接收者
		BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(telegram.Receiver);

		cout << "\n" <<"消息队列准备好，发送给：" << GetNameOfEntity(pReceiver->ID()) << ", 内容：" << MsgToStr(telegram.Msg);

		//发送消息
		Discharge(pReceiver, telegram);

		//将此消息从队列中移除
		PriorityQ.erase(PriorityQ.begin());
	}
}

