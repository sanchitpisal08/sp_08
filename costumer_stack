include <iostream>
#include <stack>
using namespace std;

int main()
 {
    stack<int> canceledOrders;

    int orderNumber;

    // Store 5 canceled order numbers
    cout << "Enter 5 canceled order numbers:\n";

    for (int i = 0; i < 5; i++)
{

        cout<<"enter cancelled order"<<i+1<<":";
        cin >> orderNumber;

        canceledOrders.push(orderNumber);
    }

    // Display canceled orders from most recent to oldest
    cout << "\nCanceled orders (recently canceled first):\n";

    while (!canceledOrders.empty())
 {
        cout << canceledOrders.top() << endl;
        canceledOrders.pop();
    }

    return 0;
}

