#include<iostream>
#include<stdint.h>
using namespace std;
long long hugeFib(long long n, long long m){
    if(n <= 1)
        return n;
    long long prev = 0, curr = 1;
    for (int i = 2; i <= n; i ++){
        long long tp = prev;
        prev = curr;
        curr = curr + tp;
    }
        return curr%m;
}
int main(){
    long long n;
    long long m;
    cin >> n >> m;
    cout<<hugeFib(n, m);
    return 0;
}