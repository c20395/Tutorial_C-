/* $Id$
 * This snipped shows how to find out the size of arrays using C++ references
 * and it is useful for numerical analysis algorithms.
 *
 * Note that the reference of an array includes also the number of arguments
 * T (&r)[N] means "r is a reference to an array of T-type N elements".
 */

#if (__cplusplus < 201103L) // Uses ISO C++11 Standard
#error This source code is valid for ISO C++ 2011 and onwards
#endif

#include <iostream>

template <class T,int N> void f(T(&r)[N]) {
    int index=0;
    for (auto item:r)
        std::cout << "Index " << index++ << " value "<< item  << std::endl;
    return;
}

int main() {
    int a1[10]= {1,2,3,4,5,6,7,8,9,10};
    double a2[5]= {0.1,0.2,0.3,0.4,0.5};

    f(a1);
    f(a2);
    return 0;
}
