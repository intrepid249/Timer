#pragma once
#include <functional>



class Timer {
	class TimerTask {
	public:
		TimerTask();
		~TimerTask();

		void operator ()(std::function<void()> callback, unsigned int delay);
	};

	class RepeatingTimerTask {
	public:
		RepeatingTimerTask();
		~RepeatingTimerTask();

		void operator ()(std::function<void()> callback, unsigned int delay, unsigned int repeatDelay);
		void cancel();

	private:
		bool isRepeating;
	};

public:
	Timer();
	~Timer();

	void schedule(std::function<void()> callback, unsigned int delay);

//private: // these are only private until they get fixed
	void scheduleAtFixedRate(std::function<void()> callback, unsigned int delay, unsigned int repeatDelay);
	void cancel();
	//===========================================

private:
	RepeatingTimerTask *repeaterTask;
};