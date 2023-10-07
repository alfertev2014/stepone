#include <objects/basenumfunc_obs.h>

#include <operations/value_operations.h>
#include <operations/typepredicates_ops.h>
#include <base/operations.h>

#include <functional>
#include <type_traits>

namespace stepone::objects {

using namespace base;
using namespace operations;

template <typename T>
BaseNumOps<T>::BaseNumOps() :
    aNeg(Ptr::of<Symbol>()),
    aPlus(Ptr::of<Symbol>()),
    aMinus(Ptr::of<Symbol>()),
    aProduct(Ptr::of<Symbol>()),
    aDivision(Ptr::of<Symbol>()),
    aMod(Ptr::of<Symbol>()),
    aIs(Ptr::of<Symbol>()),

    aAnd(Ptr::of<Symbol>()),
    aOr(Ptr::of<Symbol>()),
    aXor(Ptr::of<Symbol>()),
    aNot(Ptr::of<Symbol>()),

    aShl(Ptr::of<Symbol>()),
    aShr(Ptr::of<Symbol>()),

    aEql(Ptr::of<Symbol>()),
    aNE(Ptr::of<Symbol>()),
    aGT(Ptr::of<Symbol>()),
    aLT(Ptr::of<Symbol>()),
    aGE(Ptr::of<Symbol>()),
    aLE(Ptr::of<Symbol>()),

    aSz(Ptr::of<Symbol>())
{}

namespace {
// constexpr lambdas

template <typename T>
struct Shl { auto operator()(const T &lhs, const T &rhs) const { return lhs << rhs;}};

template <typename T>
struct Shr { auto operator()(const T &lhs, const T &rhs) const { return lhs >> rhs;}};

}

template <typename T>
Ptr BaseNumOps<T>::populateContext(const Ptr &a) const
{
    Ptr ctx = Context::make(aNeg, Ptr::of<BaseMacro>(Function<std::negate<T>>()), a);
    ctx = Context::make(aPlus, Ptr::of<BaseMacro>(Function<std::plus<T>>()), ctx);
    ctx = Context::make(aMinus, Ptr::of<BaseMacro>(Function<std::minus<T>>()), ctx);
    ctx = Context::make(aProduct, Ptr::of<BaseMacro>(Function<std::multiplies<T>>()), ctx);
    ctx = Context::make(aDivision, Ptr::of<BaseMacro>(Function<std::divides<T>>()), ctx);

    ctx = Context::make(aIs, Ptr::of<BaseMacro>(Function<TypePUnOp<Value<T>>>()), ctx);

    if constexpr (std::is_integral_v<T>) {
        ctx = Context::make(aMod, Ptr::of<BaseMacro>(Function<std::modulus<T>>()), ctx);

        ctx = Context::make(aAnd, Ptr::of<BaseMacro>(Function<std::bit_and<T>>()), ctx);
        ctx = Context::make(aOr, Ptr::of<BaseMacro>(Function<std::bit_or<T>>()), ctx);
        ctx = Context::make(aXor, Ptr::of<BaseMacro>(Function<std::bit_xor<T>>()), ctx);
        ctx = Context::make(aNot, Ptr::of<BaseMacro>(Function<std::bit_not<T>>()), ctx);

        ctx = Context::make(aShl, Ptr::of<BaseMacro>(Function<Shl<T>>()), ctx);
        ctx = Context::make(aShr, Ptr::of<BaseMacro>(Function<Shr<T>>()), ctx);
    }

    ctx = Context::make(aEql, Ptr::of<BaseMacro>(Function<std::equal_to<T>>()), ctx);
    ctx = Context::make(aNE, Ptr::of<BaseMacro>(Function<std::not_equal_to<T>>()), ctx);
    ctx = Context::make(aGT, Ptr::of<BaseMacro>(Function<std::greater<T>>()), ctx);
    ctx = Context::make(aLT, Ptr::of<BaseMacro>(Function<std::less<T>>()), ctx);
    ctx = Context::make(aGE, Ptr::of<BaseMacro>(Function<std::greater_equal<T>>()), ctx);
    ctx = Context::make(aLE, Ptr::of<BaseMacro>(Function<std::less_equal<T>>()), ctx);

    ctx = Context::make(aSz, Ptr::of<types::Value<long>>(sizeof(T)), ctx);

    return ctx;
}

BaseNumFunc::BaseNumFunc() :
    longOps(),
    floatOps(),
    charOps(),

    along2int(Ptr::of<Symbol>()),
    aint2long(Ptr::of<Symbol>()),

    afloat2int(Ptr::of<Symbol>()),
    aint2float(Ptr::of<Symbol>()),

    achar2int(Ptr::of<Symbol>()),
    aint2char(Ptr::of<Symbol>()),

    achar2long(Ptr::of<Symbol>()),
    along2char(Ptr::of<Symbol>())
{}

Ptr BaseNumFunc::populateContext(const Ptr &a) const
{
    Ptr ctx = longOps.populateContext(ctx);
    ctx = floatOps.populateContext(ctx);
    ctx = charOps.populateContext(ctx);

    ctx = Context::make(afloat2int, Ptr::of<BaseMacro>(Function<ValueCastUnOp<double, long>>()), ctx);
    ctx = Context::make(aint2float, Ptr::of<BaseMacro>(Function<ValueCastUnOp<long, double>>()), ctx);

    ctx = Context::make(achar2int, Ptr::of<BaseMacro>(Function<ValueCastUnOp<char, long>>()), ctx);
    ctx = Context::make(aint2char, Ptr::of<BaseMacro>(Function<ValueCastUnOp<long, char>>()), ctx);

    ctx = Context::make(achar2long, Ptr::of<BaseMacro>(Function<ValueCastUnOp<char, long>>()), ctx);
    ctx = Context::make(along2char, Ptr::of<BaseMacro>(Function<ValueCastUnOp<long, char>>()), ctx);

    return ctx;
}

const BaseNumFunc &BaseNumFunc::inst()
{
    static const BaseNumFunc instance;
    return instance;
}

} // namespaces
