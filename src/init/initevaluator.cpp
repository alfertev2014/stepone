#include <init/initevaluator.h>

#include <impl/objects/stepone_obs.h>
#include <impl/symbols/basesymbols.h>

#include <impl/core/macro.h>
#include <impl/core/value.h>

namespace stepone::init {

using namespace symbols;
using namespace objects;

static inline void addToContext(Ptr & a, const Ptr & p, const Ptr & v) {
    a = core::Context::make(p, v, a);
}

Ptr BaseEvaluator::createContext() {
    Ptr a(Ptr::anil);
    addToContext(a, BaseNumFuncSymbols::inst().aintNeg, BaseNumFunc::inst().fintNeg);
    addToContext(a, BaseNumFuncSymbols::inst().aintPlus, BaseNumFunc::inst().fintPlus);
    addToContext(a, BaseNumFuncSymbols::inst().aintMinus, BaseNumFunc::inst().fintMinus);
    addToContext(a, BaseNumFuncSymbols::inst().aintProduct, BaseNumFunc::inst().fintProduct);
    addToContext(a, BaseNumFuncSymbols::inst().aintDivision, BaseNumFunc::inst().fintDivision);
    addToContext(a, BaseNumFuncSymbols::inst().aintMod, BaseNumFunc::inst().fintMod);
    addToContext(a, BaseNumFuncSymbols::inst().aintp, BaseNumFunc::inst().fintp);
    addToContext(a, BaseNumFuncSymbols::inst().aintnot, BaseNumFunc::inst().fintnot);
    addToContext(a, BaseNumFuncSymbols::inst().aintand, BaseNumFunc::inst().fintand);
    addToContext(a, BaseNumFuncSymbols::inst().aintor, BaseNumFunc::inst().fintor);
    addToContext(a, BaseNumFuncSymbols::inst().aintxor, BaseNumFunc::inst().fintxor);
    addToContext(a, BaseNumFuncSymbols::inst().aintshl, BaseNumFunc::inst().fintshl);
    addToContext(a, BaseNumFuncSymbols::inst().aintshr, BaseNumFunc::inst().fintshr);
    addToContext(a, BaseNumFuncSymbols::inst().aintEql, BaseNumFunc::inst().fintEql);
    addToContext(a, BaseNumFuncSymbols::inst().aintNE, BaseNumFunc::inst().fintNE);
    addToContext(a, BaseNumFuncSymbols::inst().aintLT, BaseNumFunc::inst().fintLT);
    addToContext(a, BaseNumFuncSymbols::inst().aintGT, BaseNumFunc::inst().fintGT);
    addToContext(a, BaseNumFuncSymbols::inst().aintLE, BaseNumFunc::inst().fintLE);
    addToContext(a, BaseNumFuncSymbols::inst().aintGE, BaseNumFunc::inst().fintGE);

    addToContext(a, BaseNumFuncSymbols::inst().alongp, BaseNumFunc::inst().flongp);
    addToContext(a, BaseNumFuncSymbols::inst().alongnot, BaseNumFunc::inst().flongnot);
    addToContext(a, BaseNumFuncSymbols::inst().alongand, BaseNumFunc::inst().flongand);
    addToContext(a, BaseNumFuncSymbols::inst().alongor, BaseNumFunc::inst().flongor);
    addToContext(a, BaseNumFuncSymbols::inst().alongxor, BaseNumFunc::inst().flongxor);
    addToContext(a, BaseNumFuncSymbols::inst().alongshl, BaseNumFunc::inst().flongshl);
    addToContext(a, BaseNumFuncSymbols::inst().alongshr, BaseNumFunc::inst().flongshr);

    addToContext(a, BaseNumFuncSymbols::inst().alongEql, BaseNumFunc::inst().flongEql);
    addToContext(a, BaseNumFuncSymbols::inst().alongNE, BaseNumFunc::inst().flongNE);
    addToContext(a, BaseNumFuncSymbols::inst().alongLT, BaseNumFunc::inst().flongLT);
    addToContext(a, BaseNumFuncSymbols::inst().alongGT, BaseNumFunc::inst().flongGT);
    addToContext(a, BaseNumFuncSymbols::inst().alongLE, BaseNumFunc::inst().flongLE);
    addToContext(a, BaseNumFuncSymbols::inst().alongGE, BaseNumFunc::inst().flongGE);

    addToContext(a, BaseNumFuncSymbols::inst().acharp, BaseNumFunc::inst().fcharp);
    addToContext(a, BaseNumFuncSymbols::inst().acharnot, BaseNumFunc::inst().fcharnot);
    addToContext(a, BaseNumFuncSymbols::inst().acharand, BaseNumFunc::inst().fcharand);
    addToContext(a, BaseNumFuncSymbols::inst().acharor, BaseNumFunc::inst().fcharor);
    addToContext(a, BaseNumFuncSymbols::inst().acharxor, BaseNumFunc::inst().fcharxor);
    addToContext(a, BaseNumFuncSymbols::inst().acharshl, BaseNumFunc::inst().fcharshl);
    addToContext(a, BaseNumFuncSymbols::inst().acharshr, BaseNumFunc::inst().fcharshr);
    addToContext(a, BaseNumFuncSymbols::inst().acharEql, BaseNumFunc::inst().fcharEql);
    addToContext(a, BaseNumFuncSymbols::inst().acharNE, BaseNumFunc::inst().fcharNE);
    addToContext(a, BaseNumFuncSymbols::inst().acharLT, BaseNumFunc::inst().fcharLT);
    addToContext(a, BaseNumFuncSymbols::inst().acharGT, BaseNumFunc::inst().fcharGT);
    addToContext(a, BaseNumFuncSymbols::inst().acharLE, BaseNumFunc::inst().fcharLE);
    addToContext(a, BaseNumFuncSymbols::inst().acharGE, BaseNumFunc::inst().fcharGE);

    addToContext(a, BaseNumFuncSymbols::inst().afloatNeg, BaseNumFunc::inst().ffloatNeg);
    addToContext(a, BaseNumFuncSymbols::inst().afloatPlus, BaseNumFunc::inst().ffloatPlus);
    addToContext(a, BaseNumFuncSymbols::inst().afloatMinus, BaseNumFunc::inst().ffloatMinus);
    addToContext(a, BaseNumFuncSymbols::inst().afloatProduct, BaseNumFunc::inst().ffloatProduct);
    addToContext(a, BaseNumFuncSymbols::inst().afloatDivision, BaseNumFunc::inst().ffloatDivision);
    addToContext(a, BaseNumFuncSymbols::inst().afloatp, BaseNumFunc::inst().ffloatp);
    addToContext(a, BaseNumFuncSymbols::inst().afloatEql, BaseNumFunc::inst().ffloatEql);
    addToContext(a, BaseNumFuncSymbols::inst().afloatNE, BaseNumFunc::inst().ffloatNE);
    addToContext(a, BaseNumFuncSymbols::inst().afloatLT, BaseNumFunc::inst().ffloatLT);
    addToContext(a, BaseNumFuncSymbols::inst().afloatGT, BaseNumFunc::inst().ffloatGT);
    addToContext(a, BaseNumFuncSymbols::inst().afloatLE, BaseNumFunc::inst().ffloatLE);
    addToContext(a, BaseNumFuncSymbols::inst().afloatGE, BaseNumFunc::inst().ffloatGE);

    addToContext(a, BaseNumFuncSymbols::inst().along2int, BaseNumFunc::inst().flong2int);
    addToContext(a, BaseNumFuncSymbols::inst().aint2long, BaseNumFunc::inst().fint2long);
    addToContext(a, BaseNumFuncSymbols::inst().afloat2int, BaseNumFunc::inst().ffloat2int);
    addToContext(a, BaseNumFuncSymbols::inst().aint2float, BaseNumFunc::inst().fint2float);
    addToContext(a, BaseNumFuncSymbols::inst().achar2int, BaseNumFunc::inst().fchar2int);
    addToContext(a, BaseNumFuncSymbols::inst().aint2char, BaseNumFunc::inst().fint2char);
    addToContext(a, BaseNumFuncSymbols::inst().achar2long, BaseNumFunc::inst().fchar2long);
    addToContext(a, BaseNumFuncSymbols::inst().along2char, BaseNumFunc::inst().flong2char);

    addToContext(a, BaseNumFuncSymbols::inst().aszi, new core::Value<int>(sizeof(int)));
    addToContext(a, BaseNumFuncSymbols::inst().aszf, new core::Value<int>(sizeof(float)));
    addToContext(a, BaseNumFuncSymbols::inst().aszc, new core::Value<int>(sizeof(char)));
    addToContext(a, BaseNumFuncSymbols::inst().aszu, new core::Value<int>(sizeof(long long)));

    addToContext(a, VectorFuncSymbols::inst().avecp, VectorFunctions::inst().fvecp);
    addToContext(a, VectorFuncSymbols::inst().amkvec, VectorFunctions::inst().fmkvec);
    addToContext(a, VectorFuncSymbols::inst().avecclone, VectorFunctions::inst().fvecclone);
    addToContext(a, VectorFuncSymbols::inst().aveclen, VectorFunctions::inst().fveclen);
    addToContext(a, VectorFuncSymbols::inst().avecmid, VectorFunctions::inst().fvecmid);
    addToContext(a, VectorFuncSymbols::inst().avecslice, VectorFunctions::inst().fvecslice);
    addToContext(a, VectorFuncSymbols::inst().avecel, VectorFunctions::inst().fvecel);
    addToContext(a, VectorFuncSymbols::inst().aveccat, VectorFunctions::inst().fveccat);

    addToContext(a, IOFuncSymbols::inst().ainputp, IOFunctions::inst().finputp);
    addToContext(a, IOFuncSymbols::inst().aoutputp, IOFunctions::inst().foutputp);
    addToContext(a, IOFuncSymbols::inst().aopenin, IOFunctions::inst().fopenin);
    addToContext(a, IOFuncSymbols::inst().aopenout, IOFunctions::inst().fopenout);
    addToContext(a, IOFuncSymbols::inst().aread, IOFunctions::inst().fread);
    addToContext(a, IOFuncSymbols::inst().awrite, IOFunctions::inst().fwrite);
    addToContext(a, IOFuncSymbols::inst().astdin, IOFunctions::inst().stdin);
    addToContext(a, IOFuncSymbols::inst().astdout, IOFunctions::inst().stdout);
    addToContext(a, IOFuncSymbols::inst().astderr, IOFunctions::inst().stderr);

    addToContext(a, ByteArrayFuncSymbols::inst().abarrayp, ByteArrayFunctions::inst().fbarrayp);
    addToContext(a, ByteArrayFuncSymbols::inst().abarraylen, ByteArrayFunctions::inst().fbarraylen);
    addToContext(a, ByteArrayFuncSymbols::inst().abarrayclone, ByteArrayFunctions::inst().fbarrayclone);
    addToContext(a, ByteArrayFuncSymbols::inst().abarraycmp, ByteArrayFunctions::inst().fbarraycmp);
    addToContext(a, ByteArrayFuncSymbols::inst().abarrayncmp, ByteArrayFunctions::inst().fbarrayncmp);
    addToContext(a, ByteArrayFuncSymbols::inst().abarrayfindch, ByteArrayFunctions::inst().fbarrayfindch);
    addToContext(a, ByteArrayFuncSymbols::inst().abarrayfind, ByteArrayFunctions::inst().fbarrayfind);
    addToContext(a, ByteArrayFuncSymbols::inst().abarraycat, ByteArrayFunctions::inst().fbarraycat);
    addToContext(a, ByteArrayFuncSymbols::inst().abarraymid, ByteArrayFunctions::inst().fbarraymid);
    addToContext(a, ByteArrayFuncSymbols::inst().abarrayslice, ByteArrayFunctions::inst().fbarrayslice);
    addToContext(a, ByteArrayFuncSymbols::inst().aserint, ByteArrayFunctions::inst().fserint);
    addToContext(a, ByteArrayFuncSymbols::inst().aserfloat, ByteArrayFunctions::inst().fserfloat);
    addToContext(a, ByteArrayFuncSymbols::inst().aserchar, ByteArrayFunctions::inst().fserchar);
    addToContext(a, ByteArrayFuncSymbols::inst().agetint, ByteArrayFunctions::inst().fgetint);
    addToContext(a, ByteArrayFuncSymbols::inst().agetfloat, ByteArrayFunctions::inst().fgetfloat);
    addToContext(a, ByteArrayFuncSymbols::inst().agetchar, ByteArrayFunctions::inst().fgetchar);

    addToContext(a, BaseTypePredSymbols::inst().apairp, BaseTypePredicates::inst().fpairp);
    addToContext(a, BaseTypePredSymbols::inst().alazyp, BaseTypePredicates::inst().flazyp);
    addToContext(a, BaseTypePredSymbols::inst().alabelp, BaseTypePredicates::inst().flabelp);
    addToContext(a, BaseTypePredSymbols::inst().aatomp, BaseTypePredicates::inst().fatomp);
    addToContext(a, BaseTypePredSymbols::inst().asymbolp, BaseTypePredicates::inst().fsymbolp);
    addToContext(a, BaseTypePredSymbols::inst().aconstp, BaseTypePredicates::inst().fconstp);
    addToContext(a, BaseTypePredSymbols::inst().amacrop, BaseTypePredicates::inst().fmacrop);
    addToContext(a, BaseTypePredSymbols::inst().abasemacrop, BaseTypePredicates::inst().fbasemacrop);
    addToContext(a, BaseTypePredSymbols::inst().ausermacrop, BaseTypePredicates::inst().fusermacrop);
    addToContext(a, BaseTypePredSymbols::inst().avaluep, BaseTypePredicates::inst().fvaluep);

    addToContext(a, BaseFuncSymbols::inst().actxget, BaseFunctions::inst().fctxget);
    addToContext(a, BaseFuncSymbols::inst().actxpush, BaseFunctions::inst().fctxpush);
    addToContext(a, BaseFuncSymbols::inst().aeempty, core::Evaluator::eempty);
    addToContext(a, BaseFuncSymbols::inst().acons, BaseFunctions::inst().fcons);
    addToContext(a, BaseFuncSymbols::inst().acar, BaseFunctions::inst().fcar);
    addToContext(a, BaseFuncSymbols::inst().acdr, BaseFunctions::inst().fcdr);
    addToContext(a, BaseFuncSymbols::inst().aeq, BaseFunctions::inst().feq);

    addToContext(a, Ptr::anil, Ptr::anil);
    addToContext(a, Ptr::at, Ptr::at);

    addToContext(a, BaseMacroSymbols::inst().agensym, BaseMacroses::inst().mgensym);
    addToContext(a, BaseMacroSymbols::inst().acurctx, BaseMacroses::inst().mcurctx);
    addToContext(a, BaseMacroSymbols::inst().abot, BaseMacroses::inst().mbot);
    addToContext(a, BaseMacroSymbols::inst().atry, BaseMacroses::inst().mtry);
    addToContext(a, BaseMacroSymbols::inst().aunlazy, BaseMacroses::inst().munlazy);
    addToContext(a, BaseMacroSymbols::inst().alazy, BaseMacroses::inst().mlazy);
    addToContext(a, BaseMacroSymbols::inst().amacro, BaseMacroses::inst().mmacro);
    addToContext(a, BaseMacroSymbols::inst().aapply, BaseMacroses::inst().mapply);
    addToContext(a, BaseMacroSymbols::inst().alabel, BaseMacroses::inst().mlabel);
    addToContext(a, BaseMacroSymbols::inst().aif, BaseMacroses::inst().mif);
    addToContext(a, BaseMacroSymbols::inst().alambda, BaseMacroses::inst().mlambda);
    addToContext(a, BaseMacroSymbols::inst().alet, BaseMacroses::inst().mlet);
    addToContext(a, BaseMacroSymbols::inst().aquote, BaseMacroses::inst().mquote);
    return a;
}

} // namespaces
