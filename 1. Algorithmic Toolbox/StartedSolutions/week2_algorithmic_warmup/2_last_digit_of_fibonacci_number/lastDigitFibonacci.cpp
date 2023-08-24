#include<iostream>
using namespace std;
int lastDigit(int n){
    if(n == 0)
        return 0;
    if ( n == 1)
        return 1;
    int fib[n+1];
    fib[0] = 0, fib[1] = 1;
    for (int i = 2; i <= n; i++){
        fib[i] = (fib[i - 1] % 10) + (fib[i - 2] % 10);
        fib[i] %= 10;
    }
    return fib[n];
}
int main(){
    int n;
    cin >> n;
    cout << lastDigit(n);
    return 0;
}