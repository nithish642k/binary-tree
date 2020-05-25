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
void inorderTraverse(struct Node *node)
{
if(node==NULL)
    return;
inorderTraverse(node->left);
cout << node->data << " ";
inorderTraverse(node->right);
}
int getInOrderIndex(int inorder[],int data,int Start,int End)
{
    for(int i=Start;i<=End;i++)
    {
        if(inorder[i]==data)
            return i;
    }
    return -1;
}
struct Node* buildTree(int inorder[],int preorder[],int inStart,int inEnd)
{
    static int preIndex=0;
    if(inStart>inEnd)
    {
        return NULL;
    }
    struct Node *node=new Node(preorder[preIndex++]);
    if(inStart==inEnd)
    {
        return node;
    }
    int inIndex=getInOrderIndex(inorder,node->data,inStart,inEnd);
    node->left=buildTree(inorder,preorder,inStart,inIndex-1);
    node->right=buildTree(inorder,preorder,inIndex+1,inEnd);
    return node;
}
int main()
{
    int preorder[]={2,4,7,3,8};
    int inorder[]={7,4,3,2,8};
    int n=sizeof(inorder)/sizeof(inorder[0]);
    struct Node *root=buildTree(inorder,preorder,0,n-1);
    cout<<"\nInorder traversal:"<<endl;
    inorderTraverse(root);
    return 0;
}
