#include<iostream>
using namespace std;
class queue
{
    public:
    int *arr;
    int size;
    int front;
    int rear;
    int check;

    queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
        check = 0;
    }

    void push(int element)
    {
        if(rear == size)
        {
            cout<<"Queue is Full : "<<endl;
        }
        else
        {
            arr[rear] = element;
            rear++;
        }
    }

    void pop()
    {
        if(front == rear)
        {
            cout<<"No element present: "<<endl;
        }
        else
        {
            arr[front] = -1;
            front++;
            if(front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    int frontt()
    {
        if(front == rear)
        {
            cout<<"No element present: "<<endl;
            return -1;
        }
        else
        {
            return arr[front];
            
        }
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

    void present(int element)
    {
        if(check == element)
        {
            cout<<"Element is present in the queue "<<endl;
        }
        else
        {
            while(check != element)
            {
                check++;
            }
            if(check == element)
            {
                cout<<"Element is present in the queue "<<endl;
            }
            else
            {
                cout<<"Element is not present in the queue "<<endl;
            }
            
        }

    }
};


int main(){
    queue obj(5);
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(40);
    
    cout<<obj.frontt()<<endl;
    obj.pop();
    obj.pop();
    if(obj.isEmpty())
    {
        cout<<"Queue is empty mera dost. "<<endl;
    }
    else
    {
        cout<<"Queue is not empty mera dost. "<<endl;
    }
    obj.pop();
    obj.pop();
    if(obj.isEmpty())
    {
        cout<<"Queue is empty mera dost. "<<endl;
    }
    else
    {
        cout<<"Queue is not empty mera dost. "<<endl;
    }
return 0;
}