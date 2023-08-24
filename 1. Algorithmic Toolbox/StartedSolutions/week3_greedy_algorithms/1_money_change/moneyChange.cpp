#include<iostream>
using namespace std;
int coins(int money){
    if(money == 0)
        return 0;
    int largest = 0;
    if(money < 5)
        largest = 1;
    else if (money < 10)
        largest = 5;
    else
        largest = 10;
    return 1 + coins(money - largest);
}
int main(){
    int money;
    cin >> money;
    cout << coins(money);
    return 0;
}
