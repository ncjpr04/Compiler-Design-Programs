#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <sstream>

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

int countKeywords(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file!" << std::endl;
        return -1;
    }

    std::string word;
    int keywordCount = 0;

    // Read each word from the file
    while (file >> word) {
        // Check if the word is a keyword
        if (cpp_keywords.find(word) != cpp_keywords.end()) {
            keywordCount++;
        }
    }

    file.close();
    return keywordCount;
}

int main() {
    std::string filePath;
    std::cout << "Enter the file path: ";
    std::cin >> filePath;

    int keywordCount = countKeywords(filePath);
    if (keywordCount >= 0) {
        std::cout << "Total number of keywords in the file: " << keywordCount << std::endl;
    }

    return 0;
}
