

#include <iostream>
#include <Timer.h>

auto main(int argc, char** argv) -> int {
	Timer runOnce, repeater;

	runOnce.schedule([]() { std::cout << "Do me once\n"; }, 1000);
	repeater.scheduleAtFixedRate([]() { std::cout << "Do me until I get cancelled\n"; }, 1500, 300);
	
	runOnce.schedule([&repeater]() { 
		std::cout << "This time I'll cancel the repeater!\n";
		repeater.cancel();
	}, 3000);

	system("pause");
	return EXIT_SUCCESS;
}