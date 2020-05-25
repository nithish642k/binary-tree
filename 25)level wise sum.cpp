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
void getNodes(struct Node *node,int level,map<int,int>&m,int lv)
{
    if(node==NULL)
    return;
    if(level==1)
    {
        m[lv]+=node->data;
    }
getNodes(node->left,level-1,m,lv);
getNodes(node->right,level-1,m,lv);
}
int Height(struct Node *node)
{
if(node==NULL)
    return -1;
return 1+max(Height(node->left),Height(node->right));
}
void levelOrderTraversal(struct Node * node)
{
    map<int,int>m;
    int levels=Height(node)+1;
    for(int i=1;i<=levels;i++)
    {
        getNodes(node,i,m,i);
    }
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
    {
        cout<<it->second<<endl;
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
    cout<<"Level-wise sums:\n";
    levelOrderTraversal(root);
    return 0;
}
