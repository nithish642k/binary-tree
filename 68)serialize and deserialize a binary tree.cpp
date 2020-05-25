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
void preorder(Node *node)
{
    if(node==NULL)
        return;
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}
void serialize(Node *node,vector<int>&v)
{
    if(node==NULL)
    {
        v.push_back(-1);
        return;
    }
    v.push_back(node->data);
    serialize(node->left,v);
    serialize(node->right,v);
}
void deserialize(Node *&node,vector<int>&v,int &index)
{
    if(v[index]==-1)
    {
        index++;
        return;
    }
    node=new Node(v[index++]);
    deserialize(node->left,v,index);
    deserialize(node->right,v,index);
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
    vector<int>v;
    serialize(root,v);
    cout<<"**Serialised**";
    cout<<"\nSerialized tree(preorder):";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    Node *root2=NULL;
    int startIndex=0;
    deserialize(root2,v,startIndex);
    cout<<"\n**Deserialised**";
    cout<<"\nDeserialized tree(preorder):";
    preorder(root2);
    return 0;
}
