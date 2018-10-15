#pragma once

#include <string>
#include "Telegram.h"

class BaseGameEntity
{
private:
	//ʵ��Ψһʶ��ID
	int m_ID;

	//��һ����ЧID�� ÿ�δ����¶���ʱ����
	static int m_iNextValidID;

	//���캯���е��ô˺���ȷ��ID����ȷ����
	//������ID������ǰ��ȷ��ֵ���ڵ�����һ����ЧID
	void SetID(int val);
public:
	BaseGameEntity(int id);
	virtual ~BaseGameEntity();

	//��Ϸѭ�����ø��º���
	virtual void Update() = 0;
	//��Ϣ������
	virtual bool HandleMessage(const Telegram& msg) = 0;

	int ID() const;
};

