#pragma once
#include "State.h"
#include <random>

using std::default_random_engine;
using std::uniform_int_distribution;

class MinersWife;
struct Telegram;

//妻子全局状态
//
//
class WifesGlobalState : 
	public State<MinersWife>
{
private:

	WifesGlobalState() = default;

	//复制构造与赋值函数私有但不定义
	WifesGlobalState(const WifesGlobalState&);
	WifesGlobalState& operator=(const WifesGlobalState&);

public:

	static WifesGlobalState* Instance();

	virtual void Enter(MinersWife* wife);

	virtual void Execute(MinersWife* wife);

	virtual void Exit(MinersWife* wife);

	virtual bool OnMessage(MinersWife* wife, const Telegram& msg);
};



//妻子状态：做家务
//
//
class DoHouseWork : public State<MinersWife>
{

private:

	DoHouseWork() = default;

	//复制构造与赋值函数私有但不定义
	DoHouseWork(const DoHouseWork&);
	DoHouseWork& operator=(const DoHouseWork&);

public:

	static DoHouseWork* Instance();

	virtual void Enter(MinersWife* wife);

	virtual void Execute(MinersWife* wife);

	virtual void Exit(MinersWife* wife);

	virtual bool OnMessage(MinersWife* wife, const Telegram& msg);

};



//妻子状态:去厕所
//
//
class VisitBathroom : public State<MinersWife>
{
private:

	VisitBathroom() = default;

	//复制构造与赋值函数私有但不定义
	VisitBathroom(const VisitBathroom&);
	VisitBathroom& operator=(const VisitBathroom&);

public:

	static VisitBathroom* Instance();

	virtual void Enter(MinersWife* wife);

	virtual void Execute(MinersWife* wife);

	virtual void Exit(MinersWife* wife);

	virtual bool OnMessage(MinersWife* wife, const Telegram& msg);
};



//妻子状态:做吃的
//
//
class CookStew : public State<MinersWife>
{
private:

	CookStew() = default;

	//复制构造与赋值函数私有但不定义
	CookStew(const CookStew&);
	CookStew& operator=(const CookStew&);

public:

	static CookStew* Instance();

	virtual void Enter(MinersWife* wife);

	virtual void Execute(MinersWife* wife);

	virtual void Exit(MinersWife* wife);

	virtual bool OnMessage(MinersWife* wife, const Telegram& msg);
};

