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
void getSumAndCount(Node *node,float &sum,float &count)
{
    if(node==NULL)
    {
        return;
    }
    sum+=node->data;
    count++;
    getSumAndCount(node->left,sum,count);
    getSumAndCount(node->right,sum,count);
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
    if(root==NULL)
    {
        cout<<"-1";
    }
    else
    {
        float sum=0,count=0;
        getSumAndCount(root,sum,count);
        cout<<sum/count;
    }
    return 0;
}
