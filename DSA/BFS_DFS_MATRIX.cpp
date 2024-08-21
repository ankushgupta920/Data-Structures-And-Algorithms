#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void breath_first_search(int adj[3][3] , int visited[3] , int start)
{
    int k;
    for(k=0;k<3;k++)
    {
        visited[k] = 0;
    }
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while(!q.empty())
    {
        start  = q.front();
        q.pop();
        printf("%d -->", start); //0 1 0 0 0 1 1 0 0 


        // add neighbours in the queue:
        for(int i = 0; i < 3; i++)
        {
            if(adj[start][i]  &&  visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1; 
            }
        }

    }
}
void depth_first_search(int adj[3][3] , int visited[3] , int start)
{
    int k;
    for(k=0;k<3;k++)
    {
        visited[k] = 0;
    }

    stack<int> s;
    s.push(start);
    visited[start] = 1;

    while(!s.empty())
    {
        start = s.top();
        s.pop();
        printf("%c-", start+65);

        // add neighbours in the stack:
        for(int i = 0; i < 3; i++)
        {
            if(adj[start][i]  &&  visited[i] == 0)
            {
                s.push(i);
                visited[i] = 1;
            }
        }

    }
}
int main()
{
    int visited[3];  //1D array:
    int adj[3][3] , i, j;  //2D array:

    int option,size;

    do
    {
        cout<<endl<<"*****MAIN MENU*****"<<endl;
        cout<<"1. To create graph"<<endl;
        cout<<"2. BFS Traversal"<<endl;
        cout<<"3. DFS Traversal"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<endl<<"Enter your option  : "<<endl;
        cin>>option;

        switch (option)
        {
            case 1: cout<<"Enter the adjacency matrix:"<<endl;
            for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
                {
                    cin>>adj[i][j];
                }
            }
            break;
            case 2: cout<<"BFS Traversal: "<<endl;
            breath_first_search(adj,visited,0);
            break;
        
            case 3: cout<<"DFS Traversal: "<<endl;  
            depth_first_search(adj,visited,0);
            break; 
        } 
    }while(option!=4);
    
    return 0;
}