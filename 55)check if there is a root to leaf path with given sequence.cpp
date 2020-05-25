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
bool check(struct Node *node,int index,int seq[],int n)
{
if(node==NULL)
    return false;
if(index>=n||node->data!=seq[index])
    return false;
if(node->left==NULL&&node->right==NULL&&index==n-1)
    return true;
return check(node->left,index+1,seq,n)||check(node->right,index+1,seq,n);
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
    int seq[]={2,7,6,11};
    int n=sizeof(seq)/sizeof(seq[0]);
    bool result=check(root,0,seq,n);
    if(result)
    {
        cout<<"Sequence path exists";
    }
    else
    {
        cout<<"Sequence path does not exist";
    }
    return 0;
}
