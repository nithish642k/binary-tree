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
int getWidth(struct Node *node,int level)
{
if(node==NULL)
    return 0;
if(level==1)
    return 1;
return getWidth(node->left,level-1)+getWidth(node->right,level-1);
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
    int level=4;
    cout<<"Widith of "<<level<<" is:"<<getWidth(root,level);
    return 0;
}
