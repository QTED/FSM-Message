#include "EntityManager.h"
#include "BaseGameEntity.h"


EntityManager::EntityManager()
{
}

EntityManager * EntityManager::Instance()
{
	static EntityManager instance;
	return &instance;
}

void EntityManager::RegisterEntity(BaseGameEntity * NewEntity)
{
	m_EntityMap.insert(std::make_pair(NewEntity->ID(), NewEntity));
}

BaseGameEntity * EntityManager::GetEntityFromID(int id) const
{
	//由ID找到实体
	EntityMap::const_iterator ent = m_EntityMap.find(id);

	//确保实体存在
	assert((ent != m_EntityMap.end()) && "<EntityManager::GetEntityFromID>: 实体不存在");

	return ent->second;
}

void EntityManager::RemoveEntity(BaseGameEntity * pEntity)
{
	m_EntityMap.erase(m_EntityMap.find(pEntity->ID()));
}

