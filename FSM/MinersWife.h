#pragma once
#include <string>

#include "State.h"
#include "BaseGameEntity.h"
#include "Locations.h"
#include "MinersWifeOwnedStates.h"
#include "Miner.h"
#include "StateMachine.h"

struct Telegram;

class MinersWife:
	public BaseGameEntity
{
private:
	StateMachine<MinersWife>* m_pStateMachine;

	location_type m_Location;

	//表示是否在做饭
	bool m_bCooking;

public:
	MinersWife(int id);
	~MinersWife();

	void Update();

	StateMachine<MinersWife>* GetFSM()const;
	virtual bool HandleMessage(const Telegram& msg);

	location_type Location()const;
	void ChangeLocation(location_type loc);

	bool Cooking();
	void SetCooking(bool val);
};

