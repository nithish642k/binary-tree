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
void findParent(struct Node *node,int key,int parent)
{
if(node==NULL)
    return;
if(node->data==key)
    cout<<parent;
findParent(node->left,key,node->data);
findParent(node->right,key,node->data);
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
    int key=9;
    findParent(root,key,-1);
    return 0;
}
