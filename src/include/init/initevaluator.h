#pragma once

#include <ptr.h>

class BaseEvaluator {
    BaseEvaluator(){}
public:
    static Ptr createContext();
};
