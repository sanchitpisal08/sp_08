#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Student {
    int rollNo;
    string name;
    string branch;
    string course;
    Student* next;
};

struct HashNode {
    Student* student;
    HashNode* next;
};

class University {
private:
    Student* head;
    HashNode* hashTable[SIZE];

    int hashFunction(int rollNo) {
        return rollNo % SIZE;
    }

public:
    University() {
        head = NULL;

        for (int i = 0; i < SIZE; i++)
            hashTable[i] = NULL;
    }

    // Register New Student
    void registerStudent() {
        int rollNo;
        string name, branch;

        cout << "Enter Roll Number: ";
        cin >> rollNo;

        if (searchStudent(rollNo) != NULL) {
            cout << "Student Already Exists!\n";
            return;
        }

        cout << "Enter Student Name: ";
        getline(cin >> ws, name);

        cout << "Enter Branch: ";
        getline(cin >> ws, branch);

        Student* newStudent = new Student;

        newStudent->rollNo = rollNo;
        newStudent->name = name;
        newStudent->branch = branch;
        newStudent->course = "Not Enrolled";

        newStudent->next = head;
        head = newStudent;

        // Insert into Hash Table
        int index = hashFunction(rollNo);

        HashNode* newNode = new HashNode;
        newNode->student = newStudent;
        newNode->next = hashTable[index];

        hashTable[index] = newNode;

        cout << "Student Registered Successfully!\n";
    }

    // Search Student
    Student* searchStudent(int rollNo) {
        int index = hashFunction(rollNo);

        HashNode* temp = hashTable[index];

        while (temp != NULL) {
            if (temp->student->rollNo == rollNo)
                return temp->student;

            temp = temp->next;
        }

        return NULL;
    }

    // Enroll Student in Course
    void enrollStudent() {
        int rollNo;
        string course;

        cout << "Enter Roll Number: ";
        cin >> rollNo;

        Student* temp = searchStudent(rollNo);

        if (temp == NULL) {
            cout << "Student Not Found!\n";
            return;
        }

        cout << "Enter Course Name: ";
        getline(cin >> ws, course);

        temp->course = course;

        cout << "Student Enrolled Successfully!\n";
    }

    // Search and Display Student
    void search() {
        int rollNo;

        cout << "Enter Roll Number: ";
        cin >> rollNo;

        Student* temp = searchStudent(rollNo);

        if (temp == NULL) {
            cout << "Student Not Found!\n";
            return;
        }

        cout << "\nStudent Details\n";
        cout << "Roll Number: " << temp->rollNo << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Branch: " << temp->branch << endl;
        cout << "Course: " << temp->course << endl;
    }

    // Delete Student
    void deleteStudent() {
        int rollNo;

        cout << "Enter Roll Number: ";
        cin >> rollNo;

        Student* temp = head;
        Student* prev = NULL;

        while (temp != NULL && temp->rollNo != rollNo) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Student Not Found!\n";
            return;
        }

        // Delete from Linked List
        if (prev == NULL)
            head = temp->next;
        else
            prev->next = temp->next;

        // Delete from Hash Table
        int index = hashFunction(rollNo);

        HashNode* h = hashTable[index];
        HashNode* p = NULL;

        while (h != NULL) {
            if (h->student == temp) {
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

        cout << "Student Deleted Successfully!\n";
    }

    // Display All Students
    void display() {
        Student* temp = head;

        if (temp == NULL) {
            cout << "No Student Records Found!\n";
            return;
        }

        cout << "\n===== STUDENT RECORDS =====\n";

        while (temp != NULL) {
            cout << "\nRoll Number: " << temp->rollNo;
            cout << "\nName: " << temp->name;
            cout << "\nBranch: " << temp->branch;
            cout << "\nCourse: " << temp->course << endl;

            temp = temp->next;
        }
    }

    // Destructor
    ~University() {
        while (head != NULL) {
            Student* temp = head;
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
    University u;
    int choice;

    do {
        cout << "\n===== UNIVERSITY STUDENT REGISTRATION SYSTEM =====\n";
        cout << "1. Register New Student\n";
        cout << "2. Enroll Student in Course\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Display All Students\n";
        cout << "6. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            u.registerStudent();
            break;

        case 2:
            u.enrollStudent();
            break;

        case 3:
            u.search();
            break;

        case 4:
            u.deleteStudent();
            break;

        case 5:
            u.display();
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
