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
    if (a > b)
        cout << gcd(b, a);
    else if (a < b)
        cout << gcd(a, b);
    else
        cout << a;
    return 0;
}