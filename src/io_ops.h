#pragma once

#include "io.h"

class InputOpenUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {
        return new FileInputDescriptor(x->cast<ByteArray>()->getData());
    }
    static string toString() {return "open-in";}
};

class OutputOpenUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {
        return new FileOutputDescriptor(x->cast<ByteArray>()->getData());
    }
    static string toString() {return "open-out";}
};

class ReadBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        istream &in = x1->cast<IOStreamDescriptor>()->getInputStream();
        int size = x2->cast<ValueType<int> >()->getValue();
        ByteArray *res = new ByteArray(size);
        in.read(res->getData(), size);
        return res;
    }
    static string toString() {return "read";}
};

class WriteBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        ostream &out = x1->cast<IOStreamDescriptor>()->getOutputStream();
        ByteArray * ba = x2->cast<ByteArray>();
        out.write(ba->getData(), ba->getSize());
        return new ValueType<int>(ba->getSize());
    }
    static string toString() {return "write";}
};
