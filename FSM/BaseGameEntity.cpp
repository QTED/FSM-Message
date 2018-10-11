#include "BaseGameEntity.h"
#include <cassert>

int BaseGameEntity::m_iNextValidID = 0;

void BaseGameEntity::SetID(int val)
{
	assert((val >= m_iNextValidID) && "<BaseGameEntity::SetID>: ÎÞÐ§µÄ ID");

	m_ID = val;

	m_iNextValidID = m_ID + 1;
}

BaseGameEntity::BaseGameEntity(int id)
{
	SetID(id);
}


BaseGameEntity::~BaseGameEntity()
{
}

int BaseGameEntity::ID() const
{
	return m_ID;
}
