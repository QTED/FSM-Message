#pragma once
#include <cassert>
#include <string>

#include "State.h"
#include "Telegram.h"

template <class entity_type>
class StateMachine
{
private:
	//指向拥有这个实例的指针
	entity_type* m_pOwner;
	//当前状态
	State<entity_type>* m_pCurrentState;
	//上一个状态
	State<entity_type>* m_pPreviousState;
	//全局状态
	State<entity_type>* m_pGlobalState;
public:
	StateMachine(entity_type* owmer): m_pOwner(owmer),
									  m_pCurrentState(nullptr),
									  m_pGlobalState(nullptr),
									  m_pPreviousState(nullptr)
	{}

	//初始化FSM
	void SetCurrentState(State<entity_type>* s) { m_pCurrentState = s; }
	void SetGlobalState(State<entity_type>* s) { m_pGlobalState = s; }
	void SetPreviousState(State<entity_type>* s) { m_pPreviousState = s; }

	//更新函数
	void Update()const {
		//执行全局状态
		if (m_pGlobalState)
			m_pGlobalState->Execute(m_pOwner);
		//执行当前状态
		if (m_pCurrentState)
			m_pCurrentState->Execute(m_pOwner);
	}

	//接收消息
	bool HandleMessage(const Telegram& msg) const {
		//检查当前状态与是否可以接收消息
		if (m_pCurrentState && m_pCurrentState->OnMessage(m_pOwner, msg))
		{
			return true;
		}
		//若不能，将消息发送给全局状态
		if (m_pGlobalState && m_pGlobalState->OnMessage(m_pOwner, msg))
		{
			return true;
		}
		return false;
	}

	//改变到新状态
	void ChangeState(State<entity_type>* pNewState) {
		assert(pNewState && "<StateMachine::ChangeState>:试图改变到一个空状态！");

		//记录前一个状态
		m_pPreviousState = m_pCurrentState;

		//推出当前状态
		m_pCurrentState->Exit(m_pOwner);

		//进入新的状态
		m_pCurrentState = pNewState;
		m_pCurrentState->Enter(m_pOwner);
	}

	//回到上一个状态
	void RevertToPreviousState() {
		ChangeState(m_pPreviousState);
	}

	//获取状态
	State<entity_type>* CurrentState()const {
		return m_pCurrentState;
	}
	State<entity_type>* GlobalState()const {
		return m_pCurrentState;
	}
	State<entity_type>* Previous()const {
		return m_pPreviousState;
	}

	//
	bool isInState(const State<entity_type>& st)const {
		if (typeid(*m_pCurrentState) == typeid(st))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
