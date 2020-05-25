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
void findSibling(struct Node *node,int key1,int key2,bool &sibling)
{
if(node==NULL)
    return;
if(node->left!=NULL&&node->right!=NULL&&node->left->data==key1&&node->right->data==key2)  //Both not NULL conditions are necessary!!
{
    sibling=true;
    return;
}
if(node->left!=NULL&&node->right!=NULL&&node->left->data==key2&&node->right->data==key1)  //Both not NULL conditions are necessary!!
{
    sibling=true;
    return;
}
findSibling(node->left,key1,key2,sibling);
findSibling(node->right,key1,key2,sibling);
}
int main()
{
    struct Node *root=new Node(12);
    root->left=new Node(7);
    root->right=new Node(5);
    root->left->left=new Node(2);
    root->left->right=new Node(6);
    root->right->right=new Node(9);
    root->left->right->left=new Node(5);
    root->left->right->right=new Node(11);
    root->right->right->left=new Node(4);
    int key1=6,key2=2;
    bool sibling=false;
    findSibling(root,key1,key2,sibling);
    if(sibling)
        cout<<"Siblings!";
    else
        cout<<"Not siblings";
    return 0;
}
