#include <iostream> //25K-3101
#include <string>
using namespace std;

void printReverse(string s, int index)
{
    if (index < 0)
    {
        return;
    }

    cout << s[index];
    printReverse(s, index - 1);
}

int main()
{
    string message;
    cout << "Enter a message: ";
    getline(cin, message);

    cout << "Reversed: ";
    printReverse(message, message.length() - 1);
    cout << endl;

    return 0;
}
