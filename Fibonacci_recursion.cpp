#include<iostream>
using namespace std;


long long fibo(long long n) {
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    else {
        
        return (fibo(n - 2) + fibo(n - 1));
    
    }
}

int main() {
    long long n;
    cout << "please, enter the number" << endl;
    cin >> n;
    if (n > 2) {
        cout << fibo(n) << endl;
    }
    else {
        cout << "facepalm" << endl;
    }
    return 0;
}
