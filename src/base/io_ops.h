#pragma once

#include <io.h>

class InputOpenUnOp {
public:
    static Ptr op(const Ptr &x) {
        return new FileInputDescriptor(x->cast<ByteArray>()->getData());
    }
};

class OutputOpenUnOp {
public:
    static Ptr op(const Ptr &x) {
        return new FileOutputDescriptor(x->cast<ByteArray>()->getData());
    }
};

class ReadBinOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2) {
        std::istream &in = x1->cast<IOStreamDescriptor>()->getInputStream();
        int size = x2->cast<Value<int> >()->getValue();
        ByteArray *res = new ByteArray(size);
        in.read(res->getData(), size);
        return res;
    }
};

class WriteBinOp {
public:
    static Ptr op(const Ptr &x1, const Ptr &x2) {
        std::ostream &out = x1->cast<IOStreamDescriptor>()->getOutputStream();
        ByteArray * ba = x2->cast<ByteArray>();
        out.write(ba->getData(), ba->getSize());
        return new Value<int>(ba->getSize());
    }
};
