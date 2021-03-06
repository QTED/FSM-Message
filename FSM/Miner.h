#pragma once
#include "BaseGameEntity.h"
#include "Locations.h"
#include "MinerOwnedStates.h"
#include "StateMachine.h"

#include <cassert>
#include <string>

struct Telegram;

//矿工感到满足的最小金额
const int ComfortLevel = 5;
//矿工最大携带金块量
const int MaxNuggets = 3;
//矿工口渴值
const int ThirstLevel = 5;
//矿工疲劳值
const int TirednessThreshold = 5;

class Miner :
	public BaseGameEntity
{
private:

	//StateMachine
	StateMachine<Miner>* m_pStateMachine;

	//矿工当前所处位置
	location_type m_Location;

	//矿工背包中金块数量
	int m_iGoldCarried;

	//矿工银行财富
	int m_iMoneyInBank;

	//矿工口渴程度
	int m_iThirst;

	//矿工疲劳程度
	int m_iFatigue;
public:
	Miner(int ID);
	~Miner();
	//更新函数
	void Update();

	//获取StatMachine
	StateMachine<Miner>* GetFSM()const;

	//处理消息
	virtual bool HandleMessage(const Telegram& msg);

	location_type Location() const;
	void ChangeLocation(const location_type loc);

	int GoldCarried() const;
	void SetGoldCarried(const int val);
	void AddToGoldCarried(const int val);
	bool PocketsFull() const;

	bool Fatigued()const;
	void DecreaseFatigue();
	void IncreaseFatigue();

	int Wealth()const;
	void SetWealth(const int val);
	void AddToWealth(const int val);

	bool Thirsty()const;
	void BuyAndDrinkAWhiskey();
};

