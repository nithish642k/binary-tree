#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left,*right,*next;
    Node(int data)
    {
        this->data=data;
        left=right=next=NULL;
    }
};
void levelOrderTraversal(struct Node * &node)
{
    static Node *prev=NULL;
    if(node==NULL)
        return;
    queue<Node*>q;
    q.push(node);
    while(!q.empty())
    {
        Node *node=q.front();
        q.pop();
        if(prev!=NULL)
        {
            prev->next=node;
        }
        prev=node;
        if(node->left!=NULL)
        {
            q.push(node->left);
        }
        if(node->right!=NULL)
        {
            q.push(node->right);
        }
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
    levelOrderTraversal(root);
    while(root!=NULL)
    {
        cout<<root->data<<" ";
        root=root->next;
    }
    return 0;
}
