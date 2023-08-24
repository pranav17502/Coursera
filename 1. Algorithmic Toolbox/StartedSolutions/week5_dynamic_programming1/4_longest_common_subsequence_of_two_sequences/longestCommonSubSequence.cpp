//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
int M = 101;
int N = 101;
vector<vector<int>> LCS(M, vector<int>(N, 0));
vector<int> longestCommonSubsequence(vector<int> a, vector<int> b)
{
    int m = a.size();
    int n = b.size();
    vector<int> result;
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (a[i] == b[j])
                LCS[i][j] = 1 + LCS[i + 1][j + 1];
            else
                LCS[i][j] = max(LCS[i + 1][j], LCS[i][j + 1]);
        }
    }

    // find the sub-sequence
    int i = 0, j = 0;
    vector<int> ss;
    while (i <= m && j <= n)
    {
        if (a[i] == b[j])
        {
            result.push_back(a[i]);
            i++;
            j++;
        }
        else if (LCS[i + 1][j] > LCS[i][j + 1])
            j++;
        else
            j++;
    }
    return result;
}

int main()
{
    vector<int> a, b;
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++){
        int c;
        cin >> c;
        a.push_back(c);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int c;
        cin >> c;
        b.push_back(c);
    }
    vector<int> result = longestCommonSubsequence(a, b);
    cout << result.size();
    cout << endl;
    return 0;
}