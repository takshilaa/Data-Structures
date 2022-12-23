#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;

    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right =NULL;

    }
};

node*binaryTree(node*root)
{
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    root =new node(data);

    if(data==-1)
    {
        return NULL;
    }

    cout<<"node to left of "<<data<<endl;
    root->left=binaryTree(root->left);

    cout<<"node to right of "<<data<<endl;
    root->right=binaryTree(root->right);
    return root;


}

void levelOrderTraversal(node*root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node*temp=q.front();
        q.pop();

        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
            
        }
        else{

            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }

        }
    }
    

}
void inorder(node*root)
{
    //base case
    if(root==NULL)
    {
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
int main()
{
    node*root=NULL;
    //creating tree
    root = binaryTree(root);

    cout<<"Printing level order traversal output: " << endl;
    levelOrderTraversal(root);
    return 0;

    //inorder
    cout<<"Inorder traversal is :  ";
    inorder(root);

}