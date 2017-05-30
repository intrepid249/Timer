#include <Timer.h>

#include <thread>
#include <ctime>


#pragma region Timer
Timer::Timer() {
}

Timer::~Timer() {
}

void Timer::schedule(std::function<void()> callback, unsigned int delay) {
	// Create a separate thread to run execution on
	std::thread timerThread([=]() {
		// Halt the thread for the delay time
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		callback(); // Call the callback function when the thread wakes up
	});
	timerThread.detach();
}

void Timer::scheduleAtFixedRate(std::function<void()> callback, unsigned int initialDelay, unsigned int repeatDelay) {
	isRepeating = true; // Set the thread to repeat execution

	// Create a separate thread to run execution on
	std::thread timerThread([=]() {
		// Halt the thread for the delay time
		std::this_thread::sleep_for(std::chrono::milliseconds(initialDelay));
		callback(); // Call the callback function when the thread wakes up

		while (isRepeating) {
			/// Repeated cycles
			// Halt the thread for the delay time
			std::this_thread::sleep_for(std::chrono::milliseconds(repeatDelay));
			callback(); // Call the callback function when the thread wakes up
		}
	});

	// Tell the main thread to continue execution without waiting for this thread to finish
	timerThread.detach();
}

void Timer::cancel() {
	// Set the thread to disable repeat execution
	isRepeating = false;
}
#pragma endregion