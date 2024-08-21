#include<iostream>
#include<queue>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* &root) //with recursive method:
{
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;
    root = new Node(data);

    if(data == -1)
    {
        return NULL;
    }
    cout<<"Enter data for inserting in Left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in Right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void buildFromlevelOrder(Node* &root)  //without recursive method:
{
    queue<Node*> q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root = new Node(data);  
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        cout<<"Enter left node for: "<< temp->data <<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for: "<< temp->data <<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}
void levelOrderTraversal(Node* &root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);  //separater:

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<< temp->data <<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
            // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
        }
    }
}

void inOrder(Node* &root)
{
    // base case:
    if(root == NULL)
    {
        return; 
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}

void preOrder(Node* &root)
{
    // base case:
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

}

void postOrder(Node* &root)
{
    // base case:
    if(root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";

}
bool present(int element, Node* &root)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp->data == element)
        {
            cout<< temp->data <<" ";
            return true;

        }
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
            // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
        
    }
    return false;
}

int countNodes(Node* &root)
{
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}


int main(){
    Node* root = NULL;

    root = buildTree(root);  //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<"Printing the level Order traversal output "<<endl;
    levelOrderTraversal(root);

    // if(present(11,root))
    // {
    //     cout<<"element is present: "<<endl;
    // }
    // else
    // {
    //     cout<<"element is not present: "<<endl;
    // }

    cout<<"Printing postorder: ";
    postOrder(root);
    
    // buildFromlevelOrder(root);
    // cout<<countNodes(root);
   
return 0;
}

