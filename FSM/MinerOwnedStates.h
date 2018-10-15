#pragma once
#include "State.h"

class Miner;
struct Telegram;

//状态：矿工进入金矿挖矿
//若矿工有足够金块，改变状态至 VisitBankAndDepositNugget
//若矿工口渴，改变状态至 QuenchThirst
class EnterMineAndDigForNugget :
	public State<Miner>
{
private:
	EnterMineAndDigForNugget() = default;

	//私有 复制构造函数与赋值运算符
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


//状态：矿工去银行将身上金块存入银行
//若矿工足够有钱，他会回家 GoHomeAndSleepTilRested
//否则，回金矿继续挖矿 EnterMineAndDigForNugget
class VisitBankAndDepositNugget :
	public State<Miner>
{
private:
	VisitBankAndDepositNugget() = default;

	//私有 复制构造函数与赋值运算符
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


//状态：矿工回家睡觉
//
//
class GoHomeAndSleepTilRested :
	public State<Miner>
{
private:
	GoHomeAndSleepTilRested() = default;

	//私有 复制构造函数与赋值运算符
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


//状态：解渴，回复口渴程度
//
//
class QuenchThirst :
	public State<Miner>
{
private:
	QuenchThirst() = default;

	//私有 复制构造函数与赋值运算符
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


//状态：吃
//
//
class EatStew :
	public State<Miner>
{
private:
	EatStew() = default;

	//私有 复制构造函数与赋值运算符
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