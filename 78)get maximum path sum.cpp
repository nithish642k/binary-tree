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

    int max_one=max(node->data,node->data+max(l,r));
    int max_two=max(max_one,l+r+node->data);
    maxSum=max(maxSum,max_two);
    return max_one;
}
int main()
{
    struct Node *root=new Node(10);
    root->left=new Node(2);
    root->right=new Node(10);
    root->left->left=new Node(20);
    root->left->right=new Node(1);
    root->right->right=new Node(-25);
    root->right->right->left=new Node(3);
    root->right->right->right=new Node(4);
    int maxSum=INT_MIN;
    getMaximumSum(root,maxSum);
    cout<<maxSum;
    return 0;
}
