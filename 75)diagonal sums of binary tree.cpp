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
void getDiagonalSum(Node *node,vector<int>&d,int i)
{
    if(node==NULL)
        return;
    d[i]+=node->data;
    getDiagonalSum(node->left,d,i+1);
    getDiagonalSum(node->right,d,i);
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
    cout<<"Diagonal sums:";
    vector<int>d(10,0);
    getDiagonalSum(root,d,0);
    for(int i=0;i<d.size();i++)
    {
        if(d[i]!=0)
        cout<<d[i]<<" ";
    }
    return 0;
}
