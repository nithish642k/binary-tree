
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
void spiralTraversal(struct Node * node)
{
    stack<Node*>s1,s2;
    s1.push(node);
while(!s1.empty()||!s2.empty())
{
    while(!s1.empty())
    {
        Node *temp=s1.top();
        s1.pop();
        cout<<temp->data<<" ";
        if(temp->right!=NULL)
        {
            s2.push(temp->right);
        }
        if(temp->left!=NULL)
        {
            s2.push(temp->left);
        }
    }
    cout<<endl;
    while(!s2.empty())
    {
        Node *temp=s2.top();
        s2.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL)
        {
            s1.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            s1.push(temp->right);
        }
    }
    cout<<endl;
}

}
int main()
{
    struct Node *root=new Node(2);
    root->left=new Node(7);
    root->right=new Node(5);
    root->left->left=new Node(12);
    root->left->right=new Node(6);
    root->right->right=new Node(9);
    root->left->right->left=new Node(5);
    root->left->right->right=new Node(11);
    root->right->right->left=new Node(4);
    cout<<"Spiral traversal:\n";
    spiralTraversal(root);
    return 0;
}
