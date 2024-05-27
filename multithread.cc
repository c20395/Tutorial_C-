#include <iostream>
#include <thread>

// Function to be executed in a separate thread
void printNumbers() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread 1: " << i << std::endl;
    }
}

int main() {
    // Creating a thread and associating it with the function 'printNumbers'
    std::thread t1(printNumbers);
    
    // The main thread waits for 't1' to finish its execution
    t1.join();
    return 0;
}
