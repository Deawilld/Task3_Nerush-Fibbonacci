#include <iostream>

//This is how it's supposed to be
//Still couldn't actually compile this with g++ with the parameter more than 30

template<int n>
inline constexpr long long int fibonacci_template(){
    return fibonacci_template<n-1>() + fibonacci_template<n-2>();
}

template<>
inline constexpr long long int fibonacci_template<0>(){
    return 0;
}

template<>
inline constexpr long long int fibonacci_template<1>(){
    return 1;
}

int main(){
    constexpr long long int a = fibonacci_template<30>();
    std::cout << a << std::endl;
}
