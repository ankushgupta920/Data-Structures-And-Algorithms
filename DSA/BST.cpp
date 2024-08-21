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
Node* insertIntoBTS(Node* &root,int d)
{
    // base case:
    if(root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if(d > root->data)
    {
        root->right = insertIntoBTS(root->right,d);
    }
    else
    {
        root->left = insertIntoBTS(root->left,d);
    }
    return root;
}

void takeInput(Node* &root)
{
    int data;
    cin>>data;

    while(data != -1)
    {
        root = insertIntoBTS(root,data);
        cin>>data;
    }
}
Node* MinValue(Node* &root)
{
    Node* temp = root;

    while(temp->left != NULL)
    {
        temp = temp->left; 
    }
    return temp;
}

Node* deletefromBST(Node* &root , int element)
{
    // base case:(If the tree is empty)
    if(root == NULL)
    {
        return root;
    }
    if(root->data == element)
    {
        // 0 child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child:
        // left  child:
        if(root->left !=  NULL && root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // right child:
        if(root->right !=  NULL && root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child:
        if(root->left != NULL && root->right != NULL)
        {
            int mini = MinValue(root->right) -> data;
            root->data = mini;
            root->right = deletefromBST(root->right , mini);
            return root;
        }
    }
    else if(root->data > element)
    {
        // left part me jao
        root->left = deletefromBST(root->left , element);
        return root;
    }
    else
    {
        // right part me jao
        root->right = deletefromBST(root->right , element);
        return root;
    }
}
bool present(int element , Node* &root) // in recursion 
{
    // base case:
    if(root == NULL)
    {
        return false;
    }

    if(root->data == element)
    {
        return true;
    }

    if(root->data > element)
    {
        // left part me:
        return present(element , root->left);
    }
    else
    {
        // right part:
        return present(element , root->right);
    }
}

bool elementPresent(int element , Node* &root)  //without recursion:
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
        if(temp->data > element)
        {
            q.push(temp->left);
        }
        if(temp->data < element)
        {
            q.push(temp->right);
        }
        
    }
    return false;
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
        }
    }
}

void inOrder(Node* &root)  //sorted order:
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

Node* MaxValue(Node* &root)
{
    Node* temp = root;

    while(temp->right != NULL)
    {
        temp = temp->right; 
    }
    return temp;
}
bool Checkprime(int *n)
{
    int i=1,count=0;
    for(i=1;i<=*n;i++)
    {
        if(*n%i==0)
        {
            count++;
        }
    }
    if(count==2)
    {
        return true;
    }
    return false;
}
void findprimeNumber(Node* &root)
{
    queue<Node*> q;
    q.push(root);
    int i;
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(Checkprime(&temp->data))
        {
            cout<<"Prime number : "<<temp->data<<endl;
        }
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }

    }
}

void predecessorSuccessor(Node* &root , int k , Node* succ , Node* pre)
{
    Node* temp = root;

    if(temp == NULL)
    {
        return;
    }
    if(temp->data == k)
    {
        if(temp->left)
        {
            pre = MaxValue(temp->left);
        }
        if(temp->right)
        {
            succ = MinValue(temp->right);
        }
        cout<<"pre: "<<pre->data<<endl;
        cout<<"suc: "<<succ->data<<endl;
        return;
    }

    if(temp->data > k)
    {
        succ = temp;
        predecessorSuccessor(root->left , k, succ , pre);
    }
    else if(temp->data < k)
    {
        pre = temp;
        predecessorSuccessor(root->right , k , succ , pre);
    }

}

int main()
{
    Node* root = NULL;
    Node* pre = NULL;
    Node* succ = NULL;
    cout<<"Enter data to create BTS: "; //10 8 21 7 27 5 4 3 -1
    takeInput(root);

    cout<<"Printing the BTS: "<<endl;
    levelOrderTraversal(root);

    // findprimeNumber(root);

    // if(present(20,root))
    // {
    //     cout<<"element is present. "<<endl;
    // }
    // else
    // {
    //     cout<<"element is not present. "<<endl;
    // }

    // cout<<"Printing preorder: "<<endl;
    // preOrder(root);
    // cout<<endl<<"Printing postorder: "<<endl;
    // postOrder(root);
    // cout<<endl<<"Printing inorder: "<<endl;
    // inOrder(root);

    // cout<<"Min value is : "<<MinValue(root) ->data << endl;
    // cout<<"Max value is : "<<MaxValue(root) ->data << endl;

    // root = deletefromBST(root,30);  // 50 21 70 10 30 90 110 -1
 
    // cout<<"Printing the BTS: "<<endl;
    // levelOrderTraversal(root);

    predecessorSuccessor(root, 10, succ , pre);
    

    
}