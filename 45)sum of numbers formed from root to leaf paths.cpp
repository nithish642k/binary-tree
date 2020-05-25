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
void getSum(struct Node * node,int i,long int &sum)
{
    if(node==NULL)
        return;
    if(node->left==NULL&&node->right==NULL)
    {
        sum=sum+i*10+node->data;
    }
    getSum(node->left,i*10+node->data,sum);
    getSum(node->right,i*10+node->data,sum);
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
    root->left->right->right=new Node(1);
    root->right->right->left=new Node(4);
    long int sum=0;
    getSum(root,0,sum);
    cout<<"Sum:"<<sum;
    return 0;
}
