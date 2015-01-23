#pragma once

#include "core.h"
#include "bytearray.h"
#include "operations.h"
#include "fstream"

class IOStreamDescriptor : public Value {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<IOStreamDescriptor>::instance;}
    static string getTypeString() {return "IOStreamDescriptor";}
private:
    ifstream stream;
public:
    virtual iostream &getStream() {throw SemanticError();}
    virtual istream &getInputStream() {throw SemanticError();}
    virtual ostream &getOutputStream() {throw SemanticError();}
};

class StdIn : public IOStreamDescriptor {
public:
    istream &getInputStream() {return cin;}
};

class StdOut : public IOStreamDescriptor {
public:
    ostream &getOutputStream() {return cout;}
};

class StdErr : public IOStreamDescriptor {
public:
    ostream &getOutputStream() {return cerr;}
};

class FileDescriptor : public IOStreamDescriptor {
protected:
    fstream stream;
public:
    FileDescriptor(const char * fname, ios_base::openmode mode) : stream(fname, mode) {
        if(!stream.is_open())
            throw SemanticError();
    }
    iostream &getStream() {return stream;}
    void close() {stream.close();}
};

class FileInputDescriptor : public FileDescriptor {
public:
    FileInputDescriptor(const char * fname) : FileDescriptor(fname, ios_base::in) {}
    istream &getInputStream() {return stream;}
};

class FileOutputDescriptor : public FileDescriptor {
public:
    FileOutputDescriptor(const char * fname) : FileDescriptor(fname, ios_base::out | ios_base::app) {}
    ostream &getOutputStream() {return stream;}
};

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


class IOFunctions {
    IOFunctions();
public:
    static const IOFunctions &inst();

    const Ob::Ptr finputp;
    const Ob::Ptr foutputp;
    const Ob::Ptr fopenin;
    const Ob::Ptr fopenout;
    const Ob::Ptr fread;
    const Ob::Ptr fwrite;

    const Ob::Ptr stdin;
    const Ob::Ptr stdout;
    const Ob::Ptr stderr;
};
