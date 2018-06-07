#pragma once

#include <ptr.h>

namespace stepone { namespace init {

class BaseEvaluator {
    BaseEvaluator(){}
public:
    static Ptr createContext();
};

}} // namespaces
