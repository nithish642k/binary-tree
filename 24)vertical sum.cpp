#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left,*right;
    int height;
    Node(int data)
    {
        this->data=data;
        left=right=NULL;
    }
};
void getVerticalOrder(struct Node *node,int height,map<int,int>&adj)
{
    if(node==NULL)
    {
        return;
    }
    adj[height]+=node->data;
    getVerticalOrder(node->left,height-1,adj);
    getVerticalOrder(node->right,height+1,adj);
}
void verticalOrder(struct Node * node)
{
    map<int,int>adj;
    getVerticalOrder(node,0,adj);
    cout<<"Printing vertical sums...\n";
    for(map<int,int>::iterator it=adj.begin();it!=adj.end();it++)
    {
            cout<<it->second<<" ";
        cout<<endl;
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
    cout<<"Vertical order:\n";
    verticalOrder(root);
    return 0;
}
