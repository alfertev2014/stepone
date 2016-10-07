#pragma once

#include <string>
#include <sstream>
#include <iostream>

#define DBG(x) (std::cout << (x) << " at file: " << __FILE__ << " line: " << __LINE__ << std::endl)

#define SDBG(x) dynamic_cast<std::stringstream *> (&(std::stringstream(x) << " at file: " << __FILE__ << " line: " << __LINE__))->str()
