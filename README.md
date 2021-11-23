# Time data type

This repo provides C++ data type for calculating with clock times. You can add/subtract minutes to your clock.
I write this repo to handle with tram arrival times and adding delays/earliness to that.

Tested with **C++17**.

### Add to your project:
Simply add `add_subdirectory(<path/to/Time/folder>)` to your CMakeLists.txt and linking that by adding `Time` to `target_link_libraries` of your project.

### Examples:

```cpp
#include "Time.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    Time time1("11:30");
    constexpr auto DelayTimeInMinutes = 8;

    std::cout << time1 + DelayTimeInMinutes << std::endl;

    Time time2("13:15");
    std::cout << Time::getDifferenceInMinutes(time1, time2) //
              << " minutes between "                        //
              << time1 << " and " << time2 << std::endl;
    
    return 0;
}
```
