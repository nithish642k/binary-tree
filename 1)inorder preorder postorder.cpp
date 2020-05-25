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
void inorder(struct Node *node)
{
if(node==NULL)
    return;
inorder(node->left);
cout << node->data << " ";
inorder(node->right);
}
void preorder(struct Node *node)
{
if(node==NULL)
    return;
cout << node->data << " ";
preorder(node->left);
preorder(node->right);
}
void postorder(struct Node *node)
{
if(node==NULL)
    return;
postorder(node->left);
postorder(node->right);
cout << node->data << " ";
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

    cout<<"Inorder traversal:"<<endl;
    inorder(root);
    cout<<"\nPreorder traversal:"<<endl;
    preorder(root);
    cout<<"\nPostorder traversal:"<<endl;
    postorder(root);

    return 0;
}
