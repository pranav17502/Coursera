#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
bool has_max(vector<int>& arr){
    unordered_map<int, int> freq;
    for(int num : arr){
        freq[num] += 1;
        if(freq[num] > arr.size()/2)
            return true;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    if(has_max(arr))
        cout << 1;
    else
        cout << 0;
    return 0;
}