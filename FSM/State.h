#pragma once

class Miner;

class State
{
public:

	virtual ~State() {};

	//进入状态函数
	virtual void Enter(Miner*) = 0;

	//执行状态函数
	virtual void Execute(Miner*) = 0;

	//退出状态函数
	virtual void Exit(Miner*) = 0;
};

