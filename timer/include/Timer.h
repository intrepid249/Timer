#pragma once
#include <functional>

class Timer {
	class TimerTask {
	public:
		TimerTask();
		~TimerTask();

		void operator ()(std::function<void()> callback, unsigned int delay);
		void operator ()(std::function<void()> callback, unsigned int delay, unsigned int repeatDelay);

		void setRepeating(bool flag);

	private:
		bool isRepeating;
	};

public:
	Timer();
	~Timer();

	void schedule(std::function<void()> callback, unsigned int delay);
	void scheduleAtFixedRate(std::function<void()> callback, unsigned int delay, unsigned int repeatDelay);
	void cancel();

private:
	TimerTask *repeaterTask;
};