#pragma once

#include <core.h>

class BaseEvaluator {
    BaseEvaluator(){}
public:
    static Ob::Ptr createContext();
};
