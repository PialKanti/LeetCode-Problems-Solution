#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int count = 0, result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
            count++;
        else
        {
            result = max(result, count);
            count = 0;
        }
    }

    result = max(result, count);

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

    cout << findMaxConsecutiveOnes(nums) << endl;
    return 0;
}