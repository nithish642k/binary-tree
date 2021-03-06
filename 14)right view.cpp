
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
void getNodes(struct Node *node,int level,int *flag)
{
    if(node==NULL)
    return;
    if(level==1&&*flag==0)
    {
        *flag=1;
        cout<<node->data<<" ";
    }
getNodes(node->right,level-1,flag);
getNodes(node->left,level-1,flag);
}
int Height(struct Node *node)
{
if(node==NULL)
    return -1;
return 1+max(Height(node->left),Height(node->right));
}
void levelOrderTraversal(struct Node * node)
{
    int levels=Height(node)+1;
    for(int i=1;i<=levels;i++)
    {
        int flag=0;
        getNodes(node,i,&flag);
    }
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
    cout<<"Level order traversal:\n";
    levelOrderTraversal(root);
    return 0;
}
