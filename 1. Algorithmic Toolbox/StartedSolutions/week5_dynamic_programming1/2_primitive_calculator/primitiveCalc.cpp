// C++ program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to generate
// the minimum sequence
void find_sequence(int n)
{

    // Stores the values for the
    // minimum length of sequences
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));

    // Base Case
    dp[1] = 1;

    // Loop to build up the dp[]
    // array from 1 to n
    for (int i = 1; i < n + 1; i++)
    {
        if (dp[i] != 0)
        {

            // If i + 1 is within limits
            if (i + 1 < n + 1 &&
                (dp[i + 1] == 0 ||
                 dp[i + 1] > dp[i] + 1))
            {

                // Update the state of i + 1
                // in dp[] array to minimum
                dp[i + 1] = dp[i] + 1;
            }

            // If i * 2 is within limits
            if (i * 2 < n + 1 &&
                (dp[i * 2] == 0 ||
                 dp[i * 2] > dp[i] + 1))
            {

                // Update the state of i * 2
                // in dp[] array to minimum
                dp[i * 2] = dp[i] + 1;
            }

            // If i * 3 is within limits
            if (i * 3 < n + 1 &&
                (dp[i * 3] == 0 ||
                 dp[i * 3] > dp[i] + 1))
            {

                // Update the state of i * 3
                // in dp[] array to minimum
                dp[i * 3] = dp[i] + 1;
            }
        }
    }

    // Generate the sequence by
    // traversing the array
    vector<int> sequence;
    while (n >= 1)
    {

        // Append n to the sequence
        sequence.push_back(n);

        // If the value of n in dp
        // is obtained from n - 1:
        if (dp[n - 1] == dp[n] - 1)
        {
            n--;
        }

        // If the value of n in dp[]
        // is obtained from n / 2:
        else if (n % 2 == 0 &&
                 dp[(int)floor(n / 2)] == dp[n] - 1)
        {
            n = (int)floor(n / 2);
        }

        // If the value of n in dp[]
        // is obtained from n / 3:
        else if (n % 3 == 0 &&
                 dp[(int)floor(n / 3)] == dp[n] - 1)
        {
            n = (int)floor(n / 3);
        }
    }

    // Print the sequence
    // in reverse order
    reverse(sequence.begin(), sequence.end());

    // Print the length of
    // the minimal sequence
    cout << sequence.size() -1<< endl;
    for (int i = 0; i < sequence.size(); i++)
    {
        cout << sequence[i]  << " ";
    }
}

// Driver code
int main()
{

    // Given Number N
    int n;
    cin >> n;

    // Function Call
    find_sequence(n);

    return 0;
}

// This code is contributed by divyeshrabadiya07
