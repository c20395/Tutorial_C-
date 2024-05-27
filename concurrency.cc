#include <iostream>
#include <thread>
#include <atomic>

// Atomic variable for shared counter
std::atomic<int> counter(0);

// Function to increment the counter
void increment() {
    for (int i = 0; i < 1000000; ++i) {
        // Atomic fetch_add operation to increment counter
        counter.fetch_add(1, std::memory_order_relaxed);
    }
}

int main() {
    // Creating two threads to concurrently increment the counter
    std::thread t1(increment);
    std::thread t2(increment);

    // Waiting for both threads to finish
    t1.join();
    t2.join();

    // Printing the final value of the counter
    std::cout << "Counter: " << counter.load() << std::endl;
    return 0;
}
