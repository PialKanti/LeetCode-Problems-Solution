#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> distinctDifferenceArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n);
    unordered_map<int, int> prefixMap;
    unordered_map<int, int> suffixMap;

    for (int i = 0; i < n; i++)
    {
        suffixMap[nums[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        prefixMap[nums[i]]++;
        suffixMap[nums[i]]--;
        if (suffixMap[nums[i]] == 0)
        {
            suffixMap.erase(nums[i]);
        }

        result[i] = prefixMap.size() - suffixMap.size();
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