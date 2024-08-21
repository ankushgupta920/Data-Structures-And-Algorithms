#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }

};
void inseartNode(Node* &tail,int element,int d)
{
    // empty list:
    if(tail==NULL)
    {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next=newNode;
    }
    else
    {
        // non-empty list:-
        // assuming that the element is present in the list:
        Node* cur = tail;
        while(cur->data != element)
        {
            cur=cur->next;
        }
        // element found:
        Node* temp = new Node(d);
        temp->next = cur->next;
        cur->next=temp;
    }
}
void inseartNodeBefore(Node *&tail, int element, int d)
{
    // empty list:
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node *cur = tail;
        while (cur->next->data != element)
        {
            cur = cur->next;
        }
        // element found:
        Node *temp = new Node(d);
        temp->next = cur->next;
        cur->next = temp;
    }
}
void print(Node* &tail)
{
    Node* temp = tail;
    do
    {
        cout<<tail->data<<" ";
        tail=tail->next;
    } while (tail != temp);
    cout<<endl;
    
}
bool isCircular(Node* head)
{
    // empty list:
    if(head==NULL)
    {
        return true;
    }
    Node* temp = head->next;
    while(temp!=NULL && temp!=head)
    {
        temp=temp->next;

    }
    if(temp==head)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(){

    Node* tail = NULL;
    // empty list me insert krre hai:
    // inseartNode(tail,10,2);
    // print(tail);

    if((isCircular(tail)))
    {
        cout<<"LL is circular in nature :"<<endl;
    }
    else
    {
        cout<<"LL is not circular in nature :"<<endl;
    }
    
   
    
return 0;
}