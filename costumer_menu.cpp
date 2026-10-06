
#include<iostream>
using namespace std;

int main()
{
    int choice;

    do
    {
        cout << "\n\n==== RESTAURANT MENU ====";
        cout << "\n1. Pizza";
        cout << "\n2. Burger";
        cout << "\n3. Pasta";
        cout << "\n4. Sandwich";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "You selected Pizza!";
        }

        else if (choice == 2)
        {
            cout << "You selected Burger!";
        }

        else if (choice == 3)
        {
            cout << "You selected Pasta!";
        }

        else if (choice == 4)
        {
            cout << "You selected Sandwich!";
        }

        else if (choice == 5)
        {
            cout << "Thank you for visiting!";
        }

        else
        {
            cout << "Invalid Choice!";
        }

    } while (choice != 5);

    return 0;
}

