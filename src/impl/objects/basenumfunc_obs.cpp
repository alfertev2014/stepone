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
    aNeg(Ob::of<Symbol>()),
    aPlus(Ob::of<Symbol>()),
    aMinus(Ob::of<Symbol>()),
    aProduct(Ob::of<Symbol>()),
    aDivision(Ob::of<Symbol>()),
    aMod(Ob::of<Symbol>()),
    aIs(Ob::of<Symbol>()),

    aAnd(Ob::of<Symbol>()),
    aOr(Ob::of<Symbol>()),
    aXor(Ob::of<Symbol>()),
    aNot(Ob::of<Symbol>()),

    aShl(Ob::of<Symbol>()),
    aShr(Ob::of<Symbol>()),

    aEql(Ob::of<Symbol>()),
    aNE(Ob::of<Symbol>()),
    aGT(Ob::of<Symbol>()),
    aLT(Ob::of<Symbol>()),
    aGE(Ob::of<Symbol>()),
    aLE(Ob::of<Symbol>()),

    aSz(Ob::of<Symbol>())
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
    Ptr ctx = Context::make(aNeg, Ob::of<BaseMacro>(Function<std::negate<T>>()), a);
    ctx = Context::make(aPlus, Ob::of<BaseMacro>(Function<std::plus<T>>()), ctx);
    ctx = Context::make(aMinus, Ob::of<BaseMacro>(Function<std::minus<T>>()), ctx);
    ctx = Context::make(aProduct, Ob::of<BaseMacro>(Function<std::multiplies<T>>()), ctx);
    ctx = Context::make(aDivision, Ob::of<BaseMacro>(Function<std::divides<T>>()), ctx);
    
    ctx = Context::make(aIs, Ob::of<BaseMacro>(Function<TypePUnOp<Value<T>>>()), ctx);

    if constexpr (std::is_integral_v<T>) {
        ctx = Context::make(aMod, Ob::of<BaseMacro>(Function<std::modulus<T>>()), ctx);
        
        ctx = Context::make(aAnd, Ob::of<BaseMacro>(Function<std::bit_and<T>>()), ctx);
        ctx = Context::make(aOr, Ob::of<BaseMacro>(Function<std::bit_or<T>>()), ctx);
        ctx = Context::make(aXor, Ob::of<BaseMacro>(Function<std::bit_xor<T>>()), ctx);
        ctx = Context::make(aNot, Ob::of<BaseMacro>(Function<std::bit_not<T>>()), ctx);

        ctx = Context::make(aShl, Ob::of<BaseMacro>(Function<Shl<T>>()), ctx);
        ctx = Context::make(aShr, Ob::of<BaseMacro>(Function<Shr<T>>()), ctx);
    }

    ctx = Context::make(aEql, Ob::of<BaseMacro>(Function<std::equal_to<T>>()), ctx);
    ctx = Context::make(aNE, Ob::of<BaseMacro>(Function<std::not_equal_to<T>>()), ctx);
    ctx = Context::make(aGT, Ob::of<BaseMacro>(Function<std::greater<T>>()), ctx);
    ctx = Context::make(aLT, Ob::of<BaseMacro>(Function<std::less<T>>()), ctx);
    ctx = Context::make(aGE, Ob::of<BaseMacro>(Function<std::greater_equal<T>>()), ctx);
    ctx = Context::make(aLE, Ob::of<BaseMacro>(Function<std::less_equal<T>>()), ctx);
    
    ctx = Context::make(aSz, core::Ob::of<core::Value<int>>(sizeof(T)), ctx);

    return ctx;
}

BaseNumFunc::BaseNumFunc() :
    intOps(),
    longOps(),
    floatOps(),
    charOps(),

    along2int(Ob::of<Symbol>()),
    aint2long(Ob::of<Symbol>()),

    afloat2int(Ob::of<Symbol>()),
    aint2float(Ob::of<Symbol>()),

    achar2int(Ob::of<Symbol>()),
    aint2char(Ob::of<Symbol>()),

    achar2long(Ob::of<Symbol>()),
    along2char(Ob::of<Symbol>())
{}

Ptr BaseNumFunc::populateContext(const Ptr &a) const
{
    Ptr ctx = intOps.populateContext(a);
    ctx = longOps.populateContext(ctx);
    ctx = floatOps.populateContext(ctx);
    ctx = charOps.populateContext(ctx);

    ctx = Context::make(aint2long, Ob::of<BaseMacro>(Function<ValueCastUnOp<int, long long>>()), ctx);
    ctx = Context::make(along2int, Ob::of<BaseMacro>(Function<ValueCastUnOp<long long, int>>()), ctx);

    ctx = Context::make(afloat2int, Ob::of<BaseMacro>(Function<ValueCastUnOp<float, int>>()), ctx);
    ctx = Context::make(aint2float, Ob::of<BaseMacro>(Function<ValueCastUnOp<int, float>>()), ctx);

    ctx = Context::make(achar2int, Ob::of<BaseMacro>(Function<ValueCastUnOp<char, long long>>()), ctx);
    ctx = Context::make(aint2char, Ob::of<BaseMacro>(Function<ValueCastUnOp<long long, char>>()), ctx);

    ctx = Context::make(achar2long, Ob::of<BaseMacro>(Function<ValueCastUnOp<char, int>>()), ctx);
    ctx = Context::make(along2char, Ob::of<BaseMacro>(Function<ValueCastUnOp<int, char>>()), ctx);

    return ctx;
}

const BaseNumFunc &BaseNumFunc::inst()
{
    static const BaseNumFunc instance;
    return instance;
}

} // namespaces
