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

	//单例模式，隐藏构造，复制，赋值
	EntityManager();
	EntityManager(const EntityManager&);
	EntityManager& operator=(const EntityManager&);
public:

	static EntityManager* Instance();

	//注册实体
	void RegisterEntity(BaseGameEntity* NewEntity);

	//由传入ID得到实体指针
	BaseGameEntity* GetEntityFromID(int id)const;

	//从map中移除实体
	void RemoveEntity(BaseGameEntity* pEntity);

};

