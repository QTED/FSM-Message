#pragma once
#include <cassert>
#include <string>

#include "State.h"
#include "Telegram.h"

template <class entity_type>
class StateMachine
{
private:
	//ָ��ӵ�����ʵ����ָ��
	entity_type* m_pOwner;
	//��ǰ״̬
	State<entity_type>* m_pCurrentState;
	//��һ��״̬
	State<entity_type>* m_pPreviousState;
	//ȫ��״̬
	State<entity_type>* m_pGlobalState;
public:
	StateMachine(entity_type* owmer): m_pOwner(owmer),
									  m_pCurrentState(nullptr),
									  m_pGlobalState(nullptr),
									  m_pPreviousState(nullptr)
	{}

	//��ʼ��FSM
	void SetCurrentState(State<entity_type>* s) { m_pCurrentState = s; }
	void SetGlobalState(State<entity_type>* s) { m_pGlobalState = s; }
	void SetPreviousState(State<entity_type>* s) { m_pPreviousState = s; }

	//���º���
	void Update()const {
		//ִ��ȫ��״̬
		if (m_pGlobalState)
			m_pGlobalState->Execute(m_pOwner);
		//ִ�е�ǰ״̬
		if (m_pCurrentState)
			m_pCurrentState->Execute(m_pOwner);
	}

	//������Ϣ
	bool HandleMessage(const Telegram& msg) const {
		//��鵱ǰ״̬���Ƿ���Խ�����Ϣ
		if (m_pCurrentState && m_pCurrentState->OnMessage(m_pOwner, msg))
		{
			return true;
		}
		//�����ܣ�����Ϣ���͸�ȫ��״̬
		if (m_pGlobalState && m_pGlobalState->OnMessage(m_pOwner, msg))
		{
			return true;
		}
		return false;
	}

	//�ı䵽��״̬
	void ChangeState(State<entity_type>* pNewState) {
		assert(pNewState && "<StateMachine::ChangeState>:��ͼ�ı䵽һ����״̬��");

		//��¼ǰһ��״̬
		m_pPreviousState = m_pCurrentState;

		//�Ƴ���ǰ״̬
		m_pCurrentState->Exit(m_pOwner);

		//�����µ�״̬
		m_pCurrentState = pNewState;
		m_pCurrentState->Enter(m_pOwner);
	}

	//�ص���һ��״̬
	void RevertToPreviousState() {
		ChangeState(m_pPreviousState);
	}

	//��ȡ״̬
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
