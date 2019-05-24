#pragma once

#include <impl/ptr_impl.h>

namespace stepone::base {

using namespace core;

namespace {

template <typename T>
class Type {
public:
    using type = T;
};

template <typename T>
class TypeMapping : TypeMapping<std::remove_cv_t<std::remove_reference_t<T>>> {
    
};

template <>
class TypeMapping<int> : Type<Value<int>> {
};

template <>
class TypeMapping<float> : Type<Value<float>> {
};

template <>
class TypeMapping<char> : Type<Value<char>> {
};

template <>
class TypeMapping<long long> : Type<Value<long long>> {
};

template <typename T>
inline Ptr convertToOb(T &&value) {
    return Ob::of<TypeMapping<T>::type>(std::forward<T>(value));
}

inline Ptr convertToOb(Ptr &&value) {
    return std::forward<Ptr>(value);
}


class TypeConvertionWrapper {
    const Ptr &ptr;
public:
    TypeConvertionWrapper(const Ptr &ptr) : ptr(ptr) {}
    
    template <typename T>
    operator T() {
        return ptr.cast<Value<T>>().getValue();
    }
    
    operator const Ptr&() {
        return ptr;
    }
    
};


template <typename Arg, typename ...Args>
class FunctionImpl {
public:
    template <typename Func, typename ...AllArgs>
    static Ptr apply(Func func, const Ptr &p, const Ptr &a, AllArgs && ...args) {
        return FunctionImpl<Args...>::apply(func, p.cdr(), a,
            std::forward<AllArgs>(args)..., p.car().eval(a));
    }
};

template <typename Arg>
class FunctionImpl<Arg> {
public:
    template <typename Func, typename ...AllArgs>
    static Ptr apply(Func func, const Ptr &p, const Ptr &a, AllArgs && ...args) {
        return convertToOb(func(
            TypeConvertionWrapper(std::forward<AllArgs>(args))...,
            TypeConvertionWrapper(p.car().eval(a))
        ));
    }
};

}


template <typename Func>
class Function;

template <typename Ret, typename ...Args>
class Function<Ret (*)(Args...)> {
    using Func = Ret (*)(Args...);
    Func func;    
public:
    Function(Func func) : func(func) {}
    Ptr operator()(const Ptr &p, const Ptr &a) {
        return FunctionImpl<Args...>::apply(func, p, a);
    }
};

template <class Func>
Function(Func) -> Function<Func>;


} // namespaces
