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
void bottomView(struct Node *node)
{
    if(node==NULL)
    return;
    queue<Node*>q;
    q.push(node);
    map<int,int>m;
    node->height=0;
    while(!q.empty())
    {
        Node * temp=q.front();
        q.pop();
        int ht=temp->height;
            m[ht]=temp->data;
        if(temp->left!=NULL)
        {
            temp->left->height=ht-1;
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            temp->right->height=ht+1;
            q.push(temp->right);
        }
    }
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
    {
        cout<<it->second<<" ";
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
    cout<<"Bottom View:\n";
    bottomView(root);
    return 0;
}

