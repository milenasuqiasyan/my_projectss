#include <iostream>

template <int n>
struct fibonaci {
    static const int s=fibonaci<n-1>::s + fibonaci<n-2>::s;

};

template<>
struct fibonaci<0> {
    static const int s=0;
};

template<> 
struct fibonaci<1>{
    static const int s=1;
};
 
int main() {
    std::cout<<fibonaci<7>::s;
    return 0;
}

