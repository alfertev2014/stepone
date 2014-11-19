#pragma once

#include "core.h"
#include "bytearray.h"
#include "operations.h"
#include "fstream"

class InputDescriptor : public Value {
public:
    Ptr getTypeId() const {return TypeInfo<InputDescriptor>::type_id;}
    static string getTypeString() {return "InputDescriptor";}
    string typeToString() const {return getTypeString();}
private:
    ifstream stream;
public:
    InputDescriptor(const char * fname) : stream(fname) {
        if(!stream.is_open())
            throw SemanticError();
    }
    ifstream &getStream() {return stream;}
};

class OutputDescriptor : public Value {
public:
    Ptr getTypeId() const {return TypeInfo<OutputDescriptor>::type_id;}
    static string getTypeString() {return "OutputDescriptor";}
    string typeToString() const {return getTypeString();}
private:
    ofstream stream;
public:
    OutputDescriptor(const char * fname) : stream(fname) {
        if(!stream.is_open())
            throw SemanticError();
    }
    ofstream &getStream() {return stream;}
};

class InputOpenUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {
        ByteArray * ba = x->cast<ByteArray>();
        return new InputDescriptor(ba->getData());
    }
    static string toString() {return "InputOpenUnOp";}
};

class OutputOpenUnOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x) {
        ByteArray * ba = x->cast<ByteArray>();
        return new OutputDescriptor(ba->getData());
    }
    static string toString() {return "OutputOpenUnOp";}
};

class ReadBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        InputDescriptor *in = x1->cast<InputDescriptor>();
        int size = x2->cast<ValueType<int> >()->getValue();
        ByteArray *res = new ByteArray(size);
        in->getStream().read(res->getData(), size);
        return res;
    }
    static string toString() {return "ReadBinOp";}
};

class WriteBinOp {
public:
    static Ob::Ptr op(const Ob::Ptr &x1, const Ob::Ptr &x2) {
        OutputDescriptor *out = x1->cast<OutputDescriptor>();
        ByteArray * ba = x2->cast<ByteArray>();
        out->getStream().write(ba->getData(), ba->getSize());
        return new ValueType<int>(ba->getSize());
    }
    static string toString() {return "WriteBinOp";}
};


class IOFunctions {
public:
    static Ob::Ptr finputp;
    static Ob::Ptr foutputp;
    static Ob::Ptr fopenin;
    static Ob::Ptr fopenout;
    static Ob::Ptr fread;
    static Ob::Ptr fwrite;
};
