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
int check(struct Node *node,int sum)
{
if(node==NULL)
    return false;
if(node->left==NULL&&node->right==NULL&&node->data==sum)
    return true;
return check(node->left,sum-node->data)||check(node->right,sum-node->data);
}
int main()
{
    struct Node *root=new Node(2);
    root->left=new Node(5);
    root->right=new Node(3);
    root->right->left=new Node(1);
    int sum=6;
    cout<<"Sum exists?:"<<check(root,sum);
    return 0;
}


