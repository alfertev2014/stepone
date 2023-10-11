#include <gtest/gtest.h>

#include <ptr_impl.h>

using namespace stepone;
using namespace stepone::types;

TEST(CompilationInfo,SiteOfTypes) {
    std::cout << "sizeof Ob = " << sizeof(Ob) << std::endl;
    std::cout << "sizeof Ptr = " << sizeof(Ptr) << std::endl;

    std::cout << "sizeof types::Pair = " << sizeof(Pair) << std::endl;
    std::cout << "sizeof types::Symbol = " << sizeof(Symbol) << std::endl;
    std::cout << "sizeof types::Evaluator = " << sizeof(Evaluator) << std::endl;
    std::cout << "sizeof types::BaseMacro = " << sizeof(BuiltInMacro) << std::endl;
    std::cout << "sizeof types::MacroClosure = " << sizeof(MacroClosure) << std::endl;
    std::cout << "sizeof types::Vector = " << sizeof(Vector) << std::endl;
    std::cout << "sizeof types::ByteArray = " << sizeof(ByteArray) << std::endl;
    std::cout << "sizeof types::Value<double> = " << sizeof(Value<double>) << std::endl;
    std::cout << "sizeof types::Value<long> = " << sizeof(Value<long>) << std::endl;
    std::cout << "sizeof types::Value<char> = " << sizeof(Value<char>) << std::endl;
}
