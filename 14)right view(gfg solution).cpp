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
void rightView(struct Node *node,int level,int *maxlevel)
{
    if(node==NULL)
    return;
    if(*maxlevel<level)
    {
        cout<<node->data<<" ";
        *maxlevel=level;
    }
rightView(node->right,level+1,maxlevel);
rightView(node->left,level+1,maxlevel);
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
    cout<<"Level order traversal:\n";
    int maxlevel=0;
    rightView(root,1,&maxlevel);
    return 0;
}
