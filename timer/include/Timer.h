#pragma once
#include <functional>

class Timer {
public:
	Timer();
	~Timer();

	void schedule(std::function<void()> callback, unsigned int delay);

	void scheduleAtFixedRate(std::function<void()> callback, unsigned int delay, unsigned int repeatDelay);
	void cancel();

private:
	bool isRepeating;
};