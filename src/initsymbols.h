#pragma once

#include "basesymbols.h"
#include "bytearray.h"

class BaseSymbolTable {
    BaseSymbolTable(){}
public:
    static Ob::Ptr createSymbolTable();
};
