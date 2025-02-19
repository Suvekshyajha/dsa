#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next =NULL;
    }
};

class linked_list {
private:
    Node* head;

public:
    // Constructor
    linked_list() {
        head =NULL;
    }

    void insert_beginning() {
        cout << "----Insert At the Beginning----" << endl;
        int item;
        cout << "Enter the element you want to enter at the beginning:" << endl;
        cin >> item;
        Node* p = new Node(item);
        p->next = head;
        head = p;
    }

    void insert_end() {
        cout << "----Insert At the End----" << endl;
        int item;
        cout << "Enter the element you want to enter at the end:" << endl;
        cin >> item;
        Node* p = new Node(item);
        if (head == NULL) {
            head = p;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }

    void insert_specific() {
        cout << "----Insert At the Specific Position----" << endl;
        int item, pos;
        cout << "Enter the element you want to insert: ";
        cin >> item;
        cout << "Enter the position where you want to insert the item: ";
        cin >> pos;

        Node* p = new Node(item);

        if (pos == 1) {
            p->next = head;
            head = p;
            return;
        }

        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        if (pos < 1 || pos > count + 1) {
            cout << "Your position index is greater than the list's length!" << endl;
            return;
        }

        temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }

        p->next = temp->next;
        temp->next = p;
    }

    void delete_beginning() {
        cout << "----Delete At the Beginning----" << endl;
        if (head == NULL) {
            cout << "List is empty already!" << endl;
            return;
        } else {
            Node* temp = head;
            head = head->next; // Move head to the next node
            cout << "Item you have deleted is " << temp->data << endl; // Print deleted item
            delete temp; // Free the memory of the deleted node
        }
    }

    void delete_end() {
        cout << "---Delete At the End----" << endl;
        if (head == NULL) {
            cout << "List is empty already!" << endl;
            return;
        } else if (head->next == NULL) { // Only one node in the list
            delete head;
            head = NULL;
            return;
        } else {
            Node* temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            delete temp->next; // Delete the last node
            temp->next = NULL; // Set the next of the second last node to NULL
        }
    }

    void delete_specific() {
        cout << "----Delete At the Specific Position----" << endl;
        if (head == NULL){
		
            cout << "The list is empty! Nothing to delete." << endl;
            return;
        }

        int pos;
        cout << "Enter the index of the item you want to delete:" << endl;
        cin >> pos;
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        if (pos < 1 || pos > count) {
            cout << "Your position index is greater than the list's length!" << endl;
            return;
        }

        if (pos == 1) {
            delete_beginning();
        } else {
            temp = head;
            for (int i = 1; i < pos - 1; i++) {
                temp = temp->next;
            }
            Node* nodeToDelete = temp->next; // Point to the node to delete
            temp->next = temp->next->next; // Bypass the node to delete
            delete nodeToDelete; // Free memory
        }
    }

    void traverse() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl; // Print a new line after traversing the list
    }
};

int main() {
    char ch, opt;
    linked_list obj;
    do {
        cout << "Menu:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Traverse" << endl;
        cout << "Enter your choice (1-3) or 'n' to exit:" << endl;
        cin >> ch;
        switch (ch) {
            case '1': {
                cout << "Insert Menu:" << endl;
                cout << "1. Insert at start" << endl;
                cout << "2. Insert at end" << endl;
                cout << "3. Insert at specific position" << endl;
                cout << "Enter your choice among (1-3):" << endl;
                cin >> opt;
                if (opt == '1') {
                    obj.insert_beginning();
                } else if (opt == '2') {
                    obj.insert_end();
                } else {
                    obj.insert_specific();
                }
                break;
            }
            case '2': {
                cout << "Delete Menu:" << endl;
                cout << "1. Delete at beginning" << endl;
                cout << "2. Delete at end" << endl;
                cout << "3. Delete at specific position" << endl;
                cout << "Enter your choice among (1-3):" << endl;
                cin >> opt;
                if (opt == '1') {
                    obj.delete_beginning();
                } else if (opt == '2') {
                    obj.delete_end();
                } else {
                    obj.delete_specific();
                }
                break;
            }
            case '3':
                obj.traverse();
                break;
            case 'n':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (ch != 'n');
    return 0;
}

