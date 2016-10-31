#pragma once

#include <core.h>

class BaseEvaluator {
    BaseEvaluator(){}
public:
    static Ptr createContext();
};
