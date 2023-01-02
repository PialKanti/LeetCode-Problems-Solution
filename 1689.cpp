#include <iostream>
#include <string>
using namespace std;

int minPartitions(string n)
{
    int result = 0;
    int digit;
    for (int i = 0; i < n.size(); i++)
    {
        digit = (int)(n[i] - '0');
        result = max(result, digit);
    }
    return result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    string n;
    cin >> n;
    cout << minPartitions(n);
    return 0;
}