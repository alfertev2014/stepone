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
