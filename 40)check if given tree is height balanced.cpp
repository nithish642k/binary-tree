/* Number of nodes on the longest path between any two leaf nodes */

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
int check(struct Node *node)
{
if(node==NULL)
    return 0;
if(node->left==NULL&&node->right==NULL)
    return 1;

int leftHeight=check(node->left);
int rightHeight=check(node->right);

if(leftHeight==-1||rightHeight==-1||abs(leftHeight-rightHeight)>1)
    return -1;

return max(leftHeight,rightHeight)+1;
}
int main()
{
    /*
    struct Node *root=new Node(2);
    root->left=new Node(7);
    root->right=new Node(5);
    root->left->left=new Node(2);
    root->left->right=new Node(6);
    root->left->left->left=new Node(5);
    */
    struct Node *root=new Node(2);
    root->left=new Node(7);
    root->right=new Node(5);
    root->left->left=new Node(2);
    root->left->right=new Node(6);
    root->right->left=new Node(3);
    root->left->left->left=new Node(5);

    cout<<"Balanced:"<<(check(root)!=-1);
    return 0;
}

