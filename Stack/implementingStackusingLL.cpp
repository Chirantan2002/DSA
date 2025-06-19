#include <iostream>
using namespace std;

class Stack
{
public:
    int data;
    Stack *next;
    Stack(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
Stack *top = nullptr;
void push(int data)
{
    if (top == nullptr)
    {
        top = new Stack(data);
    }
    else
    {
        Stack *temp = new Stack(data);
        temp->next = top;
        top = temp;
    }
}
void pop()
{
    if (top == nullptr)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    else
    {
        Stack *temp = top;
        top = top->next;
        delete temp;
    }
}
void display()
{
    Stack *temp = top;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void printTop()
{
    if (top == nullptr)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    else
    {
        cout << top->data << endl;
    }
}
void size()
{
    Stack *temp = top;
    int count = 0;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    cout << count << endl;
}
void empty()
{
    if (!top)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    else
    {
        cout << "Stack is not empty" << endl;
        return;
    }
}

int main()
{
    Stack s(10);
    push(20);
    push(30);
    push(40);
    display();
    pop();
    display();
    printTop();
    size();
    empty();
}