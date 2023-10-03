#include <gtest/gtest.h>

#include <ptr_impl.h>

using namespace stepone;
using namespace stepone::core;

TEST(CompilationInfo,SiteOfTypes) {
    std::cout << "sizeof Ob = " << sizeof(Ob) << std::endl;
    std::cout << "sizeof Ptr = " << sizeof(Ptr) << std::endl;

    std::cout << "sizeof core::Pair = " << sizeof(Pair) << std::endl;
    std::cout << "sizeof core::Symbol = " << sizeof(Symbol) << std::endl;
    std::cout << "sizeof core::Lazy = " << sizeof(Lazy) << std::endl;
    std::cout << "sizeof core::Label = " << sizeof(Label) << std::endl;
    std::cout << "sizeof core::Evaluator = " << sizeof(Evaluator) << std::endl;
    std::cout << "sizeof core::BaseMacro = " << sizeof(BaseMacro) << std::endl;
    std::cout << "sizeof core::MacroClosure = " << sizeof(MacroClosure) << std::endl;
    std::cout << "sizeof core::CurrentContext = " << sizeof(CurrentContext) << std::endl;
    std::cout << "sizeof core::Vector = " << sizeof(Vector) << std::endl;
    std::cout << "sizeof core::ByteArray = " << sizeof(ByteArray) << std::endl;
    std::cout << "sizeof core::Value<double> = " << sizeof(Value<double>) << std::endl;
    std::cout << "sizeof core::Value<long> = " << sizeof(Value<long>) << std::endl;
    std::cout << "sizeof core::Value<char> = " << sizeof(Value<char>) << std::endl;
}
