#Timer Library
---

##Installation
The timer library is provided in static implementation. Inside the `timers` folder should be two folders:
  - `include` which contains all of the header files required
  - `src` which contains the static .lib files
After these have been copied into your project, you will need to add the location of the `.h` files to the `VC++ Directories -> Include Directories` setting in the project properties for "All Configurations".
Then you will need to add `timer.lib` to linker input for "Release" configuration and `timer_d.lib` to linker input for "Debug" configuration.
If the project contains no `.lib` files within the src folder, the project can be built under Debug/Release configuration to generate these.
***

##Getting Started
Timer can be used to create either a do-once event after a certain abount of time, or an event that will repeat at set intervals for either the duration of execution or until its `cancel()` operation is called.

Creating a timer is as simple as instantiating a timer object from anywhere in the code's execution `Timer timer;`
Timer currently has three (3) functions, with functionality and usage as described below:
  ```cpp
  timer.schedule(...)``` -> this function will schedule a do-once event (defined as a lambda function in the parameter) after the specified amount of time.
  ```cpp
  timer.scheduleAtFixedRate(...)``` -> this function will schedule a repeated event (defined as a lambda function in the parameter). The first delay parameter will set the delay until the function's initial call, the second delay parameter sets the time between function calls.
  ```cpp
  timer.cancel()``` -> this function will halt any activity on its thread
  
  <b>Example Usage</b>
  ```cpp
  #include <iostream>
  #include <Timer.h>
  int main(int argc, char** argv) {
    Timer timer;
    timer.schedule([](){ std::cout << "Show this after 3 seconds\n"; }, 3000);
    
    system("pause");
    return EXIT_SUCCESS;
  }```
