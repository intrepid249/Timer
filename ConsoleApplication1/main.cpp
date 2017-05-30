
#include <iostream>
#include <Timer.h>
#include <thread>
#include <ctime>

auto main(int argc, char** argv) -> int {
	Timer runOnce, repeater;

	runOnce.schedule([]() { std::cout << "Do me once\n"; }, 1000);

	repeater.scheduleAtFixedRate([]() { std::cout << "Do me until I get cancelled\n"; }, 1500, 323);
	
	repeater.schedule([&]() { std::cout << "STOP!\n"; repeater.cancel(); }, 3000);

	system("pause");
	return EXIT_SUCCESS;
}