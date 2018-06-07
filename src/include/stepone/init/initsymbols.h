#pragma once

#include <ptr.h>

namespace stepone { namespace init {

class BaseSymbolTable {
    BaseSymbolTable(){}
public:
    static Ptr createSymbolTable();
};

}} // namespaces
