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
	//若矿工不在金矿内，改变矿工地点进入金矿
	if (miner->Location() != goldmine) {
		cout << "\n" << GetNameOfEntity(miner->ID()) << ": " << "走入金矿";

		miner->ChangeLocation(goldmine);
	}
}

void EnterMineAndDigForNugget::Execute(Miner * miner)
{
	//矿工挖矿直到上限，
	//口渴改变状态解渴
	miner->AddToGoldCarried(1);

	miner->IncreaseFatigue();

	cout << "\n" << GetNameOfEntity(miner->ID()) << ": " << "挖出一个金块";

	//如果金块数量到达上限，去把金块存入银行
	if (miner->PocketsFull()) {
		miner->ChangeState(VisitBankAndDepositNugget::Instance());
	}

	if (miner->Thirsty()) {
		miner->ChangeState(QuenchThirst::Instance());
	}
}

void EnterMineAndDigForNugget::Exit(Miner * miner)
{
	cout << "\n" << GetNameOfEntity(miner->ID()) << ": "<< "装满了金块，离开了金矿";
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
	//将矿工地点改为bank
	if (miner->Location() != bank) {
		cout << "\n" << GetNameOfEntity(miner->ID()) << ": " << "前往银行！";

		miner->ChangeLocation(bank);
	}
}

void VisitBankAndDepositNugget::Execute(Miner * miner)
{
	//将背包内金块存入银行
	miner->AddToWealth(miner->GoldCarried());

	miner->SetGoldCarried(0);

	cout << "\n" << GetNameOfEntity(miner->ID()) << ": "<< "金块存入银行. 总存量: " << miner->Wealth();

	//判断是否足够满足
	if (miner->Wealth() >= ComfortLevel) {
		cout << "\n" << GetNameOfEntity(miner->ID()) << ": "<< "现在足够富有了！. 现在回家吧！";

		miner->ChangeState(GoHomeAndSleepTilRested::Instance());
	}
	//若不满足，重新挖矿
	else {
		miner->ChangeState(EnterMineAndDigForNugget::Instance());
	}
}

void VisitBankAndDepositNugget::Exit(Miner * miner)
{
	cout << "\n" << GetNameOfEntity(miner->ID()) << ": " << "离开银行";
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
		cout << "\n" << GetNameOfEntity(miner->ID()) << ": " << "回家！";

		miner->ChangeLocation(shack);
	}
}

void GoHomeAndSleepTilRested::Execute(Miner * miner)
{
	//如果矿工不疲劳，重新去挖矿
	if (!miner->Fatigued())
	{
		cout << "\n" << GetNameOfEntity(miner->ID()) << ": "<< "是时候去挖矿了！";

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
	cout << "\n" << GetNameOfEntity(miner->ID()) << ": " << "离开家";
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

		cout << "\n" << GetNameOfEntity(miner->ID()) << ": " << "前往商店";
	}
}

void QuenchThirst::Execute(Miner * miner)
{
	if (miner->Thirsty())
	{
		miner->BuyAndDrinkAWhiskey();

		cout << "\n" << GetNameOfEntity(miner->ID()) << ": " << "买水喝";

		miner->ChangeState(EnterMineAndDigForNugget::Instance());
	}

	else
	{
		cout << "\nERROR!\nERROR!\nERROR!";
	}
}

void QuenchThirst::Exit(Miner * miner)
{
	cout << "\n" << GetNameOfEntity(miner->ID()) << ": " << "离开商店，口不渴了";
}
