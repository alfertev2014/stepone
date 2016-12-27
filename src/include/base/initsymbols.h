#pragma once

#include <ob.h>

class BaseSymbolTable {
    BaseSymbolTable(){}
public:
    static Ptr createSymbolTable();
};
