#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int sum = (n * (n + 1)) / 2;

    for (int i = 0; i < n; i++)
    {
        sum -= nums[i];
    }

    return sum;
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

    cout << missingNumber(nums);
    return 0;
}