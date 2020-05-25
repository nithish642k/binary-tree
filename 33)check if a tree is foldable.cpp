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
bool check(struct Node *node1,struct Node *node2)
{
  if(node1==NULL&&node2==NULL)
  {
        return true;
  }
  else if(node1==NULL||node2==NULL)
  {
    return false;
  }
  return check(node1->left,node2->right)&&check(node1->right,node2->left);
}
int main()
{
    bool result;
    struct Node *root=new Node(2);
    root->left=new Node(7);
    root->right=new Node(8);
    root->left->left=new Node(5);
    root->right->right=new Node(5);
    if(root==NULL)
    {
        result=true;
    }
    else
    {
        struct Node *root1=root->left;
        struct Node *root2=root->right;
        result=check(root1,root2);
    }
    if(result)
    {
        cout<<"Foldable";
    }
    else
    {
        cout<<"Unfoldable";
    }
    return 0;
}
