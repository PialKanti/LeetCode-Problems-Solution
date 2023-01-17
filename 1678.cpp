#include <iostream>
#include <string>
using namespace std;

string interpret(string command)
{
    string result = "";
    for (int i = 0; i < command.size();)
    {
        if (command[i] == '(' && command[i + 1] == ')')
        {
            result += 'o';
            i += 2;
        }
        else if (command[i] == '(' && command[i + 1] == 'a' && command[i + 2] == 'l' && command[i + 3] == ')')
        {
            result += "al";
            i += 4;
        }
        else
        {
            result += command[i];
            i++;
        }
    }

    return result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    string n;
    cin >> n;
    cout << interpret(n);
    return 0;
}