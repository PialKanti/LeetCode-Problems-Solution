#include <iostream>
#include <vector>
using namespace std;

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    int maxCandies = 0;
    for (int i = 0; i < candies.size(); i++)
    {
        maxCandies = max(maxCandies, candies[i]);
    }

    vector<bool> result(candies.size());
    for (int i = 0; i < candies.size(); i++)
    {
        if (candies[i] + extraCandies >= maxCandies)
        {
            result[i] = true;
        }
        else
        {
            result[i] = false;
        }
    }
    return result;
}