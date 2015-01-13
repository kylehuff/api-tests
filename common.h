#include <sstream>
#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>

class apitest {
  public:
    std::string get_version();
    std::string echo(std::string);
};

// Methods that would normally be in the cpp file, however this example is
// is shared for both the JS-CTYPES library and the Native Messaging Host binary

// get_version method 
std::string apitest::get_version()
{
  std::string version = "{\"version\": \"v0.2.3\"}";
  return version;
}

// echo method
std::string apitest::echo(std::string msg)
{
  return msg;
}
