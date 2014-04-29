#ifndef DBG_H
#define DBG_H

#include <string>
#include <sstream>
#include <iostream>

#define DBG(x) (cout << (x) << " at file: " << __FILE__ << " line: " << __LINE__ << endl)

#define SDBG(x) dynamic_cast<std::stringstream *> (&(std::stringstream(x) << " at file: " << __FILE__ << " line: " << __LINE__))->str()

#endif // DBG_H
