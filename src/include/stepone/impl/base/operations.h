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
class TypeMapping<int> : public Type<Value<int>> {
};

template <>
class TypeMapping<float> : public Type<Value<float>> {
};

template <>
class TypeMapping<char> : public Type<Value<char>> {
};

template <>
class TypeMapping<long long> : public Type<Value<long long>> {
};

template <typename T>
inline Ptr convertToOb(T &&value) {
    return Ob::of<typename TypeMapping<T>::type>(std::forward<T>(value));
}

template <>
inline Ptr convertToOb<Ptr>(Ptr &&value) {
    return std::forward<Ptr>(value);
}

template <>
inline Ptr convertToOb<bool>(bool &&value) {
    return value ? Ptr::at() : Ptr::anil();
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

template <typename FuncPtr>
class FunctionPtrImpl;

template <typename Ret, typename ...Args>
class FunctionPtrImpl<Ret (*)(Args...)> {
    using Func = Ret (*)(Args...);
public:
    static Ptr apply(Func func, const Ptr &p, const Ptr &a) {
        return FunctionImpl<Args...>::apply(func, p, a);
    }
};

template <typename Func>
class FunctionFunctorImpl;

template <typename Func, typename Ret, typename ...Args>
class FunctionFunctorImpl<Ret (Func::*)(Args...) const> {
public:
    static Ptr apply(const Ptr &p, const Ptr &a) {
        return FunctionImpl<Args...>::apply(Func(), p, a);
    }
};

}


template <typename Func>
class Function {
public:
    Ptr operator()(const Ptr &p, const Ptr &a) const {
        return FunctionFunctorImpl<decltype(&Func::operator())>::apply(p, a);
    }
};


template <typename Func, Func func>
class FunctionPtr {
public:
    Ptr operator()(const Ptr &p, const Ptr &a) const {
        return FunctionPtrImpl<Func>::apply(func, p, a);
    }
};


} // namespaces
