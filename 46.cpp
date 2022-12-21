#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <sstream>
using namespace std;

void generate(int index, vector<int> nums, vector<vector<int>> &result)
{
    if (index >= nums.size() - 1)
    {
        result.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        generate(index + 1, nums, result);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> result;
    generate(0, nums, result);
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

    vector<vector<int>> result = permute(nums);
    cout << result.size() << endl;
}