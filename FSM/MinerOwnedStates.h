#pragma once
#include "State.h"

class Miner;

//״̬���󹤽������ڿ�
//�������㹻��飬�ı�״̬�� VisitBankAndDepositNugget
//���󹤿ڿʣ��ı�״̬�� QuenchThirst
class EnterMineAndDigForNugget :
	public State
{
private:
	EnterMineAndDigForNugget() = default;

	//˽�� ���ƹ��캯���븳ֵ�����
	EnterMineAndDigForNugget(const EnterMineAndDigForNugget&);
	EnterMineAndDigForNugget& operator=(const EnterMineAndDigForNugget&);

public:
	//Singleton
	static EnterMineAndDigForNugget* Instance();

	virtual void Enter(Miner* miner);
	virtual void Execute(Miner* miner);
	virtual void Exit(Miner* miner);
};


//״̬����ȥ���н����Ͻ���������
//�����㹻��Ǯ������ؼ� GoHomeAndSleepTilRested
//���򣬻ؽ������ڿ� EnterMineAndDigForNugget
class VisitBankAndDepositNugget :
	public State
{
private:
	VisitBankAndDepositNugget() = default;

	//˽�� ���ƹ��캯���븳ֵ�����
	VisitBankAndDepositNugget(const VisitBankAndDepositNugget&);
	VisitBankAndDepositNugget& operator=(const VisitBankAndDepositNugget&);

public:
	//Singleton
	static VisitBankAndDepositNugget* Instance();

	virtual void Enter(Miner* miner);
	virtual void Execute(Miner* miner);
	virtual void Exit(Miner* miner);
};


//״̬���󹤻ؼ�˯��
//
//
class GoHomeAndSleepTilRested :
	public State
{
private:
	GoHomeAndSleepTilRested() = default;

	//˽�� ���ƹ��캯���븳ֵ�����
	GoHomeAndSleepTilRested(const GoHomeAndSleepTilRested&);
	GoHomeAndSleepTilRested& operator=(const GoHomeAndSleepTilRested&);

public:
	//Singleton
	static GoHomeAndSleepTilRested* Instance();

	virtual void Enter(Miner* miner);
	virtual void Execute(Miner* miner);
	virtual void Exit(Miner* miner);
};


//״̬����ʣ��ظ��ڿʳ̶�
//
//
class QuenchThirst :
	public State
{
private:
	QuenchThirst() = default;

	//˽�� ���ƹ��캯���븳ֵ�����
	QuenchThirst(const QuenchThirst&);
	QuenchThirst& operator=(const QuenchThirst&);

public:
	//Singleton
	static QuenchThirst* Instance();

	virtual void Enter(Miner* miner);
	virtual void Execute(Miner* miner);
	virtual void Exit(Miner* miner);
};
