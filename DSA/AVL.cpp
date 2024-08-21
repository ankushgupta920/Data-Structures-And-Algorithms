#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};
class AVLTree
{
    private:
    Node* root;

    int getHeight(Node* n)
    {
        // base case:
        if(n == NULL)
        {
            return 0;
        }
        else
        {
            return n->height;
        }
    }

    int getBalanceFactor(Node* n)
    {
        // base case:
        if(n == NULL)
        {
            return 0;
        }
        else
        {
            return getHeight(n->left) - getHeight(n->right);
        }
    }

    Node* leftRotate(Node* x)
    {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        // update height:
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;    
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;  

        return y;
    }

    Node* rightRotate(Node* y)
    {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        // update height:
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1; 
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;     

        return x;
        
    }

    Node* balance(Node* n)
    {
        // update the balance factor of each node after inserting the nodes:

        if(n == NULL)
        {
            return NULL;
        }
         
        n->height =  max(getHeight(n->left), getHeight(n->right)) + 1;
        int balance = getBalanceFactor(n);

        // for left rotation:(RR)(RL)
        if(balance < -1)
        {
            if(getBalanceFactor(n->right) <= 0)
            {
                return leftRotate(n);
            }
            else
            {
                n->right = rightRotate(n->right);
                return leftRotate(n);
            }
        }

        // for right rotation:(LL)(LR)
        if(balance > 1)
        {
            if(getBalanceFactor(n->left) >= 0)
            {
                return rightRotate(n);
            }
            else
            {
                n->left = leftRotate(n->left);
                return rightRotate(n);
            }
        }

        return n;
    }
    Node* insertIntoAVL(Node* n,int d)
    {
        // base case:
        if(n == NULL)
        {
            return new Node(d);
        }

        if(d > n->data)
        {
            n->right = insertIntoAVL(n->right,d);
        }
        else if(d < n->data)
        {
            n->left = insertIntoAVL(n->left,d);
        }
        else
        {
            // Duplicate values are not allowed in this simple implementation
            return n;
        }
        return balance(n);
        
    }

    void inorderTraversal(Node *n)
    {
        if (n)
        {   
            inorderTraversal(n->left);
            cout << n->data << " ";
            inorderTraversal(n->right);
        }
    }

    public:
    AVLTree()
    {
        root= NULL;
    }

    void insert(int d)
    {
        root = insertIntoAVL(root,d);
    }
    void inorderTraversal()
    {
        inorderTraversal(root);
        cout<<endl;
    }

};
int main(){
    AVLTree avl;

    // Example usage
    avl.insert(10);
    avl.insert(70);
    avl.insert(60);
    avl.insert(50);
    avl.insert(90);
    avl.insert(55);
    avl.insert(95);
    avl.insert(67);
    avl.insert(44);

    avl.inorderTraversal(); // Output: 20 10 30
return 0;
}