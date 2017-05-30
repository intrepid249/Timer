#include <Timer.h>

#include <thread>
#include <ctime>
#include <csignal>

#include <iostream>


#pragma region Timer
Timer::Timer() {
}

Timer::~Timer() {
}

void Timer::schedule(std::function<void()> callback, unsigned int delay) {
	std::thread timerThread([=]() {
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		callback();
	});
	timerThread.detach();
}

void Timer::scheduleAtFixedRate(std::function<void()> callback, unsigned int delay, unsigned int repeatDelay) {
	isRepeating = true;
	std::thread timerThread([=]() {
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		callback();

		while (isRepeating) {
			std::this_thread::sleep_for(std::chrono::milliseconds(repeatDelay));
			callback();
		}

		std::cout << "I've stopped\n";
	});
	timerThread.detach();
}

void Timer::cancel() {
	isRepeating = false;

	//if (repeaterTask != nullptr)
	//	repeaterTask->cancel();
}
#pragma endregion