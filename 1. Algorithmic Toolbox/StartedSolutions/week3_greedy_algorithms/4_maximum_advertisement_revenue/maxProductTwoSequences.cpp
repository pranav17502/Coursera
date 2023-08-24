#include<iostream>
#include<algorithm>
using namespace std;
int maxPrice(int n, int prices[],int clicks[]){
    if(n==1)
        return prices[0] * clicks[0];
    sort(prices, prices + n);
    sort(clicks, clicks + n);
    int maxP = 0;
    for (int i = 0; i < n; i++)
        maxP += prices[i] * clicks[i];
    return maxP;
}

int main()
{
    int n;
    cin >> n;
    int prices[n], clicks[n];
    for (int i = 0; i < n;i++)
        cin >> prices[i];
    for (int i = 0; i < n; i++)
        cin >> clicks[i];
    cout << maxPrice(n, prices, clicks);
    return 0;
}
