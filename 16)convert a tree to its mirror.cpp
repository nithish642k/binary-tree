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
struct Node* mirror(struct Node *node)
{
if(node==NULL)
    return NULL;
Node *temp=node->left;
node->left=node->right;
node->right=temp;
mirror(node->left);
mirror(node->right);
return node;
}
int main()
{
    struct Node *root=new Node(8);
    root->left=new Node(3);
    root->right=new Node(10);
    root->left->left=new Node(1);
    root->left->right=new Node(6);
    root->right->right=new Node(14);
    root->left->right->left=new Node(4);
    root->left->right->right=new Node(7);
    root->right->right->left=new Node(13);
    mirror(root);
    cout<<"\nInorder traversal:"<<endl;
    inorder(root);
    return 0;
}
