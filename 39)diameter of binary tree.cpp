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
int getDiameter(struct Node *node,int &diameter)
{
if(node==NULL)
    return 0;
if(node->left==NULL&&node->right==NULL)
    return 1;

int leftHeight=getDiameter(node->left,diameter);
int rightHeight=getDiameter(node->right,diameter);

diameter=max(diameter,leftHeight+rightHeight+1);

return max(leftHeight,rightHeight)+1;
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
    int diameter=0;
    getDiameter(root,diameter);
    cout<<"Diameter:"<<diameter;
    return 0;
}
