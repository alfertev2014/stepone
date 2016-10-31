#include <base/initevaluator.h>

#include "stepone_obs.h"
#include "basesymbols.h"

#include <macro.h>
#include <value.h>

static inline void addInContext(Ptr & a, const Ptr & p, const Ptr & v) {
    a = Context::make(p, v, a);
}

Ptr BaseEvaluator::createContext() {
    Ptr a;
    addInContext(a, BaseNumFuncSymbols::inst().aintNeg, BaseNumFunc::inst().fintNeg);
    addInContext(a, BaseNumFuncSymbols::inst().aintPlus, BaseNumFunc::inst().fintPlus);
    addInContext(a, BaseNumFuncSymbols::inst().aintMinus, BaseNumFunc::inst().fintMinus);
    addInContext(a, BaseNumFuncSymbols::inst().aintProduct, BaseNumFunc::inst().fintProduct);
    addInContext(a, BaseNumFuncSymbols::inst().aintDivision, BaseNumFunc::inst().fintDivision);
    addInContext(a, BaseNumFuncSymbols::inst().aintMod, BaseNumFunc::inst().fintMod);
    addInContext(a, BaseNumFuncSymbols::inst().aintp, BaseNumFunc::inst().fintp);
    addInContext(a, BaseNumFuncSymbols::inst().aintnot, BaseNumFunc::inst().fintnot);
    addInContext(a, BaseNumFuncSymbols::inst().aintand, BaseNumFunc::inst().fintand);
    addInContext(a, BaseNumFuncSymbols::inst().aintor, BaseNumFunc::inst().fintor);
    addInContext(a, BaseNumFuncSymbols::inst().aintxor, BaseNumFunc::inst().fintxor);
    addInContext(a, BaseNumFuncSymbols::inst().aintshl, BaseNumFunc::inst().fintshl);
    addInContext(a, BaseNumFuncSymbols::inst().aintshr, BaseNumFunc::inst().fintshr);
    addInContext(a, BaseNumFuncSymbols::inst().aintEql, BaseNumFunc::inst().fintEql);
    addInContext(a, BaseNumFuncSymbols::inst().aintNE, BaseNumFunc::inst().fintNE);
    addInContext(a, BaseNumFuncSymbols::inst().aintLT, BaseNumFunc::inst().fintLT);
    addInContext(a, BaseNumFuncSymbols::inst().aintGT, BaseNumFunc::inst().fintGT);
    addInContext(a, BaseNumFuncSymbols::inst().aintLE, BaseNumFunc::inst().fintLE);
    addInContext(a, BaseNumFuncSymbols::inst().aintGE, BaseNumFunc::inst().fintGE);

    addInContext(a, BaseNumFuncSymbols::inst().alongp, BaseNumFunc::inst().flongp);
    addInContext(a, BaseNumFuncSymbols::inst().alongnot, BaseNumFunc::inst().flongnot);
    addInContext(a, BaseNumFuncSymbols::inst().alongand, BaseNumFunc::inst().flongand);
    addInContext(a, BaseNumFuncSymbols::inst().alongor, BaseNumFunc::inst().flongor);
    addInContext(a, BaseNumFuncSymbols::inst().alongxor, BaseNumFunc::inst().flongxor);
    addInContext(a, BaseNumFuncSymbols::inst().alongshl, BaseNumFunc::inst().flongshl);
    addInContext(a, BaseNumFuncSymbols::inst().alongshr, BaseNumFunc::inst().flongshr);

    addInContext(a, BaseNumFuncSymbols::inst().alongEql, BaseNumFunc::inst().flongEql);
    addInContext(a, BaseNumFuncSymbols::inst().alongNE, BaseNumFunc::inst().flongNE);
    addInContext(a, BaseNumFuncSymbols::inst().alongLT, BaseNumFunc::inst().flongLT);
    addInContext(a, BaseNumFuncSymbols::inst().alongGT, BaseNumFunc::inst().flongGT);
    addInContext(a, BaseNumFuncSymbols::inst().alongLE, BaseNumFunc::inst().flongLE);
    addInContext(a, BaseNumFuncSymbols::inst().alongGE, BaseNumFunc::inst().flongGE);

    addInContext(a, BaseNumFuncSymbols::inst().acharp, BaseNumFunc::inst().fcharp);
    addInContext(a, BaseNumFuncSymbols::inst().acharnot, BaseNumFunc::inst().fcharnot);
    addInContext(a, BaseNumFuncSymbols::inst().acharand, BaseNumFunc::inst().fcharand);
    addInContext(a, BaseNumFuncSymbols::inst().acharor, BaseNumFunc::inst().fcharor);
    addInContext(a, BaseNumFuncSymbols::inst().acharxor, BaseNumFunc::inst().fcharxor);
    addInContext(a, BaseNumFuncSymbols::inst().acharshl, BaseNumFunc::inst().fcharshl);
    addInContext(a, BaseNumFuncSymbols::inst().acharshr, BaseNumFunc::inst().fcharshr);
    addInContext(a, BaseNumFuncSymbols::inst().acharEql, BaseNumFunc::inst().fcharEql);
    addInContext(a, BaseNumFuncSymbols::inst().acharNE, BaseNumFunc::inst().fcharNE);
    addInContext(a, BaseNumFuncSymbols::inst().acharLT, BaseNumFunc::inst().fcharLT);
    addInContext(a, BaseNumFuncSymbols::inst().acharGT, BaseNumFunc::inst().fcharGT);
    addInContext(a, BaseNumFuncSymbols::inst().acharLE, BaseNumFunc::inst().fcharLE);
    addInContext(a, BaseNumFuncSymbols::inst().acharGE, BaseNumFunc::inst().fcharGE);

    addInContext(a, BaseNumFuncSymbols::inst().afloatNeg, BaseNumFunc::inst().ffloatNeg);
    addInContext(a, BaseNumFuncSymbols::inst().afloatPlus, BaseNumFunc::inst().ffloatPlus);
    addInContext(a, BaseNumFuncSymbols::inst().afloatMinus, BaseNumFunc::inst().ffloatMinus);
    addInContext(a, BaseNumFuncSymbols::inst().afloatProduct, BaseNumFunc::inst().ffloatProduct);
    addInContext(a, BaseNumFuncSymbols::inst().afloatDivision, BaseNumFunc::inst().ffloatDivision);
    addInContext(a, BaseNumFuncSymbols::inst().afloatp, BaseNumFunc::inst().ffloatp);
    addInContext(a, BaseNumFuncSymbols::inst().afloatEql, BaseNumFunc::inst().ffloatEql);
    addInContext(a, BaseNumFuncSymbols::inst().afloatNE, BaseNumFunc::inst().ffloatNE);
    addInContext(a, BaseNumFuncSymbols::inst().afloatLT, BaseNumFunc::inst().ffloatLT);
    addInContext(a, BaseNumFuncSymbols::inst().afloatGT, BaseNumFunc::inst().ffloatGT);
    addInContext(a, BaseNumFuncSymbols::inst().afloatLE, BaseNumFunc::inst().ffloatLE);
    addInContext(a, BaseNumFuncSymbols::inst().afloatGE, BaseNumFunc::inst().ffloatGE);

    addInContext(a, BaseNumFuncSymbols::inst().along2int, BaseNumFunc::inst().flong2int);
    addInContext(a, BaseNumFuncSymbols::inst().aint2long, BaseNumFunc::inst().fint2long);
    addInContext(a, BaseNumFuncSymbols::inst().afloat2int, BaseNumFunc::inst().ffloat2int);
    addInContext(a, BaseNumFuncSymbols::inst().aint2float, BaseNumFunc::inst().fint2float);
    addInContext(a, BaseNumFuncSymbols::inst().achar2int, BaseNumFunc::inst().fchar2int);
    addInContext(a, BaseNumFuncSymbols::inst().aint2char, BaseNumFunc::inst().fint2char);
    addInContext(a, BaseNumFuncSymbols::inst().achar2long, BaseNumFunc::inst().fchar2long);
    addInContext(a, BaseNumFuncSymbols::inst().along2char, BaseNumFunc::inst().flong2char);

    addInContext(a, BaseNumFuncSymbols::inst().aszi, new Value<int>(sizeof(int)));
    addInContext(a, BaseNumFuncSymbols::inst().aszf, new Value<int>(sizeof(float)));
    addInContext(a, BaseNumFuncSymbols::inst().aszc, new Value<int>(sizeof(char)));
    addInContext(a, BaseNumFuncSymbols::inst().aszu, new Value<int>(sizeof(long long)));

    addInContext(a, VectorFuncSymbols::inst().avecp, VectorFunctions::inst().fvecp);
    addInContext(a, VectorFuncSymbols::inst().amkvec, VectorFunctions::inst().fmkvec);
    addInContext(a, VectorFuncSymbols::inst().avecclone, VectorFunctions::inst().fvecclone);
    addInContext(a, VectorFuncSymbols::inst().aveclen, VectorFunctions::inst().fveclen);
    addInContext(a, VectorFuncSymbols::inst().avecmid, VectorFunctions::inst().fvecmid);
    addInContext(a, VectorFuncSymbols::inst().avecslice, VectorFunctions::inst().fvecslice);
    addInContext(a, VectorFuncSymbols::inst().avecel, VectorFunctions::inst().fvecel);
    addInContext(a, VectorFuncSymbols::inst().aveccat, VectorFunctions::inst().fveccat);

    addInContext(a, IOFuncSymbols::inst().ainputp, IOFunctions::inst().finputp);
    addInContext(a, IOFuncSymbols::inst().aoutputp, IOFunctions::inst().foutputp);
    addInContext(a, IOFuncSymbols::inst().aopenin, IOFunctions::inst().fopenin);
    addInContext(a, IOFuncSymbols::inst().aopenout, IOFunctions::inst().fopenout);
    addInContext(a, IOFuncSymbols::inst().aread, IOFunctions::inst().fread);
    addInContext(a, IOFuncSymbols::inst().awrite, IOFunctions::inst().fwrite);
    addInContext(a, IOFuncSymbols::inst().astdin, IOFunctions::inst().stdin);
    addInContext(a, IOFuncSymbols::inst().astdout, IOFunctions::inst().stdout);
    addInContext(a, IOFuncSymbols::inst().astderr, IOFunctions::inst().stderr);

    addInContext(a, ByteArrayFuncSymbols::inst().abarrayp, ByteArrayFunctions::inst().fbarrayp);
    addInContext(a, ByteArrayFuncSymbols::inst().abarraylen, ByteArrayFunctions::inst().fbarraylen);
    addInContext(a, ByteArrayFuncSymbols::inst().abarrayclone, ByteArrayFunctions::inst().fbarrayclone);
    addInContext(a, ByteArrayFuncSymbols::inst().abarraycmp, ByteArrayFunctions::inst().fbarraycmp);
    addInContext(a, ByteArrayFuncSymbols::inst().abarrayncmp, ByteArrayFunctions::inst().fbarrayncmp);
    addInContext(a, ByteArrayFuncSymbols::inst().abarrayfindch, ByteArrayFunctions::inst().fbarrayfindch);
    addInContext(a, ByteArrayFuncSymbols::inst().abarrayfind, ByteArrayFunctions::inst().fbarrayfind);
    addInContext(a, ByteArrayFuncSymbols::inst().abarraycat, ByteArrayFunctions::inst().fbarraycat);
    addInContext(a, ByteArrayFuncSymbols::inst().abarraymid, ByteArrayFunctions::inst().fbarraymid);
    addInContext(a, ByteArrayFuncSymbols::inst().abarrayslice, ByteArrayFunctions::inst().fbarrayslice);
    addInContext(a, ByteArrayFuncSymbols::inst().aserint, ByteArrayFunctions::inst().fserint);
    addInContext(a, ByteArrayFuncSymbols::inst().aserfloat, ByteArrayFunctions::inst().fserfloat);
    addInContext(a, ByteArrayFuncSymbols::inst().aserchar, ByteArrayFunctions::inst().fserchar);
    addInContext(a, ByteArrayFuncSymbols::inst().agetint, ByteArrayFunctions::inst().fgetint);
    addInContext(a, ByteArrayFuncSymbols::inst().agetfloat, ByteArrayFunctions::inst().fgetfloat);
    addInContext(a, ByteArrayFuncSymbols::inst().agetchar, ByteArrayFunctions::inst().fgetchar);

    addInContext(a, BaseTypePredSymbols::inst().apairp, BaseTypePredicates::inst().fpairp);
    addInContext(a, BaseTypePredSymbols::inst().alazyp, BaseTypePredicates::inst().flazyp);
    addInContext(a, BaseTypePredSymbols::inst().alabelp, BaseTypePredicates::inst().flabelp);
    addInContext(a, BaseTypePredSymbols::inst().aatomp, BaseTypePredicates::inst().fatomp);
    addInContext(a, BaseTypePredSymbols::inst().asymbolp, BaseTypePredicates::inst().fsymbolp);
    addInContext(a, BaseTypePredSymbols::inst().aconstp, BaseTypePredicates::inst().fconstp);
    addInContext(a, BaseTypePredSymbols::inst().amacrop, BaseTypePredicates::inst().fmacrop);
    addInContext(a, BaseTypePredSymbols::inst().abasemacrop, BaseTypePredicates::inst().fbasemacrop);
    addInContext(a, BaseTypePredSymbols::inst().ausermacrop, BaseTypePredicates::inst().fusermacrop);
    addInContext(a, BaseTypePredSymbols::inst().avaluep, BaseTypePredicates::inst().fvaluep);

    addInContext(a, BaseFuncSymbols::inst().actxget, BaseFunctions::inst().fctxget);
    addInContext(a, BaseFuncSymbols::inst().actxpush, BaseFunctions::inst().fctxpush);
    addInContext(a, BaseFuncSymbols::inst().aeempty, Evaluator::eempty);
    addInContext(a, BaseFuncSymbols::inst().agettype, BaseFunctions::inst().fgettype);
    addInContext(a, BaseFuncSymbols::inst().acons, BaseFunctions::inst().fcons);
    addInContext(a, BaseFuncSymbols::inst().acar, BaseFunctions::inst().fcar);
    addInContext(a, BaseFuncSymbols::inst().acdr, BaseFunctions::inst().fcdr);
    addInContext(a, BaseFuncSymbols::inst().aeq, BaseFunctions::inst().feq);

    addInContext(a, Ob::anil, Ob::anil);
    addInContext(a, Ob::at, Ob::at);

    addInContext(a, BaseMacroSymbols::inst().agensym, BaseMacroses::inst().mgensym);
    addInContext(a, BaseMacroSymbols::inst().acurctx, BaseMacroses::inst().mcurctx);
    addInContext(a, BaseMacroSymbols::inst().abot, BaseMacroses::inst().mbot);
    addInContext(a, BaseMacroSymbols::inst().atry, BaseMacroses::inst().mtry);
    addInContext(a, BaseMacroSymbols::inst().aunlazy, BaseMacroses::inst().munlazy);
    addInContext(a, BaseMacroSymbols::inst().alazy, BaseMacroses::inst().mlazy);
    addInContext(a, BaseMacroSymbols::inst().amacro, BaseMacroses::inst().mmacro);
    addInContext(a, BaseMacroSymbols::inst().aapply, BaseMacroses::inst().mapply);
    addInContext(a, BaseMacroSymbols::inst().alabel, BaseMacroses::inst().mlabel);
    addInContext(a, BaseMacroSymbols::inst().aif, BaseMacroses::inst().mif);
    addInContext(a, BaseMacroSymbols::inst().alambda, BaseMacroses::inst().mlambda);
    addInContext(a, BaseMacroSymbols::inst().alet, BaseMacroses::inst().mlet);
    addInContext(a, BaseMacroSymbols::inst().aquote, BaseMacroses::inst().mquote);
    return a;
}
