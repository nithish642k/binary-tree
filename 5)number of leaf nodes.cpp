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
int getNumberOfLeafNodes(struct Node *node)
{
if(node==NULL)
    return 0;
if(node->left==NULL&&node->right==NULL)
    return 1;
return getNumberOfLeafNodes(node->left)+getNumberOfLeafNodes(node->right);
}
int main()
{
    struct Node *root=new Node(2);
    root->left=new Node(7);
    root->right=new Node(5);
    root->left->left=new Node(2);
    root->left->right=new Node(6);
    root->right->right=new Node(9);
    root->left->right->left=new Node(5);
    root->left->right->right=new Node(11);
    root->right->right->left=new Node(4);
    cout<<"Number of Leaf nodes:"<<getNumberOfLeafNodes(root);
    return 0;
}

