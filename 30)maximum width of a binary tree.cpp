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
int levelOrderTraversal(struct Node * node)
{
    int level,maxWidth=1;
    if(node==NULL)
        return -1;
    queue<Node*>q;
    q.push(node);
    while(1)
    {
     int Size=q.size();
     if(Size==0)
     {
         break;
     }
     if(Size>maxWidth)
     {
         maxWidth=Size;
     }
     while(Size>0) //  !q.empty() won't work here
    {
        Node *node=q.front();
        cout<<node->data<<" ";
        q.pop();
        if(node->left!=NULL)
        {
            q.push(node->left);
        }
        if(node->right!=NULL)
        {
            q.push(node->right);
        }
        Size--;
    }
    cout<<endl;
    level++;
    }
    return maxWidth;
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
    cout<<"Maximum width:"<<levelOrderTraversal(root);
    return 0;
}
