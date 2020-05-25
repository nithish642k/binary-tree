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
void getDeepestLeftLeafNode(struct Node *node,int &dllnode,int level,int &max_odd_level)
{
if(node==NULL)
    return;
if(node->left==NULL&&node->right==NULL&&level>max_odd_level&&level%2!=0)
{
    max_odd_level=level;
}
 getDeepestLeftLeafNode(node->left,dllnode,level+1,max_odd_level);
 getDeepestLeftLeafNode(node->right,dllnode,level+1,max_odd_level);
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
    /*
    root->left->left->left=new Node(10);
    root->left->left->left->right=new Node(12);
    */
    int dllnode=-1,max_odd_level=-1;
    getDeepestLeftLeafNode(root,dllnode,1,max_odd_level);
    if(max_odd_level!=-1)
        cout<<"The deepest odd level with leaf is:"<<max_odd_level;
        else
            cout<<"There is no such level";
    return 0;
}
