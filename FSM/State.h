#pragma once

#include "Telegram.h"

class Miner;

template<class entity_type>
class State
{
public:

	virtual ~State() {};

	//进入状态函数
	virtual void Enter(entity_type*) = 0;

	//执行状态函数
	virtual void Execute(entity_type*) = 0;

	//退出状态函数
	virtual void Exit(entity_type*) = 0;

	//接收消息函数
	virtual bool OnMessage(entity_type*, const Telegram&) = 0;
};

