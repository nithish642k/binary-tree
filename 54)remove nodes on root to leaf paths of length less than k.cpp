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
struct Node* remove(struct Node *node,int level,int &k)
{
if(node==NULL)
    return NULL;
 node->left=remove(node->left,level+1,k);
 node->right=remove(node->right,level+1,k);
if(node->left==NULL&&node->right==NULL&&level<k)
{
    delete node;
    return NULL;
}
return node;
}
void inorderTraverse(struct Node *node)
{
if(node==NULL)
    return;
inorderTraverse(node->left);
cout << node->data << " ";
inorderTraverse(node->right);
}
int main()
{
    struct Node *root=new Node(2);
    root->left=new Node(7);
    root->right=new Node(9);

    root->left->left=new Node(2);
    root->left->right=new Node(6);
    root->left->right->right=new Node(11);

    int k=3;
    struct Node *node=remove(root,1,k);
    cout<<"\nInorder traversal:"<<endl;
    inorderTraverse(node);
    return 0;
}
