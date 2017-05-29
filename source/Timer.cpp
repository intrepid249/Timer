#include <Timer.h>

#include <thread>
#include <ctime>
#include <csignal>

#include <iostream>


#pragma region TimerTask
Timer::TimerTask::TimerTask() {
}

Timer::TimerTask::~TimerTask() {
}

void Timer::TimerTask::operator()(std::function<void()> callback, unsigned int delay) {
	std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	callback();
}
#pragma endregion

//============================================================================================================

#pragma region Timer
Timer::Timer() {
}

Timer::~Timer() {
	if (repeaterTask != nullptr)
		delete repeaterTask;
}

void Timer::schedule(std::function<void()> callback, unsigned int delay) {
	TimerTask task;
	std::thread timerThread(task, callback, delay);
	timerThread.detach();
}

void Timer::scheduleAtFixedRate(std::function<void()> callback, unsigned int delay, unsigned int repeatDelay) {
	repeaterTask = new RepeatingTimerTask;
	std::thread timerThread(*repeaterTask, callback, delay, repeatDelay);
	timerThread.detach();
}

void Timer::cancel() {
	if (repeaterTask != nullptr)
		delete repeaterTask;
		//repeaterTask->cancel();
}
#pragma endregion


#pragma region Repeating Timer
Timer::RepeatingTimerTask::RepeatingTimerTask() : isRepeating(true) {}

Timer::RepeatingTimerTask::~RepeatingTimerTask() {}

void Timer::RepeatingTimerTask::operator()(std::function<void()> callback, unsigned int delay, unsigned int repeatDelay) {
	std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	callback();
	while (isRepeating) {
		std::this_thread::sleep_for(std::chrono::milliseconds(repeatDelay));
		callback();
	}
	if (!isRepeating)
		std::cout << "Stop please\n";
}

void Timer::RepeatingTimerTask::cancel() {
	isRepeating = false;
}
#pragma endregion
