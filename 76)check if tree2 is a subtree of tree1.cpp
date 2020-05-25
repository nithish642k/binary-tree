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
void storeInorder(Node *node,string &str)
{
    if(node==NULL)
        return;
    storeInorder(node->left,str);
    str+=to_string(node->data);
    storeInorder(node->right,str);
}
void storePreorder(Node *node,string &str)
{
    if(node==NULL)
        return;
    str+=to_string(node->data);
    storePreorder(node->left,str);
    storePreorder(node->right,str);
}
int main()
{
    struct Node *tree1=new Node(2);
    tree1->left=new Node(7);
    tree1->right=new Node(5);
    tree1->left->left=new Node(2);
    tree1->left->right=new Node(6);
    tree1->right->right=new Node(9);
    tree1->left->right->left=new Node(5);
    tree1->left->right->right=new Node(11);
    tree1->right->right->left=new Node(4);

    struct Node *tree2=new Node(7);
    tree2->left=new Node(2);
    tree2->right=new Node(6);
    tree2->right->left=new Node(5);
    tree2->right->right=new Node(11);

    string inorderT1,preorderT1,inorderT2,preorderT2;
    storeInorder(tree1,inorderT1);
    storeInorder(tree2,inorderT2);
    storePreorder(tree1,preorderT1);
    storePreorder(tree2,preorderT2);
    if(inorderT1.find(inorderT2)!=string::npos&&preorderT1.find(preorderT2)!=string::npos)
        cout<<"t2 is a subtree of t1";
    else
        cout<<"t2 is not a subtree of t1";
    return 0;
}
