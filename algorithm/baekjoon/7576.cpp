#include <iostream>
#include <queue>

using namespace std;

#define xAxis first
#define yAxis second

int box[1001][1001];

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    queue<pair<int, int>> tomato;

    int width, height;
    cin >> width >> height;

    for (int x = 0; x < 1001; x++)
    {
        for(int y = 0; y < 1001; y++)
            box[x][y] = -1; 
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            cin >> box[x][y];

            if (box[x][y] == 1)
                tomato.push({x, y});
        }
    }

    int count, day = 0;
    while (!tomato.empty())
    {
        count = tomato.size();
        while (count--)
        {
            pair<int, int> single = tomato.front();
            int x = single.xAxis, y = single.yAxis;

            if (width > x + 1 && box[x + 1][y] == 0)
            {
                box[x + 1][y] = 1;
                tomato.push({x + 1, y});
            }

            if (x - 1 >= 0 && box[x - 1][y] == 0)
            {
                box[x - 1][y] = 1;
                tomato.push({x - 1, y});
            }

            if (height > y + 1 && box[x][y + 1] == 0)
            {
                box[x][y + 1] = 1;
                tomato.push({x, y + 1});
            }

            if (y - 1 >= 0 && box[x][y - 1] == 0)
            {
                box[x][y - 1] = 1;
                tomato.push({x, y - 1});
            }

            tomato.pop();
        }
        day++;
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
           //  cout << box[x][y] << " ";
            if(box[x][y] == 0)
            {
                cout << "-1";
                return 0;
            }
        }

        // cout << "\n";
    }

    cout << day - 1;

    return 0;
}