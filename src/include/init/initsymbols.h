#pragma once

#include <ptr.h>

class BaseSymbolTable {
    BaseSymbolTable(){}
public:
    static Ptr createSymbolTable();
};
