#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left,*right;
    Node(int data)
    {
        this->data=data;
        left=right=NULL;
    }
};
bool isBST(Node *node)
{
    static Node *prev=NULL;
    if(node==NULL)
        return true;
    if(!isBST(node->left))
        return false;
    if(prev!=NULL&&prev->data>=node->data)
        return false;
    prev=node;
    return isBST(node->right);
}
int main()
{
    struct Node *root=new Node(12);
    root->left=new Node(7);
    root->right=new Node(24);
    root->left->left=new Node(6);
    root->left->right=new Node(9);
    root->left->left->left=new Node(2);
    if(isBST(root))
        cout<<"BST";
    else
        cout<<"Not BST";
    return 0;
}
