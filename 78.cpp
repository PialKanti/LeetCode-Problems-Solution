#include <iostream>
#include <vector>
using namespace std;

void generate(int index, vector<int> subset, vector<int> nums, vector<vector<int>> &result)
{
    result.push_back(subset);
    for (int i = index; i < nums.size(); i++)
    {
        subset.push_back(nums[i]);
        generate(i + 1, subset, nums, result);
        subset.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> result;
    generate(0, {}, nums, result);
    return result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    vector<vector<int>> result = subsets(nums);
    cout << result.size() << endl;
}