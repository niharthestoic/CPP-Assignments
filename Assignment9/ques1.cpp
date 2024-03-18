#include <iostream>
#include <vector>
using namespace std;

class Box
{
private:
    int length;
    int width;
    int height;

public:
    Box() : Box(1, 1, 1) {}
    void setLength(int length)
    {
        this->length = length;
    }
    void setWidth(int width)
    {
        this->width = width;
    }
    void setHeight(int height)
    {
        this->height = height;
    }

    int getLength()
    {
        return this->length;
    }
    int getWidth()
    {
        return this->width;
    }
    int getHeight()
    {
        return this->height;
    }
    Box(int l, int w, int h) : length(l), width(w), height(h) {}
};

void operator>>(istream &in, Box &b1)
{
    int length, width, height;
    cout << "\nEnter length:";
    in >> length;
    cout << "Enter width:";
    in >> width;
    cout << "Enter height:";
    in >> height;
    b1.setLength(length);
    b1.setWidth(width);
    b1.setHeight(height);
}
void operator<<(ostream &out, Box &b1)
{
    out << "\nBox length:" << b1.getLength() << endl;
    out << "Box width:" << b1.getWidth() << endl;
    out << "Box height:" << b1.getHeight() << endl;
}

template <class T>
class Stack
{
    T data;
    vector<T> arr;

public:
    Stack()
    {
    }

    Stack(T data, int size) : data(data)
    {
    }

    void push()
    {
        if (arr.size() == 10)
            cout << "Stack is Full";
        else
        {
            cout << "Enter the Data to be Pushed:";
            cin >> data;
            arr.push_back(data);
        }
    }

    void pop()
    {
        if (arr.size() == 0)
        {
            cout << "Stack is Empty";
        }
        else
        {
            T data;
            data = arr[arr.size() - 1];
            cout << "Pop Data:";
            cout << data;
            cout << endl;
            arr.pop_back();
        }
    }
    void peek()
    {
        if (arr.size() == 0)
        {
            cout << "Stack is Empty";
        }
        else
        {
            T data;
            data = arr[arr.size() - 1];
            cout << "Data at Index:" << arr.size() << " is:";
            cout << data;
            cout << endl;
        }
    }
    void isEmpty()
    {
        if (arr.size() == 0)
            cout << "Stack is Empty" << endl;
        else
            cout << "Stack not Empty" << endl;
    }
    void isFull()
    {
        if (arr.size() == 10)
            cout << "Stack is Full" << endl;
        else
            cout << "Stack not Full" << endl;
    }
    void print()
    {
        if (arr.size() <= 0)
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            for (int i = 0; i < arr.size(); i++)
            {
                cout << "index:" << i << " Data:";
                cout << arr[i];
                cout << endl;
            }
        }
    }
};

// int menu()
// {
//     int ch;
//     cout << "\n::Program Menu::" << endl;
//     cout << "0.Exit" << endl;
//     cout << "1.Push" << endl;
//     cout << "2.Pop" << endl;
//     cout << "3.Peek" << endl;
//     cout << "4.Check if Empty" << endl;
//     cout << "5.Check if Full" << endl;
//     cout << "6. Print Stack" << endl;
//     cout << "Enter Choice:";
//     cin >> ch;
//     return ch;
// }

int main()
{
    Stack<int> stackInt;
    Stack<double> stackDouble;
    Stack<Box> StackBox;
    cout << "Testing isEmpty() Functionality" << endl;
    cout << "\nStack<int>" << endl;
    stackInt.isEmpty();
    cout << "\nStack<double>" << endl;
    stackDouble.isEmpty();
    cout << "\nStack<Box>" << endl;
    StackBox.isEmpty();
    cout << endl;

    cout << "Testing Push() Functionality" << endl;
    cout << "\nStack<int>" << endl;
    for (int i = 0; i < 2; i++)
        stackInt.push();
    cout << "\nStack<double>" << endl;
    for (int i = 0; i < 2; i++)
        stackDouble.push();
    cout << "\nStack<Box>" << endl;
    for (int i = 0; i < 2; i++)
        StackBox.push();
    cout << endl;

    cout << "Testing Print() Functionality" << endl;
    cout << "\nStack<int>" << endl;
    stackInt.print();
    cout << "\nStack<double>" << endl;
    stackDouble.print();
    cout << "\nStack<Box>" << endl;
    StackBox.print();
    cout << endl;

    cout << "Testing Pop() Functionality" << endl;
    cout << "\nStack<int>" << endl;
    stackInt.pop();
    cout << "\nStack<double>" << endl;
    stackDouble.pop();
    cout << "\nStack<Box>" << endl;
    StackBox.pop();
    cout << endl;

    cout << "Testing Peek() Functionality" << endl;
    cout << "\nStack<int>" << endl;
    stackInt.peek();
    cout << "\nStack<double>" << endl;
    stackDouble.peek();
    cout << "\nStack<Box>" << endl;
    StackBox.peek();
    cout << endl;
}

/*Output:
Testing isEmpty() Functionality

Stack<int>
Stack is Empty

Stack<double>
Stack is Empty

Stack<Box>
Stack is Empty

Testing Push() Functionality

Stack<int>
Enter the Data to be Pushed:1
Enter the Data to be Pushed:2

Stack<double>
Enter the Data to be Pushed:1.2
Enter the Data to be Pushed:2.3

Stack<Box>
Enter the Data to be Pushed:
Enter length:1
Enter width:2
Enter height:3
Enter the Data to be Pushed:
Enter length:2
Enter width:3
Enter height:4

Testing Print() Functionality

Stack<int>
index:0 Data:1
index:1 Data:2

Stack<double>
index:0 Data:1.2
index:1 Data:2.3

Stack<Box>
index:0 Data:
Box length:1
Box width:2
Box height:3

index:1 Data:
Box length:2
Box width:3
Box height:4


Testing Pop() Functionality

Stack<int>
Pop Data:2

Stack<double>
Pop Data:2.3

Stack<Box>
Pop Data:
Box length:2
Box width:3
Box height:4


Testing Peek() Functionality

Stack<int>
Data at Index:1 is:1

Stack<double>
Data at Index:1 is:1.2

Stack<Box>
Data at Index:1 is:
Box length:1
Box width:2
Box height:3
*/