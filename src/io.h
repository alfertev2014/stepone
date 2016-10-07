#pragma once

#include "core.h"
#include "bytearray.h"
#include "operations.h"
#include "fstream"

class IOStreamDescriptor : public ValueBase {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<IOStreamDescriptor>::instance;}
private:
    std::ifstream stream;
public:
    virtual std::iostream &getStream() {throw SemanticError();}
    virtual std::istream &getInputStream() {throw SemanticError();}
    virtual std::ostream &getOutputStream() {throw SemanticError();}
};

class StdIn : public IOStreamDescriptor {
public:
    std::istream &getInputStream() {return std::cin;}
};

class StdOut : public IOStreamDescriptor {
public:
    std::ostream &getOutputStream() {return std::cout;}
};

class StdErr : public IOStreamDescriptor {
public:
    std::ostream &getOutputStream() {return std::cerr;}
};

class FileDescriptor : public IOStreamDescriptor {
protected:
    std::fstream stream;
public:
    FileDescriptor(const char * fname, std::ios_base::openmode mode) : stream(fname, mode) {
        if(!stream.is_open())
            throw SemanticError();
    }
    std::iostream &getStream() {return stream;}
    void close() {stream.close();}
};

class FileInputDescriptor : public FileDescriptor {
public:
    FileInputDescriptor(const char * fname) : FileDescriptor(fname, std::ios_base::in) {}
    std::istream &getInputStream() {return stream;}
};

class FileOutputDescriptor : public FileDescriptor {
public:
    FileOutputDescriptor(const char * fname) : FileDescriptor(fname, std::ios_base::out | std::ios_base::app) {}
    std::ostream &getOutputStream() {return stream;}
};
