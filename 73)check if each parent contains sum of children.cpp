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
bool check(struct Node * node)
{
    if(node==NULL||(node->left==NULL&&node->right==NULL))
        return true;
    int a=node->left!=NULL?node->left->data:0;
    int b=node->right!=NULL?node->right->data:0;
    if(a+b!=node->data)
        return false;
    return /* (a+b==node->data)&& */check(node->left)&&check(node->right);
}
int main()
{
    struct Node *root=new Node(12);
    root->left=new Node(4);
    root->right=new Node(8);
    root->left->left=new Node(3);
    root->left->right=new Node(1);
    root->right->right=new Node(8);
    cout<<check(root);
    return 0;
}
