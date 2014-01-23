#ifndef NUMBERS_H
#define NUMBERS_H

#include "integers.h"
#include "floats.h"

class FIntToFloat : public Operation {
protected:
    Ptr applyX(const Ptr &x) {
        SpecType * stx = x->asSpecType();
        if(stx == 0) throw 0;
        Integer * i = stx->asInteger();
        if(i == 0) throw 0;
        return new Float(i->getInteger());
    }

public:
    string toString() const {return "{FIntToFloat}";}
};

class FFloatToInt : public Operation {
protected:
    Ptr applyX(const Ptr &x) {
        SpecType * stx = x->asSpecType();
        if(stx == 0) throw 0;
        Float * f = stx->asFloat();
        if(f == 0) throw 0;
        return new Integer(int(f->getFloat()));
    }

public:
    string toString() const {return "{FFloatToInt}";}
};

#endif // NUMBERS_H
