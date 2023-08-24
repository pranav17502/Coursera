#include <iostream>
using namespace std;
int binarySearchDuplicates(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int result = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            result = mid;
            high = mid - 1; // Look for the first occurrence to the left
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return result;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int m;
    cin >> m;
    int keys[m];
    for (int i = 0; i < m; i++)
        cin >> keys[i];
    for (int i = 0; i < m; i++)
        cout << binarySearchDuplicates(arr, n, keys[i]) << " ";
    return 0;
}