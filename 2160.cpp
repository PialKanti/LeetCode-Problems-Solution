#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getDigits(int num)
{
    vector<int> digits;
    while (num > 0)
    {
        int digit = num % 10;
        digits.push_back(digit);
        num /= 10;
    }
    return digits;
}

int genNumber(int d1, int d2)
{
    return d1 * 10 + d2;
}

int minimumSum(int num)
{
    vector<int> digits = getDigits(num);
    sort(digits.begin(), digits.end());

    int num1 = genNumber(digits[0], digits[2]);
    int num2 = genNumber(digits[1], digits[3]);

    return num1 + num2;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int num;
    cin >> num;
    cout << minimumSum(num);
}