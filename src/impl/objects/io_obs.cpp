#include <impl/objects/io_obs.h>

#include <impl/operations/io_ops.h>
#include <impl/base/operations.h>

namespace stepone { namespace objects {

using namespace base;
using namespace operations;

IOFunctions::IOFunctions() :
    finputp(new FTypeP<FileInputDescriptor>),
    foutputp(new FTypeP<FileOutputDescriptor>),
    fopenin(new FUnaryOp<InputOpenUnOp>),
    fopenout(new FUnaryOp<OutputOpenUnOp>),
    fread(new FBinaryOp<ReadBinOp>),
    fwrite(new FBinaryOp<WriteBinOp>),

    stdin(new StdIn()),
    stdout(new StdOut()),
    stderr(new StdErr())
{}

const IOFunctions &IOFunctions::inst()
{
    static const IOFunctions instance;
    return instance;
}

}} // namespaces
