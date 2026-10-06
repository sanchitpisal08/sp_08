```cpp
#include<iostream>
using namespace std;

int main()
{
    int choice;
    int token = 1;
    int tokens[100];
    int count = 0;

    do
    {
        cout << "\n\n==== BOOK TOKEN SYSTEM ====";
        cout << "\n1. Issue Token";
        cout << "\n2. Display All Tokens";
        cout << "\n3. Serve a Customer";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            tokens[count] = token;
            cout << "Token issued successfully!";
            cout << "\nYour token number is: " << token;

            token++;
            count++;
        }

        else if (choice == 2)
        {
            if (count == 0)
            {
                cout << "No tokens available!";
            }
            else
            {
                cout << "All Tokens: ";

                for (int i = 0; i < count; i++)
                {
                    cout << tokens[i] << " ";
                }
            }
        }

        else if (choice == 3)
        {
            if (count == 0)
            {
                cout << "No customers to serve!";
            }
            else
            {
                cout << "Serving Customer with Token Number: "
                     << tokens[0];

                // Move remaining tokens forward
                for (int i = 0; i < count - 1; i++)
```
