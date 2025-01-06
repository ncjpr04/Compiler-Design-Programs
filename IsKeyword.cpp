#include <iostream>
#include <string>
#include <set>

// List of C++ keywords
const std::set<std::string> cpp_keywords = {
    "alignas", "alignof", "and", "and_eq", "asm", "atomic_cancel", "atomic_commit", "atomic_noexcept",
    "auto", "bitand", "bitor", "bool", "break", "case", "catch", "char", "char8_t", "char16_t", "char32_t",
    "class", "compl", "concept", "const", "consteval", "constexpr", "constinit", "const_cast", "continue",
    "co_await", "co_return", "co_yield", "decltype", "default", "delete", "do", "double", "dynamic_cast",
    "else", "enum", "explicit", "export", "extern", "false", "float", "for", "friend", "goto", "if", 
    "inline", "int", "long", "mutable", "namespace", "new", "noexcept", "not", "not_eq", "nullptr", "operator",
    "or", "or_eq", "private", "protected", "public", "reflexpr", "register", "reinterpret_cast", "requires", 
    "return", "short", "signed", "sizeof", "static", "static_assert", "static_cast", "struct", "switch",
    "synchronized", "template", "this", "thread_local", "throw", "true", "try", "typedef", "typeid", 
    "typename", "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"
};

bool isKeyword(const std::string& str) {
    return cpp_keywords.find(str) != cpp_keywords.end();
}

int main() {
    std::string input;
    std::cout << "Enter a string to check: ";
    std::cin >> input;

    if (isKeyword(input)) {
        std::cout << "'" << input << "' is a C++ keyword." << std::endl;
    } else {
        std::cout << "'" << input << "' is not a C++ keyword." << std::endl;
    }

    return 0;
}
