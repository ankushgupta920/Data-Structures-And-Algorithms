// Singly linked list:
#include<iostream>
#include<map>
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
void inseartAtHead(Node* &head,int d)
{
    // creating a new node as head of linked list:
    Node* temp = new Node(d);
    temp->next=head;
    head = temp;
}
void inseartAttail(Node* &tail,int d)
{
    Node* temp = new Node(d);
    tail->next=temp;
    tail=temp;

}
void deleteNode(int pos,Node* &head,Node* &tail)
{
    // deleting first or start node:
    if(pos==1)
    {
        Node* temp = head;
        head = head->next;
        // memory free start node:
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle or last node:
        Node* cur = head;
        Node* prev = NULL;
        int i=1;
        while(i<pos)
        {
            prev=cur;
            cur=cur->next;
            i++;
        }
        prev->next=cur->next;
        cur->next = NULL;
        delete cur;
        if(prev->next==NULL)
        {
            tail=prev;
        }
        
    }
}
void inseartAtposition(Node* &tail,Node* &head,int pos,int d)
{
    // insert at start:
    if(pos==1)
    {
        inseartAtHead(head,d);
        return; 
    }

    Node* temp = head;
    int i=1;

    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }

    // inserting at last:
    if(temp->next == NULL)
    {
        inseartAttail(tail,d);
        return;
    }
    
    // creating a node for d(for new position):
    Node* nodeToinseart = new Node(d);
    nodeToinseart->next = temp->next;
    temp->next = nodeToinseart;
}
void findmax(Node* &head)
{
    
    Node* temp = head;
    Node* max = temp;
    temp=max;
    while(temp!=NULL)
    {
        if(temp->data>max->data)
        {
            max=temp;
        }
        temp=temp->next;
        
    }
    cout<<"Max:"<<max->data<<endl;
}
Node* ReverseLinkedlist(Node* head)
{
    // In case of empty list:
    if(head==NULL || head->next==NULL)
    {
        cout<<head;
    }
    Node* prev = NULL;
    Node* cur = head;
    while(cur!=NULL)
    {
        Node* forword = cur->next;
        cur->next = prev;
        prev = cur;
        cur = forword;
    }
    return prev;
    // if(cur==NULL)
    // {
    //     prev=head;
    // }
}
bool detectLoop(Node* head)
{
    if(head==NULL)
    {
        return false;
    }
    map<Node* , bool> visited;

    Node* temp = head;

    while(temp!=NULL)
    {
        // cycle is present:
        if(visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;

}
Node* floydDetectLoop(Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while(slow!=NULL && fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast)
        {
            return slow;
        }
    }
    return NULL;
}
Node* getStartingNode(Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* intersection = floydDetectLoop(head);
    Node* slow = head;
    while(slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

void removeLoop(Node* head)
{
    if(head==NULL)
    {
        return;
    }
    Node* startofLoop = getStartingNode(head);
    Node* temp = startofLoop;
    while(temp->next != startofLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
void print(Node* &head)
{
    if(head==NULL)
    {
        cout<<"List is empty: "<<endl;
        return;
    }
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int getlength(Node* &head)
{
    int len=0;
    Node* temp = head;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    return len;
}
void checkPrime(Node* &head, Node* &tail)
{
    Node* temp = head;
    int i,sum=0;
    while(temp!=NULL)
    {
        int count=0;
        for(i=1;i<=tail->data;i++)
        {
            if(temp->data%i==0)
            {
                count++; 
            }
        }
        if(count==2)
        {
            cout<<"Prime Number: "<<temp->data<<" "<<endl;
            sum = sum + temp->data;

        }
        temp=temp->next;
    }
    cout<<"Sum of Prime Numbers in Linked list: "<<sum<<endl;
}
int main(){
    // creating node1:
    Node* node1 = new Node(5);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    Node* head = node1;
    Node* tail=node1;
    print(head);
    inseartAtHead(head,10);
    print(head);
    inseartAttail(tail,15);
    print(head);

    inseartAtposition(tail,head,3,20);
    print(head);

    checkPrime(head,tail);
    // cout<<"Head:"<<head->data<<endl;
    // cout<<"Tail:"<<tail->data<<endl;
    // deleteNode(4,head,tail);
    // print(head);
    // cout<<"Head:"<<head->data<<endl;
    // cout<<"Tail:"<<tail->data<<endl;
    // findmax(head);
    // print(head);
    // ReverseLinkedlist(head);
    // print(head);
    // findmax(head);
    // print(head);
    // tail -> next = head -> next;
    // cout<<"Head:"<<head->data<<endl;
    // cout<<"Tail:"<<tail->data<<endl;
    // if(detectLoop(head))
    // {
    //     cout<<"cycle is present "<<endl;
    // }
    // else
    // {
    //     cout<<"cycle is not present "<<endl;
    // }


    // if(floydDetectLoop(head))
    // {
    //     cout<<"cycle is present "<<endl;
    // }
    // else
    // {
    //     cout<<"cycle is not present "<<endl;
    // }
    
    // Node* loop = getStartingNode(head);
    // cout<<"loops starts at "<<loop->data<<endl;

    // removeLoop(head);
    // print(head);
return 0;
}