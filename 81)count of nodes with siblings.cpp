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
void getNumberOfNodesWithSibs(Node *node,int &count)
{
    if(node==NULL)
        return;
    if(node->left!=NULL&&node->right!=NULL)
        count=count+2;
    getNumberOfNodesWithSibs(node->left,count);
    getNumberOfNodesWithSibs(node->right,count);
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
    int count=0;
    getNumberOfNodesWithSibs(root,count);
    cout<<count;
    return 0;
}
