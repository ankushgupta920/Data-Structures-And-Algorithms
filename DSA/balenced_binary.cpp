#include<iostream>
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
int height(Node* &root)
{
    if(root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int Rh = height(root->right);
    return max(lh , Rh) + 1;

}
bool isBalanced(Node* &root)
{
    if(isBalanced(root->left) == false)
    {
        return false;
    }
    if(isBalanced(root->right) == false)
    {
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main(){
    Node* root1 = new Node(2);


return 0;
}