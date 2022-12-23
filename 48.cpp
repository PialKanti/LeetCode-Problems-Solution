#include <iostream>
#include <vector>
using namespace std;

void tranpose(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void reverse_rows(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            swap(matrix[i][j], matrix[i][n - j - 1]);
        }
    }
}

void print(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void rotate(vector<vector<int>> &matrix)
{
    tranpose(matrix);
    reverse_rows(matrix);
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n, num;
    vector<vector<int>> matrix;
    vector<int> row;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        row.clear();
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            row.push_back(num);
        }
        matrix.push_back(row);
    }

    rotate(matrix);

    return 0;
}