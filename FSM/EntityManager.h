#pragma once
#include <map>
#include <string>
#include <cassert>

class BaseGameEntity;

#define EntityMgr EntityManager::Instance()


class EntityManager
{
private:
	typedef std::map<int, BaseGameEntity*> EntityMap;
	
	EntityMap m_EntityMap;

	//����ģʽ�����ع��죬���ƣ���ֵ
	EntityManager();
	EntityManager(const EntityManager&);
	EntityManager& operator=(const EntityManager&);
public:

	static EntityManager* Instance();

	//ע��ʵ��
	void RegisterEntity(BaseGameEntity* NewEntity);

	//�ɴ���ID�õ�ʵ��ָ��
	BaseGameEntity* GetEntityFromID(int id)const;

	//��map���Ƴ�ʵ��
	void RemoveEntity(BaseGameEntity* pEntity);

};

