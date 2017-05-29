
#include <iostream>
#include <Timer.h>

auto main(int argc, char** argv) -> int {
	Timer runOnce, repeater;

	//runOnce.schedule([]() { std::cout << "Do me once\n"; }, 1000); // Works

	repeater.scheduleAtFixedRate([]() { std::cout << "Do me until I get cancelled\n"; }, 1500, 300); // works but doesn't get cancelled
	
	repeater.cancel(); // ????

	system("pause");
	return EXIT_SUCCESS;
}