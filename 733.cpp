#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <functional>
#include <unordered_set>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int row = image.size();
    int col = image[0].size();
    int rowDir[] = {-1, 0, 0, 1};
    int colDir[] = {0, -1, 1, 0};
    int initialColor = image[sr][sc];

    queue<pair<int, int>> neighbours;
    int visited[50][50];
    memset(visited, 0, sizeof(visited));

    neighbours.push({sr, sc});

    while (!neighbours.empty())
    {
        auto pixel = neighbours.front();
        int x = pixel.first;
        int y = pixel.second;
        neighbours.pop();

        if (!visited[x][y])
        {
            for (int i = 0; i < 4; i++)
            {
                int nX = x + rowDir[i];
                int nY = y + colDir[i];

                if (nX < 0 || nX >= row || nY < 0 || nY >= col)
                    continue;

                if (image[nX][nY] == initialColor)
                {
                    neighbours.push({nX, nY});
                }
            }

            visited[x][y] = 1;
            image[x][y] = color;
        }
    }
    return image;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int m, n, sr, sc, color;
    cin >> m >> n >> sr >> sc >> color;
    vector<vector<int>> image;
    for (int i = 0; i < m; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            row.push_back(num);
        }
        image.push_back(row);
    }

    vector<vector<int>> updatedImage = floodFill(image, sr, sc, color);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}