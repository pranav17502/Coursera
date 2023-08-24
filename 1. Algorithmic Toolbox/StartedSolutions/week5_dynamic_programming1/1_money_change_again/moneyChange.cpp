#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCoins(int amount, const vector<int> &coins)
{
    vector<int> dp(amount + 1, INT_MAX); // Initialize dp table with large values
    dp[0] = 0;                                // Base case: 0 coins needed to make change for 0 amount

    for (int i = 1; i <= amount; ++i)
    {
        for (int coin : coins)
        {
            if (coin <= i && dp[i - coin] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount];
}

int main()
{
    int amount;
    cin >> amount;
    vector<int> coins = {1, 3, 4};

    int minCoinCount = minCoins(amount, coins);

    cout << minCoinCount << endl;

    return 0;
}
