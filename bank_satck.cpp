#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> servedCustomers;

    int tokenNumber;

    // Store 5 recently served customer token numbers
    cout << "Enter 5 recently served customer token numbers:\n";

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter served customer token " << i + 1 << ": ";
        cin >> tokenNumber;

        servedCustomers.push(tokenNumber);
    }

    // Display service history from most recent to oldest
    cout << "\nService History (most recently served first):\n";

    while (!servedCustomers.empty())
    {
        cout << servedCustomers.top() << endl;
        servedCustomers.pop();
    }

    return 0;
}
