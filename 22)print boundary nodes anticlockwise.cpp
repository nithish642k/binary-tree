#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left,*right;
    int height;
    Node(int data)
    {
        this->data=data;
        left=right=NULL;
    }
};
void leftBoundary(struct Node *node)
{
    if(node==NULL)
        return;
    if(node->left!=NULL)
    {
        cout<<node->data<<" ";
        leftBoundary(node->left);
    }
    else if(node->right!=NULL)
    {
        cout<<node->data<<" ";
        leftBoundary(node->right);
    }
}
void leaves(struct Node *node)
{
    if(node==NULL)
        return;

    if(node->left==NULL&&node->right==NULL)
    {
        cout<<node->data<<" ";
    }
    leaves(node->left);
    leaves(node->right);
}
void rightBoundary(struct Node *node)
{
    if(node==NULL)
        return;
    if(node->right!=NULL)
    {
        rightBoundary(node->right);
        cout<<node->data<<" ";
    }
    else if(node->left!=NULL)
    {
        rightBoundary(node->left);
        cout<<node->data<<" ";
    }
}
void boundaryNodes(struct Node *node)
{
    if(node==NULL)
    return;
    cout<<node->data<<" "; //print root first
    leftBoundary(node->left); // non-leaf left boundary
    leaves(node->left);
    leaves(node->right);
    rightBoundary(node->right); //non-leaf right boundary
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
    cout<<"Boundary nodes:\n";
    boundaryNodes(root);
    return 0;
}
