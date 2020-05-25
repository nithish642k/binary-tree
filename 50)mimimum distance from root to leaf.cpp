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
int getMinDistance(struct Node *node)
{
if(node==NULL)
    return INT_MAX;
if(node->left==NULL&&node->right==NULL)
    return 0;
return 1+min(getMinDistance(node->left),getMinDistance(node->right));
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
    cout<<"Minimum distance from root to leaf:"<<getMinDistance(root);
    return 0;
}
