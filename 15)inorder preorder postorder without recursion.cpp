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
void inorder(struct Node* node)
{
    if(node==NULL)
    {
        return;
    }
    stack<Node*>s;
    while(node!=NULL)
    {
        s.push(node);
        node=node->left;
    }
    while(!s.empty())
    {
        Node *temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        if(temp->right!=NULL)
        {
            Node *temp2=temp->right;
            while(temp2!=NULL)
            {
                s.push(temp2);
                temp2=temp2->left;
            }
        }
    }
}
void preorder(struct Node* node)
{
if(node==NULL)
{
    return;
}
stack<Node*>s;
s.push(node);
while(!s.empty())
{
    Node *temp=s.top();
    cout<<temp->data<<" ";
    s.pop();
    if(temp->right!=NULL)
    {
        s.push(temp->right);
    }
    if(temp->left!=NULL)
    {
        s.push(temp->left);
    }

}
}
void postorder(struct Node* node)
{

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
    cout<<"inorder traversal:\n";
    inorder(root);
    cout<<"\npreorder traversal:\n";
    preorder(root);
    cout<<"\npostorder traversal:\n";
    postorder(root);
    return 0;
}

