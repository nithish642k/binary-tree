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
void getSumOfLeaves(struct Node *node,int &sum)
{
if(node==NULL)
    return;
if(node->left==NULL&&node->right==NULL)
    sum+=node->data;
getSumOfLeaves(node->left,sum);
getSumOfLeaves(node->right,sum);
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
    int sum=0;
    getSumOfLeaves(root,sum);
    cout<<"Sum of leaves:"<<sum;
    return 0;
}

