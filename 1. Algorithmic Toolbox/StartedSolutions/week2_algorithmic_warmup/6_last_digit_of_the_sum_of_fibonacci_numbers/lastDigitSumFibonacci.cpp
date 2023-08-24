#include<iostream>
#include<stdint.h>
using namespace std;
int lastDigitSum(int64_t n){
    if(n <= 1)
        return n;
    int fibSum[n + 1], fib[n+1];
    fibSum[0] = 0;
    fibSum[1] = 1;
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fib[i] = (fib[i - 1] % 10) + (fib[i - 2] % 10);
        fib[i] %= 10;
        fibSum[i] = (fibSum[i - 1] + fib[i]) % 10;
    }
    return fibSum[n];
}
int main(){
    int64_t n;
    cin>>n;
    cout << lastDigitSum(n);
    return 0;
}