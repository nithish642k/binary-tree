/*
 Two trees are called isomorphic if one of them can be obtained from other by a series of flips,
  (i.e.) by swapping left and right children of a number of nodes.
*/
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
  return (check(node1->left,node2->right)&&check(node1->right,node2->left))||(check(node1->left,node2->left)&&check(node1->right,node2->right));
}
int main()
{
    struct Node *root1=new Node(2);
    root1->left=new Node(7);
    root1->right=new Node(8);
    root1->left->left=new Node(5);


    struct Node *root2=new Node(3);
    root2->left=new Node(8);
    root2->right=new Node(7);
    root2->left->right=new Node(5);

    /*
    struct Node *root2=new Node(2);
    root2->left=new Node(7);
    root2->right=new Node(8);
    root2->left->left=new Node(5);
    */
    bool result=check(root1,root2);
    if(result)
    {
        cout<<"Isomorphic";
    }
    else
    {
        cout<<"Not isomorphic";
    }
    return 0;
}
