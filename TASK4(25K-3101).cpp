#include <iostream> //25K-3101
using namespace std;

int savingsApplication(int n){
	if(n == 1){
		return 10;
	}
	
	return 2 * savingsApplication(n-1);
}

int main()
{
    int days;
    cout << "Enter number of days: ";
    cin >> days;

    if (days <= 0)
    {
        cout << "Please enter a positive number of days." << endl;
        return 0;
    }

    cout << "Amount on Day " << days << ": Rs. " << savingsApplication(days) << endl;

    return 0;
}
