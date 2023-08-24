#include<iostream>
#include<stdint.h>
using namespace std;
int lastDigit(int64_t n){
    if(n <= 1)
        return n;
    int fib[n + 2];
    fib[0] = 0, fib[1] = 1;
    for (int i = 2; i < n + 2; i ++)
        fib[i] = (fib[i - 1] + fib[i - 2]) % 10;
    return (fib[n + 1] * fib[n]) % 10;
}
int main(){
    int64_t n;
    cin >> n;
    cout << lastDigit(n);
    return 0;
}