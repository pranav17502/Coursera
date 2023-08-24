#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector <int32_t> psec;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}
int minPoints(vector<pair<int32_t, int32_t>> points, int n){
    if(n <= 1){
        psec.push_back(points[0].second);
        return 1;
    }
    sort(points.begin(), points.end(), sortbysec);
    int i = 1;
    psec.push_back(points[0].second);
    while (true){
        if(i == n)
            return 1;
        if (points[0].second < points[i].first)
            break;
        i++;
    }
    vector<pair<int32_t, int32_t>> p2(points.begin() + i, points.end());
    return 1 + minPoints(p2, n - i);
}
int main(){
    int n;
    cin >> n;
    vector<pair<int32_t, int32_t>> points;
    for (int i = 0;  i < n; i++){
        int32_t l, r;
        cin >> l >> r;
        points.push_back(make_pair(l, r));
    }
    cout << minPoints(points, n)<<endl;
    for (int i = 0; i < psec.size(); i ++)
        cout << psec[i] << " ";
    return 0;
}