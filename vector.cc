#include <iostream>
#include <vector>

// pass a pointer instead of a reference:
int smallest_element(std::vector<int>* vec_ptr) {
    auto smallest_value = (*vec_ptr)[0];
    for (auto x : *vec_ptr) 
        if (x < smallest_value) 
            smallest_value = x;
    return smallest_value;
}

int main() {
    std::vector<int> vec;
    for (size_t i = 0; i < 10000000; ++i) {
        vec.push_back(i);
    }

    std::cout << "smallest element of vec is " << smallest_element(&vec)
              << std::endl;

    // Free the memory allocated for the vector
    vec.clear();
    std::vector<int>().swap(vec); // Shrinks the capacity to 0

    return 0;
}
