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
int getMinDistDownToLeaf(Node *node)
{
    if(node==NULL)
        return INT_MAX;
    if(node->left==NULL&&node->right==NULL)
        return 0;
    return 1+min(getMinDistDownToLeaf(node->left),getMinDistDownToLeaf(node->right));
}
int closestLeafNodeDistance(Node *node,int val,Node *arr[],int level)
{
    if(node==NULL)
    {
        return INT_MAX;
    }
    int minDistToLeaf=INT_MAX;
    if(node->data==val)
    {
        minDistToLeaf=getMinDistDownToLeaf(node);
    for(int i=level-1;i>=0;i--)
    {
        minDistToLeaf=min(minDistToLeaf,level-i+getMinDistDownToLeaf(arr[i]));
    }
    return minDistToLeaf;
    }
    arr[level]=node;
    minDistToLeaf=min(minDistToLeaf,closestLeafNodeDistance(node->left,val,arr,level+1));
    if(minDistToLeaf!=INT_MAX)
    {
        return minDistToLeaf;
    }
    return min(minDistToLeaf,closestLeafNodeDistance(node->right,val,arr,level+1));
}
int main()
{
    struct Node *root=new Node(2);
    root->left=new Node(7);
    root->right=new Node(9);
    root->left->left=new Node(10);
    root->left->right=new Node(6);
    root->left->right->left=new Node(5);
    root->left->right->left->left=new Node(4);
    root->left->right->left->left->left=new Node(3);
    int val=6;
    if(root==NULL)
    {
        cout<<"-1";
    }
    else
    {
        Node *arr[100];
        cout<<closestLeafNodeDistance(root,val,arr,0);
    }
    return 0;
}

