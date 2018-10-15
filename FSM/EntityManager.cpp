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
	//��ID�ҵ�ʵ��
	EntityMap::const_iterator ent = m_EntityMap.find(id);

	//ȷ��ʵ�����
	assert((ent != m_EntityMap.end()) && "<EntityManager::GetEntityFromID>: ʵ�岻����");

	return ent->second;
}

void EntityManager::RemoveEntity(BaseGameEntity * pEntity)
{
	m_EntityMap.erase(m_EntityMap.find(pEntity->ID()));
}

