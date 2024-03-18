#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;
    int top;
    int size;

public:
    
    Stack(int stackSize = 5) {
        size = stackSize;
        arr = new int[size];
        top = -1;
    }

    
    ~Stack() {
        delete[] arr;
    }

    // Function to push element onto stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }

    // Function to pop element from stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1; 
        }
        return arr[top--];
    }

    // 
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1; 
        }
        return arr[top];
    }

    // Function to check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to check if stack is full
    bool isFull() {
        return top == size - 1;
    }

    // Function to print the elements of the stack
    void print() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Create a stack of size 5
    Stack stack(5);

    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    
    stack.push(60);

    // Print stack elements
    stack.print();

    // Pop elements from the stack
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Popped element: " << stack.pop() << endl;

    // Peek at the top element
    cout << "Top element: " << stack.peek() << endl;

    // Print stack elements after popping
    stack.print();

    return 0;
}
