#pragma once

#include <ptr.h>

namespace stepone::init {

class BaseEvaluator {
    BaseEvaluator(){}
public:
    static Ptr createContext();
};

} // namespaces
