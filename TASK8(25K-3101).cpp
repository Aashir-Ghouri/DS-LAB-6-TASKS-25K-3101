#include <iostream> //25K-3101
using namespace std;

char letters[4] = {'A', 'B', 'C', 'D'};
char result[4];
int used[4];

void solve(int pos)
{
    if (pos == 4)
    {
        for (int i = 0; i < 4; i++)
            cout << result[i];
        cout << endl;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (used[i] == 0)
        {
            used[i] = 1;
            result[pos] = letters[i];
            solve(pos + 1);
            used[i] = 0;
        }
    }
}

int main()
{
    solve(0);
    return 0;
}
