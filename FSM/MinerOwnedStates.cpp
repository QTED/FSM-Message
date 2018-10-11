#include "MinerOwnedStates.h"
#include "State.h"
#include "Miner.h"
#include "Locations.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;

//EnterMineAndDigForNugget
//
//
EnterMineAndDigForNugget * EnterMineAndDigForNugget::Instance()
{
	static EnterMineAndDigForNugget instance;
	return &instance;
}

void EnterMineAndDigForNugget::Enter(Miner * miner)
{
	//���󹤲��ڽ���ڣ��ı�󹤵ص������
	if (miner->Location() != goldmine) {
		cout << "\n" << GetNameOfEntity(miner->ID()) << ": " << "������";

		miner->ChangeLocation(goldmine);
	}
}

void EnterMineAndDigForNugget::Execute(Miner * miner)
{
	//���ڿ�ֱ�����ޣ�
	//�ڿʸı�״̬���
	miner->AddToGoldCarried(1);

	miner->IncreaseFatigue();

	cout << "\n" << GetNameOfEntity(miner->ID()) << ": " << "�ڳ�һ�����";

	//�����������������ޣ�ȥ�ѽ���������
	if (miner->PocketsFull()) {
		miner->ChangeState(VisitBankAndDepositNugget::Instance());
	}

	if (miner->Thirsty()) {
		miner->ChangeState(QuenchThirst::Instance());
	}
}

void EnterMineAndDigForNugget::Exit(Miner * miner)
{
	cout << "\n" << GetNameOfEntity(miner->ID()) << ": "<< "װ���˽�飬�뿪�˽��";
}



//VisitBankAndDepositNugget
//
//
VisitBankAndDepositNugget * VisitBankAndDepositNugget::Instance()
{
	static VisitBankAndDepositNugget instance;
	return &instance;
}

void VisitBankAndDepositNugget::Enter(Miner * miner)
{
	//���󹤵ص��Ϊbank
	if (miner->Location() != bank) {
		cout << "\n" << GetNameOfEntity(miner->ID()) << ": " << "ǰ�����У�";

		miner->ChangeLocation(bank);
	}
}

void VisitBankAndDepositNugget::Execute(Miner * miner)
{
	//�������ڽ���������
	miner->AddToWealth(miner->GoldCarried());

	miner->SetGoldCarried(0);

	cout << "\n" << GetNameOfEntity(miner->ID()) << ": "<< "����������. �ܴ���: " << miner->Wealth();

	//�ж��Ƿ��㹻����
	if (miner->Wealth() >= ComfortLevel) {
		cout << "\n" << GetNameOfEntity(miner->ID()) << ": "<< "�����㹻�����ˣ�. ���ڻؼҰɣ�";

		miner->ChangeState(GoHomeAndSleepTilRested::Instance());
	}
	//�������㣬�����ڿ�
	else {
		miner->ChangeState(EnterMineAndDigForNugget::Instance());
	}
}

void VisitBankAndDepositNugget::Exit(Miner * miner)
{
	cout << "\n" << GetNameOfEntity(miner->ID()) << ": " << "�뿪����";
}



//GoHomeAndSleepTilRested
//
//
GoHomeAndSleepTilRested * GoHomeAndSleepTilRested::Instance()
{
	static GoHomeAndSleepTilRested instance;
	return &instance;
}

void GoHomeAndSleepTilRested::Enter(Miner * miner)
{
	if (miner->Location() != shack)
	{
		cout << "\n" << GetNameOfEntity(miner->ID()) << ": " << "�ؼң�";

		miner->ChangeLocation(shack);
	}
}

void GoHomeAndSleepTilRested::Execute(Miner * miner)
{
	//����󹤲�ƣ�ͣ�����ȥ�ڿ�
	if (!miner->Fatigued())
	{
		cout << "\n" << GetNameOfEntity(miner->ID()) << ": "<< "��ʱ��ȥ�ڿ��ˣ�";

		miner->ChangeState(EnterMineAndDigForNugget::Instance());
	}
	else
	{
		//sleep
		miner->DecreaseFatigue();

		cout << "\n" << GetNameOfEntity(miner->ID()) << ": " << "ZZZZ... ";
	}
}

void GoHomeAndSleepTilRested::Exit(Miner * miner)
{
	cout << "\n" << GetNameOfEntity(miner->ID()) << ": " << "�뿪��";
}



//QuenchThirst
//
//
QuenchThirst * QuenchThirst::Instance()
{
	static QuenchThirst instance;
	return &instance;
}

void QuenchThirst::Enter(Miner * miner)
{
	if (miner->Location() != saloon)
	{
		miner->ChangeLocation(saloon);

		cout << "\n" << GetNameOfEntity(miner->ID()) << ": " << "ǰ���̵�";
	}
}

void QuenchThirst::Execute(Miner * miner)
{
	if (miner->Thirsty())
	{
		miner->BuyAndDrinkAWhiskey();

		cout << "\n" << GetNameOfEntity(miner->ID()) << ": " << "��ˮ��";

		miner->ChangeState(EnterMineAndDigForNugget::Instance());
	}

	else
	{
		cout << "\nERROR!\nERROR!\nERROR!";
	}
}

void QuenchThirst::Exit(Miner * miner)
{
	cout << "\n" << GetNameOfEntity(miner->ID()) << ": " << "�뿪�̵꣬�ڲ�����";
}
