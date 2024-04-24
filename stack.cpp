#include <iostream>
#define MAX_SIZE 100

using namespace std;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1; // Initialize top of stack
    }

    bool isEmpty() {
        return top == -1; // Check if stack is empty
    }

    bool isFull() {
        return top == MAX_SIZE - 1; // Check if stack is full
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow\n"; // Cannot push if stack is full
            return;
        }
        arr[++top] = value; // Increment top and insert value at top position
        cout << "Pushed " << value << " into the stack\n";
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n"; // Cannot pop if stack is empty
            return -1;
        }
        return arr[top--]; // Return value and decrement top
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n"; // Cannot peek if stack is empty
            return -1;
        }
        return arr[top]; // Return value at top
    }
};

int main() {
    Stack stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);

    cout << "Top element: " << stack.peek() << endl;

    cout << "Popped: " << stack.pop() << endl;
    cout << "Popped: " << stack.pop() << endl;

    cout << "Top element after pops: " << stack.peek() << endl;

    return 0;
}
