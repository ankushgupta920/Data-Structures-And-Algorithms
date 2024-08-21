// 2 Stacks in an Array:
#include<iostream>
using namespace std;
class Twostack
{
    public:
    int *arr;
    int top1;
    int top2;
    int size;

    Twostack(int size)
    {
        this->size=size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    // push in Stack1:
    void push1(int element)
    {
        // atleast a empty space should be present:
        if(top2-top1>1)
        {
            top1++;
            arr[top1] = element;
        }
        else
        {
            cout<<"Stack Overflow "<<endl;
        }
    }

    // push in Stack2:
    void push2(int element)
    {
        // atleast a empty space should be present:
        if(top2-top1>1)
        {
            top1--;
            arr[top2] = element;
        }
        else
        {
            cout<<"Stack Overflow "<<endl;
        }
    }

    // Pop from Stack 1:
    void pop1()
    {
        // atleast a one element should be present:
        if(top1>=0)
        {
            top1--;
        }
        else
        {
            cout<<"Stack Underflow "<<endl;
        }
    }

    // Pop from Stack 2:
    void pop2()
    {
        // atleast a one element should be present:
        if(top2<size)
        {
            top2++;
        }
        else
        {
            cout<<"Stack Underflow "<<endl;
        }
    }

};
int main()
{
    Twostack obj(10);
    obj.push1(10);
    obj.push1(20);
    obj.push2(50);
    obj.push2(40);

return 0;
}