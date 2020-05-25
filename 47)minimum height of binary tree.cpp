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
void Height(struct Node *node,int height,int &min_height)
{
if(node==NULL)
    return;
if(node->left==NULL&&node->right==NULL&&height<min_height)
    min_height=height;
Height(node->left,height+1,min_height);
Height(node->right,height+1,min_height);
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
    int min_height=INT_MAX;
    Height(root,0,min_height);
    cout<<"Minimum height:"<<min_height;
    return 0;
}
