#include<iostream>
using namespace std;
int minStops(int d, int m, int n, int stops[]){
    if(m < stops[0])
        return -1;
    int i = 0;
    int tot_dist = 0;
    while (i <= n){
        if(i == n){
            if(d < m)
                return 0;
            if(d - stops[n-1] < m)
                return 1;
            return -1;
        }
        if (m < stops[i])
        {
            tot_dist = stops[i - 1];
            break;
        }
        i++;
    }
    int nindex = n-i;
    int ss[nindex];
    for (int j = 0; j < nindex; j ++)
        ss[j] = stops[i++] - tot_dist;
    int forward = minStops(d - tot_dist, m, nindex, ss);
    if(forward == -1)
        return -1;
    return 1 + forward;
}
int main(){
    int d, m, n;
    cin >> d >> m >> n;
    int stops[n];
    for (int i = 0; i < n; i ++)
        cin >> stops[i];
    cout << minStops(d, m, n, stops);
    return 0;
}