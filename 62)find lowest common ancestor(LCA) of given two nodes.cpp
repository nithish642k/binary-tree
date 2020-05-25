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
bool getAncestors(struct Node *node,int key,vector<int>&ans)
{
if(node==NULL)
    return false;
if(node->data==key)
    return true;
if(getAncestors(node->left,key,ans)||getAncestors(node->right,key,ans))
{
    ans.push_back(node->data);
    return true;
}
return false;
}
int main()
{
    struct Node *root=new Node(12);
    root->left=new Node(7);
    root->right=new Node(5);
    root->left->left=new Node(2);
    root->left->right=new Node(6);
    root->right->right=new Node(9);
    root->left->right->left=new Node(5);
    root->left->right->right=new Node(11);
    root->right->right->left=new Node(4);
    int key1=6,key2=4;
    vector<int>ans1,ans2;
    int lca=root->data;
    getAncestors(root,key1,ans1);
    getAncestors(root,key2,ans2);
    bool found=0;
    for(int i=0;i<ans1.size();i++)
    {
        for(int j=0;j<ans2.size();j++)
        {
            if(ans1[i]==ans2[j]&&!found)
            {
                lca=ans1[i];
                found=1;
                break;
            }
        }
    }
    cout<<"Lowest common ancestor:"<<lca;

    return 0;
}
