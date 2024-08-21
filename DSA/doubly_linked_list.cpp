#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};
void insertAthead(Node* &head,int d)
{
    // creating new node:
    Node* temp = new Node(d);
    temp->next=head;
    head->prev=temp;
    head = temp;
}
void inseartAttail(Node* &tail,int d)
{
    // creating a new node:
    Node* temp = new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail = temp;
}
void inseartAtposition(Node* &head,Node* &tail,int pos,int d)
{
    if(pos==1)
    {
        insertAthead(head,d);
        return;
    }
    Node* temp = head;
    int i=1;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    if(temp==NULL)
    {
        inseartAttail(tail,d);
        return;
    }
    // creating a new node:
    Node* nodetoinseart = new Node(d);
    nodetoinseart->next=temp->next;
    temp->next->prev=nodetoinseart;
    temp->next=nodetoinseart;
    nodetoinseart->prev=temp;
}
void deletenode(int pos,Node* &head,Node* &tail)
{
    if(pos==1)
    {
        // delete first or start node:
        Node* temp = head;
        temp->next->prev = NULL;
        head=head->next;
        // memory free:
        temp->next=NULL;
        delete temp;
    }
    else
    {
        // delete middle or last node:
        Node* cur = head;
        Node* prev = NULL;
        int i=1;
        while(i<pos)
        {
            prev = cur;
            cur=cur->next;
            i++;
        }
        cur->prev=NULL;
        prev->next=cur->next;
        cur->next=NULL;
        delete cur;
        if(prev->next==NULL)
        {
            tail=prev;
        }
    }
}
void print(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    Node* node1 = new Node(5);
    Node* head = node1;
    Node* tail = node1;
    insertAthead(head,10);
    print(head);
    inseartAttail(tail,20);
    print(head);
    deletenode(2,head,tail);
    print(head);
return 0;
}