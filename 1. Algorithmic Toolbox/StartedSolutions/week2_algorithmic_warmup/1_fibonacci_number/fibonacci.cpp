#include<iostream>
#include<stdint.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n == 0){
        cout << 0;
        return 0;
    }
    if (n == 1){
        cout << 1;
        return 0;
    }
    int64_t fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i ++)
        fib[i] = fib[i - 1] + fib[i - 2];
    cout << fib[n];
    return 0;
}