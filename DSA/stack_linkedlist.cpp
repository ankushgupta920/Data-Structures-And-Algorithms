#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
    public:
    Node *top;
    Stack()
    {
        top = NULL;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if(top==NULL)
        {
            cout<<"stack is empty: "<<endl;
        }
        else
        {
            Node* temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
        }
    }

    int peek()
    {
        if(top == NULL)
        {
            cout<<"stack is empty: "<<endl;

        }
        else
        {
            return top->data;
        }
    }
    
    bool isEmpty()
    {
        if(top==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};

int main()
{
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.pop();
    // cout << s1.top->data;
    cout<<s1.peek()<<endl;

    // if(s1.isEmpty())
    // {
    //     cout<<"Stack is empty";
    // }
    // else
    // {
    //     cout<<"stack is not empty";
    // }
}