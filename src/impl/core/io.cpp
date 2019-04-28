#include <impl/core/io.h>

#include <iostream>

namespace stepone::core {

std::iostream &IOStreamDescriptor::getStream() {throw SemanticError();}

std::istream &IOStreamDescriptor::getInputStream() {throw SemanticError();}

std::ostream &IOStreamDescriptor::getOutputStream() {throw SemanticError();}

std::istream &StdIn::getInputStream() {return std::cin;}

std::ostream &StdOut::getOutputStream() {return std::cout;}

std::ostream &StdErr::getOutputStream() {return std::cerr;}

std::iostream &FileDescriptor::getStream() {return stream;}

void FileDescriptor::close() {stream.close();}

std::istream &FileInputDescriptor::getInputStream() {return stream;}

std::ostream &FileOutputDescriptor::getOutputStream() {return stream;}

} // namespaces
