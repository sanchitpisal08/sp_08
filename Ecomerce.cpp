#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Product {
    int productID;
    string name;
    string category;
    float price;
    int quantity;
    Product* next;
};

struct HashNode {
    Product* product;
    HashNode* next;
};

class ECommerce {
private:
    Product* head;
    HashNode* hashTable[SIZE];

    // Hash Function
    int hashFunction(int id) {
        return id % SIZE;
    }

public:
    ECommerce() {
        head = NULL;

        for (int i = 0; i < SIZE; i++)
            hashTable[i] = NULL;
    }

    // Search Product
    Product* searchProduct(int id) {
        int index = hashFunction(id);

        HashNode* temp = hashTable[index];

        while (temp != NULL) {
            if (temp->product->productID == id)
                return temp->product;

            temp = temp->next;
        }

        return NULL;
    }

    // Add New Product
    void addProduct() {
        Product* newProduct = new Product;

        cout << "Enter Product ID: ";
        cin >> newProduct->productID;

        if (searchProduct(newProduct->productID) != NULL) {
            cout << "Product ID Already Exists!\n";
            delete newProduct;
            return;
        }

        cout << "Enter Product Name: ";
        getline(cin >> ws, newProduct->name);

        cout << "Enter Category: ";
        getline(cin >> ws, newProduct->category);

        cout << "Enter Price: ";
        cin >> newProduct->price;

        cout << "Enter Quantity: ";
        cin >> newProduct->quantity;

        // Insert into Linked List
        newProduct->next = head;
        head = newProduct;

        // Insert into Hash Table using Chaining
        int index = hashFunction(newProduct->productID);

        HashNode* newNode = new HashNode;
        newNode->product = newProduct;
        newNode->next = hashTable[index];

        hashTable[index] = newNode;

        cout << "Product Added Successfully!\n";
    }

    // Update Product Details
    void updateProduct() {
        int id;

        cout << "Enter Product ID: ";
        cin >> id;

        Product* temp = searchProduct(id);

        if (temp == NULL) {
            cout << "Product Not Found!\n";
            return;
        }

        cout << "Enter New Product Name: ";
        getline(cin >> ws, temp->name);

        cout << "Enter New Category: ";
        getline(cin >> ws, temp->category);

        cout << "Enter New Price: ";
        cin >> temp->price;

        cout << "Enter New Quantity: ";
        cin >> temp->quantity;

        cout << "Product Updated Successfully!\n";
    }

    // Search Product
    void search() {
        int id;

        cout << "Enter Product ID: ";
        cin >> id;

        Product* temp = searchProduct(id);

        if (temp == NULL) {
            cout << "Product Not Found!\n";
            return;
        }

        cout << "\nProduct Details\n";
        cout << "Product ID: " << temp->productID << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Category: " << temp->category << endl;
        cout << "Price: " << temp->price << endl;
        cout << "Quantity: " << temp->quantity << endl;
    }

    // Remove Product
    void removeProduct() {
        int id;

        cout << "Enter Product ID: ";
        cin >> id;

        Product* temp = head;
        Product* prev = NULL;

        while (temp != NULL && temp->productID != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Product Not Found!\n";
            return;
        }

        // Delete from Linked List
        if (prev == NULL)
            head = temp->next;
        else
            prev->next = temp->next;

        // Delete from Hash Table
        int index = hashFunction(id);

        HashNode* h = hashTable[index];
        HashNode* p = NULL;

        while (h != NULL) {
            if (h->product == temp) {

                if (p == NULL)
                    hashTable[index] = h->next;
                else
                    p->next = h->next;

                delete h;
                break;
            }

            p = h;
            h = h->next;
        }

        delete temp;

        cout << "Product Removed Successfully!\n";
    }

    // Display All Products
    void displayProducts() {
        Product* temp = head;

        if (temp == NULL) {
            cout << "No Products Available!\n";
            return;
        }

        cout << "\n===== PRODUCT CATALOG =====\n";

        while (temp != NULL) {
            cout << "\nProduct ID: " << temp->productID;
            cout << "\nName: " << temp->name;
            cout << "\nCategory: " << temp->category;
            cout << "\nPrice: " << temp->price;
            cout << "\nQuantity: " << temp->quantity << endl;

            temp = temp->next;
        }
    }

    // Destructor
    ~ECommerce() {
        while (head != NULL) {
            Product* temp = head;
            head = head->next;
            delete temp;
        }

        for (int i = 0; i < SIZE; i++) {
            while (hashTable[i] != NULL) {
                HashNode* temp = hashTable[i];
                hashTable[i] = hashTable[i]->next;
                delete temp;
            }
        }
    }
};

int main() {
    ECommerce e;
    int choice;

    do {
        cout << "\n===== E-COMMERCE PRODUCT INVENTORY SYSTEM =====\n";
        cout << "1. Add New Product\n";
        cout << "2. Update Product Details\n";
        cout << "3. Search Product\n";
        cout << "4. Remove Product\n";
        cout << "5. Display All Products\n";
        cout << "6. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            e.addProduct();
            break;

        case 2:
            e.updateProduct();
            break;

        case 3:
            e.search();
            break;

        case 4:
            e.removeProduct();
            break;

        case 5:
            e.displayProducts();
            break;

        case 6:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}
