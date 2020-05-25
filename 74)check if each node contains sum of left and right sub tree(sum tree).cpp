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
bool isLeafNode(Node *node)
{
    if(node->left==NULL&&node->right==NULL)
        return true;
    return false;
}
bool isSumTree(struct Node * node)
{
    static int leftSum=0,rightSum=0;
    if(node==NULL||isLeafNode(node))
        return true;
    if(node->left==NULL)
        leftSum=0;
    else if(isLeafNode(node->left))
        leftSum=node->left->data;
    else
        leftSum=2*node->left->data;
    if(node->right==NULL)
        rightSum=0;
    else if(isLeafNode(node->right))
        rightSum=node->right->data;
    else
        rightSum=2*node->right->data;
    if(leftSum+rightSum==node->data)
        return true;
    else
        return false;
    return isSumTree(node->left)&&isSumTree(node->right);
}
int main()
{
    struct Node *root=new Node(120);
    root->left=new Node(40);
    root->right=new Node(20);
    root->left->left=new Node(15);
    root->left->right=new Node(25);
    root->right->right=new Node(20);
    cout<<isSumTree(root);
    return 0;
}
