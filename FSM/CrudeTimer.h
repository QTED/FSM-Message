#pragma once

#include <ratio>
#include <chrono>

using namespace std::chrono;

#define Clock CrudeTimer::Instance()

class CrudeTimer
{
private:


	//set to the time (in seconds) when class is instantiated
	steady_clock::time_point m_dStartTime;

	//set the start time
	//CrudeTimer() { m_dStartTime = system_clock::now() * 0.001; }
	CrudeTimer() { 
		m_dStartTime = steady_clock::now();
	}

	//copy ctor and assignment should be private
	CrudeTimer(const CrudeTimer&);
	CrudeTimer& operator=(const CrudeTimer&);

public:

	static CrudeTimer* Instance();

	//returns how much time has elapsed since the timer was started
	double GetCurrentTime() { 
		steady_clock::time_point t = steady_clock::now();
		duration<double> time_span = duration_cast<duration<double>>(t - m_dStartTime);
		return time_span.count(); 
	}

};
