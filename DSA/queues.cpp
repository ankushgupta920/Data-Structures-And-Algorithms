#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    q.push(5);
    q.push(10);
    q.push(20);

    cout<<"size of queue is: "<<q.size()<<endl;

    q.pop();
    q.pop();
    q.pop();
    cout<<"size of queue is: "<<q.size()<<endl;

    if(q.empty())
    {
        cout<<"Queue is empty: "<<endl;
    }
    else
    {
        cout<<"Queue is not empty: "<<endl;
    }

return 0;
}   