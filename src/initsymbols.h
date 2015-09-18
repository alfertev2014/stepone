#pragma once

#include "core.h"

class BaseSymbolTable {
    BaseSymbolTable(){}
public:
    static Ob::Ptr createSymbolTable();
};
