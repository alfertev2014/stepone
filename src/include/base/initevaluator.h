#pragma once

#include <ob.h>

class BaseEvaluator {
    BaseEvaluator(){}
public:
    static Ptr createContext();
};
