#include <iostream>
#include <vector>
using namespace std;

class Stack
{
public:
    int capacity;
    int *arr;
    int idx = -1;

    Stack(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int x)
    {
        if (idx == capacity - 1)
        {
            cout << "Stack is full" << endl;
            return;
        }
        arr[++idx] = x;
    }

    void printStack()
    {
        for (int i = 0; i <= idx; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void pop()
    {
        if (idx == -1)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        idx--;
    }
    void top()
    {
        if (idx == -1)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << arr[idx] << endl;
    }
    void size(){
        if(idx == -1){
            cout << "Stack is empty" << endl;
            return;
        }
        cout << idx + 1 << endl;
    }
};

int main()
{
    Stack s(3);
    s.push(10);
    s.push(20);
    s.push(30);
    s.printStack();
    s.pop();
    s.printStack();
    s.size();
}