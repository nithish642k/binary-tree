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
void inorder(struct Node *node,int &max,int &min)
{
if(node==NULL)
    return;
    inorder(node->left,max,min);
    if(node->data>max)
    {
        max=node->data;
    }
    if(node->data<min)
    {
        min=node->data;
    }
    inorder(node->right,max,min);
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
    int max=INT_MIN;
    int min=INT_MAX;
    inorder(root,max,min);
    cout<<"Max:"<<max<<endl;
    cout<<"Min:"<<min<<endl;
    return 0;
}
