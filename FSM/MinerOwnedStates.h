#pragma once
#include "State.h"

class Miner;
struct Telegram;

//״̬���󹤽������ڿ�
//�������㹻��飬�ı�״̬�� VisitBankAndDepositNugget
//���󹤿ڿʣ��ı�״̬�� QuenchThirst
class EnterMineAndDigForNugget :
	public State<Miner>
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
	virtual bool OnMessage(Miner* miner, const Telegram& msg);
};


//״̬����ȥ���н����Ͻ���������
//�����㹻��Ǯ������ؼ� GoHomeAndSleepTilRested
//���򣬻ؽ������ڿ� EnterMineAndDigForNugget
class VisitBankAndDepositNugget :
	public State<Miner>
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
	virtual bool OnMessage(Miner* miner, const Telegram& msg);
};


//״̬���󹤻ؼ�˯��
//
//
class GoHomeAndSleepTilRested :
	public State<Miner>
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
	virtual bool OnMessage(Miner* miner, const Telegram& msg);
};


//״̬����ʣ��ظ��ڿʳ̶�
//
//
class QuenchThirst :
	public State<Miner>
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
	virtual bool OnMessage(Miner* miner, const Telegram& msg);
};


//״̬����
//
//
class EatStew :
	public State<Miner>
{
private:
	EatStew() = default;

	//˽�� ���ƹ��캯���븳ֵ�����
	EatStew(const EatStew&);
	EatStew& operator=(const EatStew&);

public:
	//Singleton
	static EatStew* Instance();

	virtual void Enter(Miner* miner);
	virtual void Execute(Miner* miner);
	virtual void Exit(Miner* miner);
	virtual bool OnMessage(Miner* miner, const Telegram& msg);
};