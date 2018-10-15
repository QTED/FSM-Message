#include "MinersWife.h"



MinersWife::MinersWife(int ID): BaseGameEntity(ID),
								m_Location(shack),
								m_bCooking(false)
{
	m_pStateMachine = new StateMachine<MinersWife>(this);
	
	m_pStateMachine->SetCurrentState(DoHouseWork::Instance());

	m_pStateMachine->SetGlobalState(WifesGlobalState::Instance());
}

MinersWife::~MinersWife()
{
	delete m_pStateMachine;
}

void MinersWife::Update()
{
	m_pStateMachine->Update();
}

StateMachine<MinersWife>* MinersWife::GetFSM() const
{
	return m_pStateMachine;
}

bool MinersWife::HandleMessage(const Telegram & msg)
{
	return m_pStateMachine->HandleMessage(msg);
}

location_type MinersWife::Location() const
{
	return m_Location;
}

void MinersWife::ChangeLocation(location_type loc)
{
	m_Location = loc;
}

bool MinersWife::Cooking()
{
	return m_bCooking;
}

void MinersWife::SetCooking(bool val)
{
	m_bCooking = val;
}
