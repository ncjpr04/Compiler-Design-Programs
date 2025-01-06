#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

const std::unordered_set<std::string> cpp_operators = {
    "+", "-", "*", "/", "%", "=", "+=", "-=", "*=", "/=", "%=",
    "==", "!=", "<", ">", "<=", ">=", "&&", "||", "!", 
    "++", "--", "&", "|", "^", "~", "<<", ">>", "<<=", ">>=",
    "[]", "()", "->", ".", "::", "?:", ",", ".*", "->*",
    "&=", "|=", "^=", "...", "<=>"
};

int countOperators(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file!" << std::endl;
        return -1;
    }

    std::string content;
    char ch;
    int operatorCount = 0;
    
    while (file.get(ch)) {
        content += ch;
    }

    for (size_t i = 0; i < content.length(); i++) {
        std::string potentialOp;
        
        // Check for multi-character operators
        for (int j = 0; j < 3 && i + j < content.length(); j++) {
            potentialOp += content[i + j];
            if (cpp_operators.find(potentialOp) != cpp_operators.end()) {
                operatorCount++;
                i += j;  // Skip the characters we've already counted
                break;
            }
        }
    }

    file.close();
    return operatorCount;
}

int main() {
    std::string filePath;
    std::cout << "Enter the path to the file: ";
    std::getline(std::cin, filePath);

    int count = countOperators(filePath);
    if (count >= 0) {
        std::cout << "Total number of operators: " << count << std::endl;
    }

    return 0;
}