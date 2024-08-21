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

class Queue
{
    public:
    Node *front;
    Node *rear;
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void push(int data)
    {
        if(front == rear) // you are inserting first element:
        {
            Node *newNode = new Node(data);
            newNode->next = rear;
            rear = newNode;
            front = newNode;
        }
        else
        {
            Node *newNode = new Node(data);
            newNode->next = rear;
            rear = newNode;    
        }

    }

    void pop()
    {
        if(front == NULL)
        {
            cout<<"Queue is empty: ";
        }
        else
        {
            Node* curr = rear;
            Node* prev = NULL;
            while(curr->next!=NULL)
            {
                prev = curr;
                curr = curr->next;
                
            }
            prev->next = curr->next;
            front = prev;
            curr->next = NULL;
            delete curr;
        }   
    }

    int frontt()
    {
        return front->data;
    }
    
    bool isEmpty()
    {
        if(front == rear)
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
    Queue obj;
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(40);
    obj.pop();
    cout<<obj.frontt();

    // if(obj.isEmpty())
    // {
    //     cout<<"Queue is empty";
    // }
    // else
    // {
    //     cout<<"Queue is not empty";
    // }
}