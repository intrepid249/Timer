#include <Timer.h>

#include <thread>
#include <ctime>

#include <iostream>


#pragma region TimerTask
Timer::TimerTask::TimerTask() : isRepeating(false) {
}

Timer::TimerTask::~TimerTask() {
}

void Timer::TimerTask::operator()(std::function<void()> callback, unsigned int delay) {
	std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	callback();
}

void Timer::TimerTask::operator()(std::function<void()> callback, unsigned int delay, unsigned int repeatDelay) {
	std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	callback();
	while (isRepeating) {
		std::this_thread::sleep_for(std::chrono::milliseconds(repeatDelay));
		callback();
	}
	if (!isRepeating)
		std::cout << "Stop please\n";
}
void Timer::TimerTask::setRepeating(bool flag) {
	isRepeating = flag;
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
	/// This function has been removed, as it needs functionality of a pipe-control system in order to be terminated
	/// using signals

	//repeaterTask = new TimerTask;
	//repeaterTask->setRepeating(true);
	//std::thread timerThread(*repeaterTask, callback, delay, repeatDelay);
	//timerThread.detach();
}

void Timer::cancel() {
	//if (repeaterTask != nullptr)
	//	repeaterTask->setRepeating(false);
}
#pragma endregion