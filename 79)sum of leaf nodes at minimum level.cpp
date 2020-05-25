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
int getMinLevel(Node *node,int level) // minimum level with leaf
{
    if(node==NULL)
        return 0;
    if(node->left==NULL&&node->right==NULL)
        return level;
    getMinLevel(node->left,level+1);
    getMinLevel(node->right,level+1);
}
void getSumOfLeavesAtMinLevel(Node *node,int level,int &sum)
{
    if(node==NULL)
        return;
    if(level==1&&node->left==NULL&&node->right==NULL)
    {
        sum+=node->data;
    }
    getSumOfLeavesAtMinLevel(node->left,level-1,sum);
    getSumOfLeavesAtMinLevel(node->right,level-1,sum);
}
int main()
{
    /*
    struct Node *root=new Node(2);
    root->left=new Node(7);
    root->right=new Node(5);
    root->left->left=new Node(2);
    root->left->right=new Node(6);
    root->right->right=new Node(9);
    root->left->right->left=new Node(5);
    root->left->right->right=new Node(11);
    */
    struct Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->left->right->left=new Node(8);
    root->right->left->right=new Node(9);

    int minlevel=getMinLevel(root,1);
    int sum=0;
    getSumOfLeavesAtMinLevel(root,minlevel,sum);
    cout<<sum;
    return 0;
}
