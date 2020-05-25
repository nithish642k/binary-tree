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
void levelOrderTraversal(struct Node * node)
{
    if(node==NULL)
        return;
    queue<Node*>q;
    stack<Node*>s;
    q.push(node);
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        s.push(node);
        if(node->right!=NULL)
        {
            q.push(node->right);  // NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT
        }
        if(node->left!=NULL)
        {
            q.push(node->left);
        }
    }
    while(!s.empty())
    {
        node=s.top();
        cout<<node->data<<" ";
        s.pop();
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


