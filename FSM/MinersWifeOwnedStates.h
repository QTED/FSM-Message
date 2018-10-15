#pragma once
#include "State.h"
#include <random>

using std::default_random_engine;
using std::uniform_int_distribution;

class MinersWife;
struct Telegram;

//����ȫ��״̬
//
//
class WifesGlobalState : 
	public State<MinersWife>
{
private:

	WifesGlobalState() = default;

	//���ƹ����븳ֵ����˽�е�������
	WifesGlobalState(const WifesGlobalState&);
	WifesGlobalState& operator=(const WifesGlobalState&);

public:

	static WifesGlobalState* Instance();

	virtual void Enter(MinersWife* wife);

	virtual void Execute(MinersWife* wife);

	virtual void Exit(MinersWife* wife);

	virtual bool OnMessage(MinersWife* wife, const Telegram& msg);
};



//����״̬��������
//
//
class DoHouseWork : public State<MinersWife>
{

private:

	DoHouseWork() = default;

	//���ƹ����븳ֵ����˽�е�������
	DoHouseWork(const DoHouseWork&);
	DoHouseWork& operator=(const DoHouseWork&);

public:

	static DoHouseWork* Instance();

	virtual void Enter(MinersWife* wife);

	virtual void Execute(MinersWife* wife);

	virtual void Exit(MinersWife* wife);

	virtual bool OnMessage(MinersWife* wife, const Telegram& msg);

};



//����״̬:ȥ����
//
//
class VisitBathroom : public State<MinersWife>
{
private:

	VisitBathroom() = default;

	//���ƹ����븳ֵ����˽�е�������
	VisitBathroom(const VisitBathroom&);
	VisitBathroom& operator=(const VisitBathroom&);

public:

	static VisitBathroom* Instance();

	virtual void Enter(MinersWife* wife);

	virtual void Execute(MinersWife* wife);

	virtual void Exit(MinersWife* wife);

	virtual bool OnMessage(MinersWife* wife, const Telegram& msg);
};



//����״̬:���Ե�
//
//
class CookStew : public State<MinersWife>
{
private:

	CookStew() = default;

	//���ƹ����븳ֵ����˽�е�������
	CookStew(const CookStew&);
	CookStew& operator=(const CookStew&);

public:

	static CookStew* Instance();

	virtual void Enter(MinersWife* wife);

	virtual void Execute(MinersWife* wife);

	virtual void Exit(MinersWife* wife);

	virtual bool OnMessage(MinersWife* wife, const Telegram& msg);
};

