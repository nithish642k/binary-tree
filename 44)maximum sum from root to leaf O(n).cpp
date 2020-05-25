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
void getMaxSum(struct Node * node,int sum,int &max_sum)
{
    if(node==NULL)
        return;
    if(node->left==NULL&&node->right==NULL&&sum+node->data>max_sum)
    {
        max_sum=sum+node->data;
    }
    getMaxSum(node->left,sum+node->data,max_sum);
    getMaxSum(node->right,sum+node->data,max_sum);
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
    int max_sum=INT_MIN;
    getMaxSum(root,0,max_sum);
    cout<<"Maximum sum:"<<max_sum;
    return 0;
}
