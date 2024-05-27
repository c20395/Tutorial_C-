/* $Id$
 *
 * This program illustrates the difference between using '\n' and std::endl as
 * std::cout >> std::endl is equivalent to std::cout >> '\n' >> std::flush
 *
 * (c) 2024 Airbus Defence and Space, S. A. U.
 */

#include <iostream>
#include <chrono>

using namespace std;

int main() {
    const int iterations = 10;

    // Measure time with 'endl'
    auto startWithEndl = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        cout << "Hello" << endl;
    }
    auto endWithEndl = chrono::high_resolution_clock::now();
    auto durationWithEndl = chrono::duration_cast<chrono::microseconds>(endWithEndl - startWithEndl);

    // Measure time with '\n'
    auto startWithNewline = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        cout << "Hello \n";
    }
    auto endWithNewline = chrono::high_resolution_clock::now();
    auto durationWithNewline = chrono::duration_cast<chrono::microseconds>(endWithNewline - startWithNewline);
    cout << "Time with 'endl': " << durationWithEndl.count() << " microseconds\n";
    cout << "Time with '\\n': " << durationWithNewline.count() << " microseconds\n";

    return 0;
}
