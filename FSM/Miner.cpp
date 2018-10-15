#include "Miner.h"
#include "MinerOwnedStates.h"



Miner::Miner(int ID):BaseGameEntity(ID),
					 m_Location(shack),
					 m_iGoldCarried(0),
					 m_iMoneyInBank(0),
					 m_iThirst(0),
					 m_iFatigue(0)
{
	m_pStateMachine = new StateMachine<Miner>(this);
	m_pStateMachine->SetCurrentState(GoHomeAndSleepTilRested::Instance());
}

Miner::~Miner()
{
	delete m_pStateMachine;
}



void Miner::Update()
{
	m_iThirst += 1;
	m_pStateMachine->Update();
}


StateMachine<Miner>* Miner::GetFSM() const
{
	return m_pStateMachine;
}

bool Miner::HandleMessage(const Telegram & msg)
{
	return m_pStateMachine->HandleMessage(msg);
}

location_type Miner::Location() const
{
	return m_Location;
}

void Miner::ChangeLocation(const location_type loc)
{
	m_Location = loc;
}

int Miner::GoldCarried() const
{
	return m_iGoldCarried;
}

void Miner::SetGoldCarried(const int val)
{
	m_iGoldCarried = val;
}

void Miner::AddToGoldCarried(const int val)
{
	m_iGoldCarried += val;
	if (m_iGoldCarried < 0)
		m_iGoldCarried = 0;
}

bool Miner::PocketsFull() const
{
	return m_iGoldCarried >= MaxNuggets;
}

bool Miner::Fatigued() const
{
	if (m_iFatigue >= TirednessThreshold)
		return true;
	return false;
}

void Miner::DecreaseFatigue()
{
	m_iFatigue -= 1;
}

void Miner::IncreaseFatigue()
{
	m_iFatigue += 1;
}

int Miner::Wealth() const
{
	return m_iMoneyInBank;
}

void Miner::SetWealth(const int val)
{
	m_iMoneyInBank = val;
}

void Miner::AddToWealth(const int val)
{
	m_iMoneyInBank += val;
	if (m_iMoneyInBank < 0)
		m_iMoneyInBank = 0;
}

bool Miner::Thirsty() const
{
	if (m_iThirst >= ThirstLevel)
		return true;
	return false;
}

void Miner::BuyAndDrinkAWhiskey()
{
	m_iThirst = 0; 
	m_iMoneyInBank -= 2;
}
