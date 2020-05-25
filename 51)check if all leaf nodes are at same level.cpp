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
bool check(struct Node *node,int level)
{
    static int max_level=0;
if(node==NULL)
    return INT_MAX;
if(node->left==NULL&&node->right==NULL)
{
    if(max_level==0)
    {
        max_level=level;
        return true;
    }
    else if(level==max_level)
    {
        return true;
    }
    return false;
}
return check(node->left,level+1)&&check(node->right,level+1);
}
int main()
{
    struct Node *root=new Node(2);
    root->left=new Node(7);
    root->right=new Node(5);
    root->left->left=new Node(2);
    root->left->right=new Node(6);
    root->right->right=new Node(9);
    root->right->left=new Node(10);
    bool result=check(root,1);
    if(result)
    {
        cout<<"All leaf nodes are at the same level"<<endl;
    }
    else
    {
        cout<<"All leaf nodes are not at the same level"<<endl;
    }
    return 0;
}
