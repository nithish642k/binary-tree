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
void printPathsWithSumK(Node *node,int k,vector<int>path)
{
    if(node==NULL)
        return;
    path.push_back(node->data);
    printPathsWithSumK(node->left,k,path);
    printPathsWithSumK(node->right,k,path);
    int sum=0;
    for(int i=path.size()-1;i>=0;i--)
    {
        sum+=path[i];
        if(sum==k)
        {
            for(int j=i;j<path.size();j++)
            {
                cout<<path[j]<<" ";
            }
            cout<<endl;
        }
    }
    path.pop_back();
}
int main()
{
    /*
    struct Node *root=new Node(2);
    root->left=new Node(7);
    root->right=new Node(5);
    root->left->left=new Node(2);
    root->left->right=new Node(6);
    root->right->right=new Node(9);
    root->left->right->left=new Node(5);
    root->left->right->right=new Node(11); */

    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);


    /* int k=11; */

    int k=5;

    vector<int>path;
    printPathsWithSumK(root,k,path);
    return 0;
}

