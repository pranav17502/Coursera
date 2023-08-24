#include<iostream>
#include<algorithm>
#include<stdint.h>
using namespace std;
int64_t maximum_pairwise(int64_t a[], int n){
    int max1 = -1, max2 = -1;
    for (int i = 0; i < n; i++)
        if(max1 == -1 || a[i] > a[max1])
            max1 = i;
    for (int i = 0; i < n; i ++){
        if(max2 == -1) 
            max2 = i;
        if (max1 == max2){
            i++;
            max2++;
        }
        if (a[i] > a[max2] && max1 != i)
                max2 = i;
    }
    int64_t prod = a[max1] * a[max2];
    return prod;
}
int main(){
    int n;
    cin >> n;
    int64_t  a[n];
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    cout << maximum_pairwise(a, n);
    return 0;
}