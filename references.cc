#include <iostream>
#include <vector>
#include <algorithm>  /* Use for_each and lambda functions */

#if __cplusplus < 201103L
#error "C++11 or better required\n"
#endif

using namespace std;

template < class T > void
swap (T & a, T & b) { /* Using copies of vectors (naive solution) */
    T aux = a;
    a = b;
    b = aux;
    return;
}

template <class T> void swap_move(T& a,T& b) { /* Just exchanges references */
    T aux=std::move(a);
    a=std::move(b);
    b=std::move(aux);
    return;
}

template < class T > void
print_vector (T & v) {
    for (auto item:v) {
        cout << item << endl;
    }
    return;
}

template <class T> void print_vector_lambdas(T& v) {
    auto print=[](const int& item) {
        std::cout << item << std::endl;
    };
    std::for_each(v.begin(),v.end(),print);
    return;
}

int
main () {
    vector < int >v {1, 2, 3}, w {4, 5};

    cout << "Vector V (Before swapping)" << endl;
    print_vector (v);

    cout << "Vector W (Before swapping)" << endl;
    print_vector (w);

    swap_move (v, w);

    cout << "Vector V (After swapping)" << endl;
    print_vector_lambdas (v);

    cout << "Vector W (After swapping)" << endl;
    print_vector_lambdas (w);

    return 0;
}
