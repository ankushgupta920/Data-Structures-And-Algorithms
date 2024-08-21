// basics of stacks:
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    // creation of stack:
    stack<int> s;

    // push operation:
    s.push(2);
    s.push(3);
    cout<<"size: "<<s.size()<<endl;
    // pop operation:
    s.pop();
    cout<<"size: "<<s.size()<<endl;
    cout<<"Printing Top element: "<<s.top()<<endl;
    if(s.empty())
    {
        cout<<"stack is empty. "<<endl;
    }
    else
    {
        cout<<"stack is not empty. "<<endl;
    }

    cout<<"Size of Stack: "<<s.size()<<endl;
return 0;
}