#pragma once

#include <impl/ptr_impl.h>

namespace stepone::base {

using namespace core;

template <typename Func>
class FunctionImpl;

template <typename Ret, typename Arg, typename ...Args>
class FunctionImpl<Ret (*)(Arg, Args...)> {
public:
    template <typename Func, typename ...AllArgs>
    static Ptr apply(Func func, const Ptr &p, const Ptr &a, AllArgs && ...args) {
        return FunctionImpl<Ret (*)(Args...)>::apply(func, p.cdr(), a,
            std::forward<AllArgs>(args)..., p.car().eval(a));
    }
};

template <typename Ret>
class FunctionImpl<Ret (*)()> {
public:
    template <typename Func, typename ...AllArgs>
    static Ptr apply(Func func, const Ptr &p, const Ptr &a, AllArgs && ...args) {
        return func(std::forward<AllArgs>(args)...);
    }
};



template <class Func>
class Function {
    Func func;
public:
    Function(Func func) : func(func) {}
    
    Ptr operator()(const Ptr &p, const Ptr &a) {
        return FunctionImpl<Func>::apply(func, p, a);
    }
};

} // namespaces
