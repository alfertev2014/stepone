#pragma once

#include <ptr.h>

namespace stepone::init {

class BaseSymbolTable {
    BaseSymbolTable(){}
public:
    static Ptr createSymbolTable();
};

} // namespaces
