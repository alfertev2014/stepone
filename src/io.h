#pragma once

#include "core.h"
#include "bytearray.h"
#include "operations.h"
#include "fstream"

class IOStreamDescriptor : public ValueBase {
public:
    const TypeInfoBase * getTypeInfo() const;
private:
    std::ifstream stream;
public:
    virtual std::iostream &getStream();
    virtual std::istream &getInputStream();
    virtual std::ostream &getOutputStream();
};

class StdIn : public IOStreamDescriptor {
public:
    std::istream &getInputStream();
};

class StdOut : public IOStreamDescriptor {
public:
    std::ostream &getOutputStream();
};

class StdErr : public IOStreamDescriptor {
public:
    std::ostream &getOutputStream();
};

class FileDescriptor : public IOStreamDescriptor {
protected:
    std::fstream stream;
public:
    FileDescriptor(const char * fname, std::ios_base::openmode mode) : stream(fname, mode) {
        if(!stream.is_open())
            throw SemanticError();
    }
    std::iostream &getStream();
    void close();
};

class FileInputDescriptor : public FileDescriptor {
public:
    FileInputDescriptor(const char * fname) : FileDescriptor(fname, std::ios_base::in) {}
    std::istream &getInputStream();
};

class FileOutputDescriptor : public FileDescriptor {
public:
    FileOutputDescriptor(const char * fname) : FileDescriptor(fname, std::ios_base::out | std::ios_base::app) {}
    std::ostream &getOutputStream();
};
