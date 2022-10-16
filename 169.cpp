#include <iostream>
#include <vector>
#include <map>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int majority = nums[0];
    map<int, int> frequency;

    for (int i = 0; i < nums.size(); i++)
    {
        frequency[nums[i]]++;
        if (frequency[nums[i]] > frequency[majority])
        {
            majority = nums[i];
        }
    }

    return majority;
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

    cout << majorityElement(nums) << endl;
    return 0;
}