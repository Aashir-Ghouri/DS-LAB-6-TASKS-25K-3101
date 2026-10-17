#include <iostream> //25K-3101
using namespace std;

int sumOfDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return (n % 10) + sumOfDigits(n / 10);
}

int main()
{
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;

    cout << "Sum of digits: " << sumOfDigits(number) << endl;

    return 0;
}
