#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Item
{
    int value, weight;

    // Constructor
    Item(int value, int weight)
        : value(value), weight(weight)
    {
    }
};

// Comparison function to sort Item
// according to val/weight ratio
bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(struct Item arr[],
                          int N, int size)
{
    // Sort Item on basis of ratio
    sort(arr, arr + size, cmp);

    // Current weight in knapsack
    int curWeight = 0;

    // Result (value in Knapsack)
    double finalvalue = 0.0;

    // Looping through all Items
    for (int i = 0; i < size; i++)
    {

        // If adding Item won't overflow,
        // add it completely
        if (curWeight + arr[i].weight <= N)
        {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }

        // If we can't add current Item,
        // add fractional part of it
        else
        {
            int remain = N - curWeight;
            finalvalue += arr[i].value * ((double)remain / arr[i].weight);

            break;
        }
    }

    // Returning final value
    return finalvalue;
}
int main(){
    int n;
    double tot_weight;
    cin>>n>>tot_weight;
    double arr[n][2];
    for (int i = 0; i < n; i ++)
        cin >> arr[i][0] >> arr[i][1];
    cout << fractionalKnapsack(arr, tot_weight, n);
    return 0;
}