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
void findSibling(struct Node *node,int key,int &sibling)
{
if(node==NULL)
    return;
if(node->left!=NULL&&node->right!=NULL&&node->left->data==key)  //Both not NULL conditions are necessary!!
{
    sibling=node->right->data;
    return;
}
if(node->right!=NULL&&node->left!=NULL&&node->right->data==key) //Both not NULL conditions are necessary!!
{
    sibling=node->left->data;
    return;
}
findSibling(node->left,key,sibling);
findSibling(node->right,key,sibling);
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
    int key=7;
    int sibling=-1;
    findSibling(root,key,sibling);
    if(sibling!=-1)
        cout<<"the sibling of "<<key<<" is:"<<sibling;
    else
        cout<<"No sibling";
    return 0;
}
