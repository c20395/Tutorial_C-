#include <iostream>

# This code is borrowed from ChatGPT and explains the use of double
# and universal references introduced by ISO C++ 2011 Standard

// Function accepting a lvalue-reference
void process(int& lref) {
    std::cout << "Lvalue reference: " << lref << std::endl;
}

// Function accepting a rvalue-reference
void process(int&& rref) {
    std::cout << "Rvalue reference: " << rref << std::endl;
}

// Template with universal reference
template<typename T>
void universal(T&& ref) {
    process(std::forward<T>(ref));  // std::forward preserves reference type (lvalue or rvalue)
}

int main() {
    int a = 5;
    universal(a);        // call to process(int&)
    universal(10);       // call to  process(int&&)
    universal(std::move(a));  // call to process(int&&)
    return 0;
}
