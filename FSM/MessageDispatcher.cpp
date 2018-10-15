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
		cout << "\n" << "��Ϣδ������";
	}
}


MessageDispatcher * MessageDispatcher::Instance()
{
	static MessageDispatcher instance;
	return &instance;
}

void MessageDispatcher::DispatchMessage(double delay, int sender, int receiver, int msg, void * ExtraInfo)
{
	//ָ������������ߵ�ָ��
	BaseGameEntity* pSender = EntityMgr->GetEntityFromID(sender);
	BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(receiver);

	//ȷ�������ߴ���
	if (pReceiver == nullptr)
	{
		cout << "\n" <<"û���ҵ������ߣ� :" << receiver;
		return;
	}

	//������Ϣ
	Telegram telegram(0, sender, receiver, msg, ExtraInfo);

	//���û�ӳ٣�����������Ϣ
	if (delay <= 0.0f)
	{
		cout << "\n" << Clock->GetCurrentTime() << " :������Ϣ, " << GetNameOfEntity(pSender->ID()) << " �� " << GetNameOfEntity(pReceiver->ID()) << "�� ���ݣ�" << MsgToStr(msg);

		//������Ϣ
		Discharge(pReceiver, telegram);
	}
	else
	{
		double CurrentTime = Clock->GetCurrentTime();

		telegram.DispatchTime = CurrentTime + delay;

		//����Ϣ������Ϣ����
		PriorityQ.insert(telegram);
		cout << "\n" << "��Ϣ�ӳٷ��ͣ� " << Clock->GetCurrentTime() << "�� �� " << GetNameOfEntity(pSender->ID()) << " �� " << GetNameOfEntity(pReceiver->ID()) << "�� ���ݣ�" << MsgToStr(msg);
	}
}

void MessageDispatcher::DispatchDelyedMessage()
{
	double CurrentTime = Clock->GetCurrentTime();

	while (!PriorityQ.empty() && 
		(PriorityQ.begin()->DispatchTime < CurrentTime) &&
		(PriorityQ.begin()->DispatchTime > 0))
	{
		//�Ӷ����ж�ȡ��һ����Ϣ
		const Telegram& telegram = *PriorityQ.begin();

		//�ҵ�������
		BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(telegram.Receiver);

		cout << "\n" <<"��Ϣ����׼���ã����͸���" << GetNameOfEntity(pReceiver->ID()) << ", ���ݣ�" << MsgToStr(telegram.Msg);

		//������Ϣ
		Discharge(pReceiver, telegram);

		//������Ϣ�Ӷ������Ƴ�
		PriorityQ.erase(PriorityQ.begin());
	}
}

