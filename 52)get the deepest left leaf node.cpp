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
void getDeepestLeftLeafNode(struct Node *node,int &dllnode,int level,bool ifLeftLeaf)
{
static int max_level=0;
if(node==NULL)
    return;
if(node->left==NULL&&node->right==NULL&&ifLeftLeaf&&level>max_level)
{
    dllnode=node->data;
    max_level=level;
}
 getDeepestLeftLeafNode(node->left,dllnode,level+1,true);
 getDeepestLeftLeafNode(node->right,dllnode,level+1,false);
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
    int dllnode=-1;
    getDeepestLeftLeafNode(root,dllnode,1,false);
    if(dllnode!=-1)
        cout<<"The deepest left leaf node found is:"<<dllnode;
        else
            cout<<"There is no such leaf node";
    return 0;
}
