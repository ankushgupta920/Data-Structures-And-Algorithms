#include<iostream>
using namespace std;
class Stack
{
    // properties:
    public:
    int *arr;
    int top;
    int size;

    // behaviour:
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if(size-top>1)
        {
            top++;
            arr[top]= element;
        }
        else
        {
            cout<<"Stack Overflow "<<endl;
        }

    }
    void pop()
    {
        if(top>=0)
        {
            top--;
        }
        else
        {
            cout<<"Stack Underflow "<<endl;
        }
    }
    int peek()
    {
        if(top>=0)
            return arr[top];
        else
        {
            cout<<"Stack is Empty "<<endl;
            return -1;
        }
    }
    bool isEmpty()
    {
        if(top==-1)
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

    Stack obj(5);
    obj.push(22);
    obj.push(44);
    obj.push(50);
    obj.push(22);
    obj.push(44);
    obj.push(50);

    cout<<obj.peek()<<endl;

    obj.pop();
    cout<<obj.peek()<<endl;

    obj.pop();
    cout<<obj.peek()<<endl;

    obj.pop();
    cout<<obj.peek()<<endl;


    if(obj.isEmpty())
    {
        cout<<"Stack is empty mera dost"<<endl;
    }
    else
    {
        cout<<"Stack is not empty mera dost"<<endl;
    }

return 0;
}   