#include<iostream>
#include<vector>
using namespace std;
vector<int> optimal_summands(int n)
{
    // using the algorithm described in the pdf
    vector<int> summands;
    for (int k = n, l = 1; k > 0; l++)
    {
        if (k <= 2 * l)
        {
            summands.push_back(k);
            k -= k;
        }
        else
        {
            summands.push_back(l);
            k -= l;
        }
    }
    return summands;
}
int main()
{
    int32_t n;
    cin >> n;
    vector<int> points = optimal_summands(n);
    cout << points.size() << endl;
    for (int i = 0; i < points.size(); i++)
        cout << points[i] << " ";
    return 0;
}