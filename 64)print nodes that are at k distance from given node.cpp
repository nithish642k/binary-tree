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
void printNodesAtKDistanceDown(Node *node,int k)
{
    if(node==NULL)
    {
        return;
    }
    if(k==0)
    {
        cout<<node->data<<" ";
    }
    printNodesAtKDistanceDown(node->left,k-1);
    printNodesAtKDistanceDown(node->right,k-1);
}
int printNodesAtKDistance(Node *node,Node *target,int k)
{
    if(node==NULL)
    {
        return -1;
    }
    if(node==target)
    {
        printNodesAtKDistanceDown(node,k);
        return 0;
    }
    int leftDist=printNodesAtKDistance(node->left,target,k); // not k value is still k
    if(leftDist!=-1)
    {
        if(leftDist+1==k)
        {
            cout<<node->data<<" ";
        }
        else
        {
            printNodesAtKDistanceDown(node->right,k-2-leftDist); // traverse right from root downwards
        }
        return leftDist+1;
    }
    int rightDist=printNodesAtKDistance(node->right,target,k);
    if(rightDist!=-1)
    {
        if(rightDist+1==k)
        {
            cout<<node->data<<" ";
        }
        else
        {
            printNodesAtKDistanceDown(node->left,k-2-leftDist);
        }
        return rightDist+1;
    }
}
int main()
{
    struct Node *root=new Node(12);
    root->left=new Node(7);
    root->right=new Node(15);
    root->left->left=new Node(2);
    root->left->right=new Node(6);
    root->right->right=new Node(9);
    root->left->right->left=new Node(5);
    root->left->right->right=new Node(11);
    root->right->right->left=new Node(4);
    struct Node *target=root->left;
    int k=2;
    if(root==NULL||target==NULL||k<0)
    {
        cout<<"-1";
    }
    else
    {
        printNodesAtKDistance(root,target,k);
    }
    return 0;
}
