#include <iostream>
#include <regex>

int main() {
    // Input text containing the pattern
    std::string text = "C++ is powerful and C++ is fast!";

    // Regular expression pattern to match "C++"
    std::regex pattern("C\\+\\+");

    // Iterator for finding matches in the text
    std::sregex_iterator it(text.begin(), text.end(), pattern);

    // Iterator to represent the end of the matches
    std::sregex_iterator end;

    // Loop through matches and print found instances
    while (it != end) {
        std::cout << "Found: " << it->str() << std::endl;
        ++it;
    }
    return 0;
}
