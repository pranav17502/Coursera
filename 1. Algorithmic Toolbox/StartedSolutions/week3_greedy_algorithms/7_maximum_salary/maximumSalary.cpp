#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool isBetter(int m,  int n){
    string s = to_string(n);
    int i = 0;
    if ((s[i] - '0') > m)
        return false;
    if((s[i] - '0') < m)
        return true;
    s.erase(s.begin());
    return isBetter(m, stoi(s));
}
string maxSalary(int arr[], int n){
    string salary = "";
    int i = 0;
    while(i < n){
        int maxN = INT16_MIN;
        for (int j = 0; i < n; j ++)
            if(isBetter(arr[j], maxN))
                maxN = arr[j];
        salary.append(to_string(maxN));
        cout << i<<" "<<salary;
        i++;
    }
    return (salary);
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i ++)
        cin >> arr[i];
    cout << maxSalary(arr, n);
    return 0;
}