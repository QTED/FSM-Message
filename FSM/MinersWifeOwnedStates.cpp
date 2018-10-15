#include "MinersWifeOwnedStates.h"
#include "MinerOwnedStates.h"
#include "MinersWife.h"
#include "Locations.h"
#include "CrudeTimer.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;

default_random_engine e;
uniform_int_distribution<unsigned> u(0, 9);
uniform_int_distribution<unsigned> p(0, 2);

//
//
//
WifesGlobalState * WifesGlobalState::Instance()
{
	static WifesGlobalState instance;
	return &instance;
}

void WifesGlobalState::Enter(MinersWife * wife)
{
}

void WifesGlobalState::Execute(MinersWife * wife)
{
	if (u(e) == 0) {
		wife->GetFSM()->ChangeState(VisitBathroom::Instance());
	}
}

void WifesGlobalState::Exit(MinersWife * wife)
{
}

bool WifesGlobalState::OnMessage(MinersWife * wife, const Telegram & msg)
{
	switch (msg.Msg)
	{
	case Msg_HiHoneyImHome:
		cout << "\n��Ϣ��  " << GetNameOfEntity(wife->ID()) << "  ��  " << Clock->GetCurrentTime() << "  ����";

		cout << "\n" << GetNameOfEntity(wife->ID()) << ": ���Ҹ�����Щ�Եģ�";

		wife->GetFSM()->ChangeState(CookStew::Instance());
	default:
		break;
	}
	return false;
}



//
//
//
DoHouseWork * DoHouseWork::Instance()
{
	static DoHouseWork instance;
	return &instance;
}

void DoHouseWork::Enter(MinersWife * wife)
{
}

void DoHouseWork::Execute(MinersWife * wife)
{
	switch (p(e))
	{
	case 0:

		cout << "\n" << GetNameOfEntity(wife->ID()) << ": ����";

		break;

	case 1:

		cout << "\n" << GetNameOfEntity(wife->ID()) << ": ϴ����";

		break;

	case 2:

		cout << "\n" << GetNameOfEntity(wife->ID()) << ": ����";

		break;
	}
}

void DoHouseWork::Exit(MinersWife * wife)
{
}

bool DoHouseWork::OnMessage(MinersWife * wife, const Telegram & msg)
{
	return false;
}



//
//
//
VisitBathroom * VisitBathroom::Instance()
{
	static VisitBathroom instance;
	return &instance;
}

void VisitBathroom::Enter(MinersWife * wife)
{
	cout << "\n" << GetNameOfEntity(wife->ID()) << ": ȥ������";
}

void VisitBathroom::Execute(MinersWife * wife)
{
	cout << "\n" << GetNameOfEntity(wife->ID()) << ": ������!";

	wife->GetFSM()->RevertToPreviousState();
}

void VisitBathroom::Exit(MinersWife * wife)
{
	cout << "\n" << GetNameOfEntity(wife->ID()) << ": �Ӳ�������";
}

bool VisitBathroom::OnMessage(MinersWife * wife, const Telegram & msg)
{
	return false;
}

CookStew * CookStew::Instance()
{
	static CookStew instance;
	return &instance;
}

void CookStew::Enter(MinersWife * wife)
{
	if (!wife->Cooking())
	{
		cout << "\n" << GetNameOfEntity(wife->ID()) << ": ��ʼ���⣡";

		//���Լ�����һ���ӳ���Ϣ�������Լ�ʲôʱ�������ÿ���
		Dispatch->DispatchMessage(0.01, wife->ID(), wife->ID(), Msg_StewReady, NO_ADDITIONAL_INFO);

		wife->SetCooking(true);
	}
}

void CookStew::Execute(MinersWife * wife)
{
	cout << "\n" << GetNameOfEntity(wife->ID()) << ": Fussin' over food";
}

void CookStew::Exit(MinersWife * wife)
{
	cout << "\n" << GetNameOfEntity(wife->ID()) << ": Puttin' the stew on the table";
}

bool CookStew::OnMessage(MinersWife * wife, const Telegram & msg)
{
	switch (msg.Msg)
	{
	case Msg_StewReady: {

		cout << "\n" << GetNameOfEntity(wife->ID()) << "�� :" << Clock->GetCurrentTime() << "�յ���Ϣ";

		cout << "\n" << GetNameOfEntity(wife->ID()) << ": �������ˣ� �����ǿ��԰�!";

		//����Ϣ֪ͨ��
		Dispatch->DispatchMessage(SEND_MESSAGE_IMMEDIATELY, wife->ID(), ent_Miner_Bob, Msg_StewReady, NO_ADDITIONAL_INFO);

		wife->SetCooking(false);

		wife->GetFSM()->ChangeState(DoHouseWork::Instance());

		return true;
	}

	}
	return false;
}
