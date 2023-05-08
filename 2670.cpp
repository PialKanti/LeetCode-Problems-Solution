#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int getDistinctCount(vector<int> &nums, int start, int end)
{
    unordered_set<int> numSet;
    for (int i = start; i <= end; i++)
    {
        numSet.insert(nums[i]);
    }
    return numSet.size();
}

vector<int> distinctDifferenceArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        int prefixCount = getDistinctCount(nums, 0, i);
        int suffixCount = getDistinctCount(nums, i + 1, n - 1);
        result[i] = prefixCount - suffixCount;
    }
    return result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n, num;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        nums[i] = num;
    }

    vector<int> result = distinctDifferenceArray(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}