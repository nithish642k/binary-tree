#include<bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    struct Node *left,*right;
    Node(char data)
    {
        this->data=data;
        left=right=NULL;
    }
};
bool check(struct Node *node,int index,string str,int n)
{
if(node==NULL)
    return false;
if(index>=n||node->data!=str[index])
    return false;
if(node->left==NULL&&node->right==NULL&&index==n-1)
    return true;
return check(node->left,index+1,str,n)||check(node->right,index+1,str,n);
}
int main()
{
    struct Node *root=new Node('h');
    root->left=new Node('e');
    root->right=new Node('z');
    root->left->left=new Node('e');
    root->left->right=new Node('l');
    root->right->right=new Node('o');
    root->left->right->left=new Node('y');
    root->left->right->right=new Node('l');
    root->left->right->right->left=new Node('o');
    string str="hello";
    int n=str.size();
    bool result=check(root,0,str,n);
    if(result)
    {
        cout<<"String sequence path exists";
    }
    else
    {
        cout<<"String sequence path does not exist";
    }
    return 0;
}
