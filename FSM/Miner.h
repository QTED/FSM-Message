#pragma once
#include "BaseGameEntity.h"
#include "Locations.h"

#include <cassert>
#include <string>


class State;

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
	//ָ��ǰ״̬��ָ��
	State* m_pCurrentState;

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

	//���º���
	void Update();

	//�ı䵱ǰ״̬���µ�״̬
	void ChangeState(State* pNewState);

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

