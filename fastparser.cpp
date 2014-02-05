#include "fastparser.h"

const Ob::Ptr FastParser::acar(new Symbol);
const Ob::Ptr FastParser::acdr(new Symbol);
const Ob::Ptr FastParser::acons(new Symbol);
const Ob::Ptr FastParser::aeq(new Symbol);
const Ob::Ptr FastParser::actxget(new Symbol);
const Ob::Ptr FastParser::actxpush(new Symbol);
const Ob::Ptr FastParser::aemptyctx(new Symbol);
const Ob::Ptr FastParser::agettype(new Symbol);

const Ob::Ptr FastParser::apairp(new Symbol);
const Ob::Ptr FastParser::alazyp(new Symbol);
const Ob::Ptr FastParser::alabelp(new Symbol);
const Ob::Ptr FastParser::acontextp(new Symbol);
const Ob::Ptr FastParser::aatomp(new Symbol);
const Ob::Ptr FastParser::asymbolp(new Symbol);
const Ob::Ptr FastParser::aconstp(new Symbol);
const Ob::Ptr FastParser::amacrop(new Symbol);
const Ob::Ptr FastParser::abasemacrop(new Symbol);
const Ob::Ptr FastParser::ausermacrop(new Symbol);
const Ob::Ptr FastParser::afunctionp(new Symbol);
const Ob::Ptr FastParser::abasefunctionp(new Symbol);
const Ob::Ptr FastParser::aclosurep(new Symbol);
const Ob::Ptr FastParser::aspectypep(new Symbol);

const Ob::Ptr FastParser::aintNeg(new Symbol);
const Ob::Ptr FastParser::aintPlus(new Symbol);
const Ob::Ptr FastParser::aintMinus(new Symbol);
const Ob::Ptr FastParser::aintProduct(new Symbol);
const Ob::Ptr FastParser::aintDivision(new Symbol);
const Ob::Ptr FastParser::aintMod(new Symbol);
const Ob::Ptr FastParser::aintp(new Symbol);
const Ob::Ptr FastParser::aintnot(new Symbol);
const Ob::Ptr FastParser::aintand(new Symbol);
const Ob::Ptr FastParser::aintor(new Symbol);
const Ob::Ptr FastParser::aintxor(new Symbol);
const Ob::Ptr FastParser::aintshl(new Symbol);
const Ob::Ptr FastParser::aintshr(new Symbol);
const Ob::Ptr FastParser::aintEql(new Symbol);
const Ob::Ptr FastParser::aintNE(new Symbol);
const Ob::Ptr FastParser::aintGT(new Symbol);
const Ob::Ptr FastParser::aintLT(new Symbol);
const Ob::Ptr FastParser::aintGE(new Symbol);
const Ob::Ptr FastParser::aintLE(new Symbol);

const Ob::Ptr FastParser::alongp(new Symbol);
const Ob::Ptr FastParser::alongnot(new Symbol);
const Ob::Ptr FastParser::alongand(new Symbol);
const Ob::Ptr FastParser::alongor(new Symbol);
const Ob::Ptr FastParser::alongxor(new Symbol);
const Ob::Ptr FastParser::alongshl(new Symbol);
const Ob::Ptr FastParser::alongshr(new Symbol);

const Ob::Ptr FastParser::afloatNeg(new Symbol);
const Ob::Ptr FastParser::afloatPlus(new Symbol);
const Ob::Ptr FastParser::afloatMinus(new Symbol);
const Ob::Ptr FastParser::afloatProduct(new Symbol);
const Ob::Ptr FastParser::afloatDivision(new Symbol);
const Ob::Ptr FastParser::afloatp(new Symbol);
const Ob::Ptr FastParser::afloatEql(new Symbol);
const Ob::Ptr FastParser::afloatNE(new Symbol);
const Ob::Ptr FastParser::afloatGT(new Symbol);
const Ob::Ptr FastParser::afloatLT(new Symbol);
const Ob::Ptr FastParser::afloatGE(new Symbol);
const Ob::Ptr FastParser::afloatLE(new Symbol);

const Ob::Ptr FastParser::along2int(new Symbol);
const Ob::Ptr FastParser::aint2long(new Symbol);

const Ob::Ptr FastParser::afloat2int(new Symbol);
const Ob::Ptr FastParser::aint2float(new Symbol);

const Ob::Ptr FastParser::avecp(new Symbol);
const Ob::Ptr FastParser::amkvec(new Symbol);
const Ob::Ptr FastParser::aveclen(new Symbol);
const Ob::Ptr FastParser::avecmid(new Symbol);
const Ob::Ptr FastParser::avecel(new Symbol);
const Ob::Ptr FastParser::aveccat(new Symbol);
