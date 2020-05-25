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
void doubleTree(struct Node *node)
{
if(node==NULL)
{
    return;
}
doubleTree(node->left);
doubleTree(node->right);

Node *temp=new Node(node->data);
temp->left=node->left;
node->left=temp;
}
int main()
{
    struct Node *root=new Node(2);
    root->left=new Node(7);
    root->right=new Node(8);
    doubleTree(root);
    cout<<"\nInorder traversal:"<<endl;
    inorder(root);
    return 0;
}
