#include <iostream> //25K-3101
using namespace std;

char grid[3][3] = {
    {'C', 'A', 'X'},
    {'B', 'T', 'A'},
    {'D', 'E', 'T'}
};

int used[3][3];
char word[4] = "CAT";

bool solve(int r, int c, int idx)
{
    if (r < 0 || r >= 3 || c < 0 || c >= 3)
        return false;

    if (used[r][c] == 1 || grid[r][c] != word[idx])
        return false;

    if (idx == 2)
        return true;

    used[r][c] = 1;

    if (solve(r, c + 1, idx + 1) ||
        solve(r, c - 1, idx + 1) ||
        solve(r + 1, c, idx + 1) ||
        solve(r - 1, c, idx + 1))
        return true;

    used[r][c] = 0;
    return false;
}

int main()
{
    bool found = false;

    for (int i = 0; i < 3 && !found; i++)
        for (int j = 0; j < 3 && !found; j++)
            if (solve(i, j, 0))
                found = true;

    if (found)
        cout << "Word CAT exists." << endl;
    else
        cout << "Word CAT does not exist." << endl;

    return 0;
}
