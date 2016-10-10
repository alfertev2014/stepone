#pragma once

#include <io.h>

class InputOpenUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {
        return new FileInputDescriptor(x->cast<ByteArray>()->getData());
    }
};

class OutputOpenUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {
        return new FileOutputDescriptor(x->cast<ByteArray>()->getData());
    }
};

class ReadBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        std::istream &in = x1->cast<IOStreamDescriptor>()->getInputStream();
        int size = x2->cast<Value<int> >()->getValue();
        ByteArray *res = new ByteArray(size);
        in.read(res->getData(), size);
        return res;
    }
};

class WriteBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        std::ostream &out = x1->cast<IOStreamDescriptor>()->getOutputStream();
        ByteArray * ba = x2->cast<ByteArray>();
        out.write(ba->getData(), ba->getSize());
        return new Value<int>(ba->getSize());
    }
};
