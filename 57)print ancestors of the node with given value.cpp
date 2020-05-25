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
bool printAncestors(struct Node *node,int key)
{
if(node==NULL)
    return false;
if(node->data==key)
    return true;
if(printAncestors(node->left,key)||printAncestors(node->right,key))
{
    cout<<node->data<<" ";
    return true;
}
return false;
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
    int key=11;
    printAncestors(root,key);
    return 0;
}
