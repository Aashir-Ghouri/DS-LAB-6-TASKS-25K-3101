#include <iostream> //25K-3101
#include <string>
using namespace std;

int graph[4][4] = {
    {0, 1, 1, 0},
    {1, 0, 1, 1},
    {1, 1, 0, 1},
    {0, 1, 1, 0}
};

int color[4] = {0, 0, 0, 0};
string deptName[4] = {"A", "B", "C", "D"};
string colorName[4] = {"", "Red", "Green", "Blue"};

bool isSafe(int dept, int col)
{
    for (int i = 0; i < 4; i++)
    {
        if (graph[dept][i] == 1 && color[i] == col)
        {
            return false;
        }
    }
    return true;
}

bool solve(int dept)
{
    if (dept == 4)
    {
        return true;
    }

    for (int col = 1; col <= 3; col++)
    {
        if (isSafe(dept, col))
        {
            color[dept] = col;

            if (solve(dept + 1))
            {
                return true;
            }

            color[dept] = 0;
        }
    }

    return false;
}

int main()
{
    if (solve(0))
    {
        for (int i = 0; i < 4; i++)
        {
            cout << "Department " << deptName[i] << " -> " << colorName[color[i]] << endl;
        }
    }
    else
    {
        cout << "No valid coloring exists." << endl;
    }

    return 0;
}
