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
int getLevel(Node *node,int val,int level)
{
    if(node==NULL)
        return 0;
     if(node->data==val)
        return level;
    int l=getLevel(node->left,val,level+1);
    if(l!=0)
        return l;
    return getLevel(node->right,val,level+1);
}
void printRightNode(Node *node,int val,int level)
{
    static bool flag=0;
    if(node==NULL)
        return;
    printRightNode(node->left,val,level-1);
    if(level==1&&flag)
    {
        cout<<node->data<<" ";
        flag=0;
    }
    if(level==1&&node->data==val)
    {
        flag=1;
    }
    printRightNode(node->right,val,level-1);
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
    int val=6;
    int level=getLevel(root,val,1);
    printRightNode(root,val,level);
    return 0;
}
