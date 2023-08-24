#include<iostream>
using namespace std;
int binarySearch(int arr[], int l, int h, int key){
    if(l > h)
        return -1;
    int m = l + (h - l) / 2;
    if(arr[m] == key)
        return m;
    int ans = (arr[m] > key) ? binarySearch(arr, l, m - 1, key) : binarySearch(arr, m + 1, h, key);
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i ++)
        cin >> arr[i];
    int m;
    cin>>m;
    int keys[m];
    for(int i = 0 ; i < m ; i ++)
        cin >> keys[i];
    for(int i = 0 ; i < m ; i ++)
        cout << binarySearch(arr, 0, n, keys[i]) << " ";
    return 0;
}