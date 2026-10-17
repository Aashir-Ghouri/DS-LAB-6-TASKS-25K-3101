#include <iostream> //25K-3101
using namespace std;

int nums[5] = {2, 3, 5, 6, 8};
int chosen[5];

bool solve(int i, int sum)
{
    if (sum == 9)
        return true;

    if (i == 5 || sum > 9)
        return false;

    chosen[i] = 1;
    if (solve(i + 1, sum + nums[i]))
        return true;

    chosen[i] = 0;
    if (solve(i + 1, sum))
        return true;

    return false;
}

int main()
{
    if (solve(0, 0))
    {
        cout << "Subset: ";
        for (int i = 0; i < 5; i++)
            if (chosen[i] == 1)
                cout << nums[i] << " ";
        cout << endl;
    }
    else
        cout << "No subset with sum 9 exists." << endl;

    return 0;
}
