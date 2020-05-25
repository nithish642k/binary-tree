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
int getMaximumSum(Node *node,int &maxSum)
{
    if(node==NULL)
        return 0;
    if(node->left==NULL&&node->right==NULL)
        return node->data;
    int l=getMaximumSum(node->left,maxSum);
    int r=getMaximumSum(node->right,maxSum);
    if(node->right!=NULL&&node->left!=NULL)
    {
        if(l+r+node->data>maxSum)
            maxSum=l+r+node->data;
        return max(l,r)+node->data;
    }
    return node->left!=NULL?l+node->data:r+node->data;
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
    int maxSum=INT_MIN;
    getMaximumSum(root,maxSum);
    cout<<maxSum;
    return 0;
}
