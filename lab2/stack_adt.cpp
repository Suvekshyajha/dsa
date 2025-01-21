#include<iostream>
#define max 3
using namespace std;

class stack {
    int stack[max];
    int top = -1;

public:
    bool isfull() {
        return top == max - 1;
    }

    bool isempty() {
        return top == -1;
    }

    void makeempty() {
        top = -1;
        cout << "stack has been emptied" << endl;
    }

    void push() {
        if (isfull()) {
            cout << "the stack is already full. Can't push more elements." << endl;
        } else {
            cout << "Enter a number: ";
            top++;
            cin >> stack[top];
        }
    }

    void pop() {
        if (isempty()) {
            cout << "The stack is empty, so can't perform pop operation." << endl;
        } else {
            cout << "Element popped: " << stack[top] << endl;
            top--;
        }
    }

    void traverse() {
        if (isempty()) {
            cout << "There are no elements to display as the stack is empty." << endl;
        } else {
            for (int i = 0; i <= top; ++i) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }

    void peek() {
        if (isempty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Element on top is: " << stack[top] << endl;
        }
    }
};

int main() {
    stack obj;
    char ch;
    do {
        cout << "Menu:" << endl;
        cout << "1. Make an empty stack" << endl;
        cout << "2. Push" << endl;
        cout << "3. Pop" << endl;
        cout << "4. Traverse" << endl;
        cout << "5. Peek" << endl;
        cout << "Enter your choice among (1-5) or 'n' to exit: ";
        cin >> ch;
        
        switch (ch) {
            case '1': {
                cout << "Empty stack operation:" << endl;
                obj.makeempty();
                break;
            }
            case '2': {
                cout << "Push operation:" << endl;
                obj.push();
                break;
            }
            case '3': {
                cout << "Pop operation:" << endl;
                obj.pop();
                break;
            }
            case '4': {
                cout << "Traverse elements:" << endl;
                obj.traverse();
                break;
            }
            case '5': {
                cout << "Peek operation:" << endl;
                obj.peek();
                break;
            }
            case 'n': {
                cout << "Exiting.........." << endl;
                break;
            }
            default: {
                cout << "Enter among the given choices only." << endl;
                break;
            }
        }
    } while (ch != 'n');

    return 0;
}

