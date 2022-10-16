#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> dict;
    vector<int> result(2);

    for (int i = 0; i < nums.size(); i++)
    {
        int key = target - nums[i];
        if (dict.find(key) != dict.end())
        {
            result[0] = i;
            result[1] = dict[key];
            return result;
        }
        dict[nums[i]] = i;
    }
    return result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n, num;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        nums.push_back(num);
    }

    int target;
    cin >> target;

    vector<int> result = twoSum(nums, target);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}