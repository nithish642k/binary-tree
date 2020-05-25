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
Node *getLCA(Node *node,int key1,int key2)
{
if(node==NULL)
    return NULL;
if(node->data==key1||node->data==key2)
    return node;
Node *leftLCA=getLCA(node->left,key1,key2);
Node *rightLCA=getLCA(node->right,key1,key2);
if(leftLCA!=NULL&&rightLCA!=NULL)
{
    return node;
}
if(leftLCA!=NULL)
{
    return leftLCA;
}
return rightLCA;
}
int getDistance(Node *node,int key,int distance)
{
    if(node==NULL)
        return -1;
    if(node->data==key)
        return distance;
    int d=getDistance(node->left,key,distance+1);
    if(d!=-1)
        return d;
    d=getDistance(node->right,key,distance+1);
    return d;
}
int main()
{
    struct Node *root=new Node(12);
    root->left=new Node(7);
    root->right=new Node(15);
    root->left->left=new Node(2);
    root->left->right=new Node(6);
    root->right->right=new Node(9);
    root->left->right->left=new Node(5);
    root->left->right->right=new Node(11);
    root->right->right->left=new Node(4);
    int key1=6,key2=2;
    Node *lca=getLCA(root,key1,key2);
    cout<<"Distance between "<<key1<<" and "<<key2<<":"<<getDistance(lca,key1,0)+getDistance(lca,key2,0);
    return 0;
}
