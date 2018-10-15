#pragma once
#include <iostream>
#include <math.h>

struct Telegram
{
	//发送者
	int Sender;

	//接收者
	int Receiver;

	//信息本身
	//MessageTypes.h
	int Msg;

	//消息延迟时间
	double DispatchTime;

	//备注，附加消息
	void* ExtraInfo;

	Telegram(): Sender(-1),
				Receiver(-1),
				Msg(-1),
				DispatchTime(-1)
	{}

	Telegram(double time, int sender, int receiver, int msg, void* info = nullptr):Sender(sender),
		Receiver(receiver),
		Msg(msg),
		DispatchTime(time),
		ExtraInfo(info)
	{}
};

const double SmallestDelay = 0.25;

inline bool operator==(const Telegram& t1, const Telegram& t2) {
	return (fabs(t1.DispatchTime - t2.DispatchTime) < SmallestDelay) &&
		(t1.Sender == t2.Sender) &&
		(t1.Receiver == t2.Receiver) &&
		(t1.Msg == t2.Msg);
}

inline bool operator<(const Telegram& t1, const Telegram& t2) {
	if (t1 == t2)
	{
		return false;
	}
	else
	{
		return (t1.DispatchTime < t2.DispatchTime);
	}
}

inline std::ostream& operator<<(std::ostream& os, const Telegram& t) {

	os << "time: " << t.DispatchTime << "  Sender:  " << t.Sender << "  Receiver:  " << t.Receiver << "  Msg:  " << t.Msg;

	return os;
}

template <class T>
inline T DereferenceToType(void* p) {

	return *(T*)(p);
}
