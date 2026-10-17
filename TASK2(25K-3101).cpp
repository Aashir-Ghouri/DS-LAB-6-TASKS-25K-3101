#include <iostream> //25K-3101
using namespace std;

void printRange(int n)
{
    if (n <= 0)
    {
        return;
    }

    printRange(n - 1);
    cout << n << " ";
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    printRange(n);
    cout << endl;

    return 0;
}
