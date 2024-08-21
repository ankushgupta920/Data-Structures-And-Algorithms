#include<iostream>
using namespace std;
class Circularqueue
{
    public:
    int size;
    int *arr;
    int front;
    int rear;

    Circularqueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int element)
    {
        // Check if Queue is Full or Not:
        if((front == 0 && rear == size-1) || (rear == (front-1) % (size-1)))
        {
            cout<<"Queue is Full : ";
        }
        else if(front == -1) // When you are inserting the first element:
        {
            front = 0;
            rear = 0;
            arr[rear] = element;
        }
        else if(rear == size-1 && front != 0) // Jb tumhara rear last per hota hai.
        {
            rear  = 0;
            arr[rear] = element;
        }
        else // For normal case:
        {
            rear++;
            arr[rear] = element;
        }
    }

    void pop()
    {
        // Check for Queue is empty or not:
        if(front == -1)
        {
            cout<<"Queue is Empty : ";
        }
        arr[front] = -1;
        if(front == rear)
        {
            front = rear = 1;
        }
        else if(front == size -1)
        {
            front = 0;
        }
        else
        {
            front++;

        }

    }
    int frontt()
    { 
        // HW
        return arr[front];
    }
};
int main(){
    Circularqueue obj(5);
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(40);
    obj.push(50);
    obj.pop();
    obj.push(60);
    cout<<obj.frontt()<<endl;
return 0;
}