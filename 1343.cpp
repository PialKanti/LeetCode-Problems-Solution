#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int numOfSubarrays(vector<int> &arr, int k, int threshold)
{
    int result = 0;
    int sum = 0;
    int limit = threshold * k;
    for (int low = 0, high = 0; high < arr.size(); high++)
    {
        sum += arr[high];
        if (high - low == (k - 1))
        {
            if (sum >= limit)
                result++;

            sum -= arr[low];
            low++;
        }
    }

    return result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int count, k, threshold, num;
    vector<int> arr;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> num;
        arr.push_back(num);
    }

    cin >> k;
    cin >> threshold;

    cout << numOfSubarrays(arr, k, threshold) << endl;
    return 0;
}