#pragma once
#include "BaseGameEntity.h"
#include "Locations.h"
#include "MinerOwnedStates.h"
#include "StateMachine.h"

#include <cassert>
#include <string>

struct Telegram;

//�󹤸е��������С���
const int ComfortLevel = 5;
//�����Я�������
const int MaxNuggets = 3;
//�󹤿ڿ�ֵ
const int ThirstLevel = 5;
//��ƣ��ֵ
const int TirednessThreshold = 5;

class Miner :
	public BaseGameEntity
{
private:

	//StateMachine
	StateMachine<Miner>* m_pStateMachine;

	//�󹤵�ǰ����λ��
	location_type m_Location;

	//�󹤱����н������
	int m_iGoldCarried;

	//�����вƸ�
	int m_iMoneyInBank;

	//�󹤿ڿʳ̶�
	int m_iThirst;

	//��ƣ�ͳ̶�
	int m_iFatigue;
public:
	Miner(int ID);
	~Miner();
	//���º���
	void Update();

	//��ȡStatMachine
	StateMachine<Miner>* GetFSM()const;

	//������Ϣ
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

