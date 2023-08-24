#include<iostream>
#include<stdint.h>
using namespace std;
int lastDigitPartialSum(int64_t n, int64_t m){
    if(n <= 1)
        return n;
    int fib[n + 1];
    fib[0] = 0, fib[1] = 1;
    for (int64_t i = 2; i <= n; i++){
        fib[i] = (fib[i - 1] + fib[i - 2]) % 10;
    }
    int lastDig = 0;
    for (int64_t i = m; i <= n; i++){
        lastDig += fib[i];
        lastDig %= 10;
    }
    return lastDig;
}
int main(){
    int64_t n, m;
    cin >> m >> n;
    cout << lastDigitPartialSum(n, m);
    return 0;
}