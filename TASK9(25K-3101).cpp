#include <iostream> //25K-3101
using namespace std;

int g[4][4] = {
    {1, 0, 0, 4},
    {0, 4, 1, 0},
    {0, 1, 4, 0},
    {4, 0, 0, 1}
};

bool isSafe(int r, int c, int n)
{
    for (int i = 0; i < 4; i++)
        if (g[r][i] == n || g[i][c] == n)
            return false;

    int sr = r / 2 * 2;
    int sc = c / 2 * 2;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (g[sr + i][sc + j] == n)
                return false;

    return true;
}

bool solve(int pos)
{
    if (pos == 16)
        return true;

    int r = pos / 4;
    int c = pos % 4;

    if (g[r][c] != 0)
        return solve(pos + 1);

    for (int n = 1; n <= 4; n++)
        if (isSafe(r, c, n))
        {
            g[r][c] = n;
            if (solve(pos + 1))
                return true;
            g[r][c] = 0;
        }

    return false;
}

int main()
{
    if (solve(0))
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
                cout << g[i][j] << " ";
            cout << endl;
        }
    }
    else
        cout << "No solution exists." << endl;

    return 0;
}
