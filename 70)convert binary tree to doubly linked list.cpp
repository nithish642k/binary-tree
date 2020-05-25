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
void convertBTtoDLL(Node *node,Node *&root2)
{
    if(node==NULL)
        return;
    static Node *prev=NULL;
    convertBTtoDLL(node->left,root2);
    if(prev==NULL)
    {
        root2=node;
    }
    else
    {
        node->left=prev;
        prev->right=node;
    }
    prev=node;
    convertBTtoDLL(node->right,root2);
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
    Node *root2=NULL;
    convertBTtoDLL(root,root2);
    cout<<"\nPrinting doubly linked list...";
    while(root2!=NULL)
    {
        cout<<root2->data<<" ";
        root2=root2->right;
    }
    return 0;
}
