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
void printNodesAtKDistance(Node *node,int k,int arr[],bool visited[],int count)
{
    if(node==NULL)
    {
        return;
    }
    arr[count]=node->data;
    visited[count]=false;
    if(node->left==NULL&&node->right==NULL&&count-k>=0&&!visited[count-k])
    {
        cout<<arr[count-k]<<" ";
        visited[count-k]=true;
        return;
    }
    printNodesAtKDistance(node->left,k,arr,visited,count+1);
    printNodesAtKDistance(node->right,k,arr,visited,count+1);
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
    int k=1;
    if(root==NULL||k<0)
    {
        cout<<"-1";
    }
    else
    {
        int arr[100];
        bool visited[100];
        printNodesAtKDistance(root,k,arr,visited,0);
    }
    return 0;
}
