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
void printPath(struct Node * node,int arr[],int index)
{
    if(node==NULL)
        return;
    arr[index]=node->data;
    if(node->left==NULL&&node->right==NULL)
    {
        for(int i=0;i<=index;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    printPath(node->left,arr,index+1);
    printPath(node->right,arr,index+1);
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
    int arr[100];
    cout<<"Paths:"<<endl;
    printPath(root,arr,0);
    return 0;
}
