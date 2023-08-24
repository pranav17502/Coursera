#include<iostream>
using namespace std;
int64_t gcd(int64_t a, int64_t b){
    if(a == 0)
        return b;
    return gcd(b % a, a);
}
int main(){
    int64_t a, b;
    cin >> a >> b;
    if(a == b){
        cout << a;
        return 0;
    }
    int64_t gc = (a > b) ? gcd(b, a) : gcd(a, b);
    cout << (a / gc) * b;
    return 0;
}