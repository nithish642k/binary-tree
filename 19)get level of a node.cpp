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
int getLevel(struct Node *node,int nodeval,int level)
{
  if(node==NULL)
    return 0;
  if(node->data==nodeval)
    return level;
  int l=getLevel(node->left,nodeval,level+1);
  if(l!=0)
    return l;
  l=getLevel(node->right,nodeval,level+1);
  return l;
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
    int nodeval=11;
    cout<<"Level of "<<nodeval<<":"<<getLevel(root,nodeval,1);
    return 0;
}

