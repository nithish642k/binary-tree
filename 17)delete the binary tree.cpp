
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
struct Node* deleteTree(struct Node *node)
{
if(node==NULL)
    return NULL;
deleteTree(node->left);
deleteTree(node->right);
cout <<"Deleting..."<<node->data << " ";
node=NULL;
return node;
}
void inorder(struct Node *node)
{
if(node==NULL)
    return;
inorder(node->left);
cout << node->data << " ";
inorder(node->right);
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
    root=deleteTree(root);
    cout<<"\nInorder traversal:"<<endl;
    inorder(root);
    return 0;
}
