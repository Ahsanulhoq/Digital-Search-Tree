#include "digitalsearchtree.h"

DigitalSearchTree::DigitalSearchTree()
{
    root=NULL;
    pos=0;
}
bool DigitalSearchTree::isEmpty()
{
    if(root==NULL)
    {
        return true;
    }
    else
        return false;
}

void DigitalSearchTree::insertElement(string d)
{
    pos=0;
    tree_node* t=new tree_node;
    t->data=d;
    t->left=NULL;
    t->right=NULL;
    tree_node* parent;
    parent=NULL;

    if(isEmpty())
    {
        root=t;
    }
    else
    {
        tree_node* curr;
        curr=root;
        while(curr)
        {
            if(pos>4)
            {
                pos=0;
            }
            parent=curr;
            if(t->data[pos]=='1')
            {
                curr=curr->right;
            }
            else
            {
                curr=curr->left;
            }
            pos++;
        }
        if(t->data[pos-1]=='0')
        {
            parent->left=t;
        }
        else
        {
            parent->right=t;
        }
    }

}


void DigitalSearchTree::print_tree_inorder()
{
    inorder(root);
}
void DigitalSearchTree::inorder(tree_node* p)
{
    if(p!=NULL)
    {
        if(p->left)
            inorder(p->left);
        cout<<" "<<p->data<<" ";
        if(p->right)
            inorder(p->right);
    }
    else
         return;
}


void DigitalSearchTree::print_tree_preorder()
{
    preorder(root);
}
void DigitalSearchTree::preorder(tree_node* p)
{
    if(p!=NULL)
    {

        cout<<" "<<p->data<< " ";
        if(p->left)
            preorder(p->left);
        if(p->right)
            preorder(p->right);
    }
    else
        return;
}
void DigitalSearchTree::print_tree_postorder()
{
    postorder(root);
}
void DigitalSearchTree::postorder(tree_node* p)
{
    if(p != NULL)
    {
        if(p->left)
            postorder(p->left);
        if(p->right)
            postorder(p->right);
        cout<<" "<<p->data<<" ";
    }
    else
        return;
}

bool DigitalSearchTree::searchElement(string x)
{
    if(root==NULL)
    {
        return false;
    }
    else{
        pos=0;
        return findx(root,x);
    }
}
bool DigitalSearchTree::findx(tree_node *p,string x)
{
    if(p==NULL)
    {
        return false;
    }
    else if(p->data==x)
    {
        return true;
    }
    else if(p->data!=x)
    {
        return findx(p->left,x)||findx(p->right,x);
    }
}

void DigitalSearchTree::makeTreeEmpty()
{
        makeEmpty(root);
}
void DigitalSearchTree::makeEmpty(tree_node*& p)
{
    if(p!=NULL)
    {
        if(p->left)
            makeEmpty(p->left);
        if(p->right)
            makeEmpty(p->right);
        delete p;//Memory free
        p = NULL;
    }
}
int DigitalSearchTree::CountNode()
{
    return counts(root);//Helper function call
}
int DigitalSearchTree::counts(tree_node* p)
{
if(p!= NULL)
    {
       return 1+counts(p->left)+counts(p->right);
    }
    else{
        return 0;;
    }
}

void DigitalSearchTree::removeElement(string d)
{
    //Locate the element
    pos=0;//Level count
    bool found = false;
    if(isEmpty())
    {
        cout<<"\n Tree is empty! "<<endl;
        return;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while(curr != NULL)
    {
        if(pos>4)
            {
                pos=0;
            }
        if(curr->data == d)
        {
            found = true;
            break;
        }
        else
        {
            parent = curr;
            if(d[pos]=='1')
                curr = curr->right;
            else
                curr = curr->left;
        }
        pos++;
    } // while ends here
    if(!found)
    {
        cout<<" Data Not found! "<<endl;
        return;
    }
// 3 cases :
// 1. We're removing a leaf node
// 2. We're removing a node with a single child
// 3. we're removing a node with 2 children
// 1. Node with single child
    if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL
            && curr->right == NULL))
    {
        if(curr->left == NULL && curr->right != NULL)
        {
            if(parent->left == curr)
            {
                parent->left = curr->right;
                delete curr;
            }
            else
            {
                parent->right = curr->right;
                delete curr;
            }
        }
        else // left child present, no right child
        {
            if(parent->left == curr)
            {
                parent->left = curr->left;
                delete curr;
            }
            else
            {
                parent->right = curr->left;
                delete curr;
            }
        }
        return;
    }
//We're looking at a leaf node
    if( curr->left == NULL && curr->right == NULL)
    {
        if(parent->left == curr)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
        delete curr;
        return;
    }
//2. Node with 2 children
// replace node with smallest value in right subtree
    if (curr->left != NULL && curr->right != NULL)
    {
        tree_node* chkr;
        chkr = curr->right;
        if((chkr->left == NULL) && (chkr->right == NULL))
        {
            curr->data = chkr->data;
            delete chkr;
            curr->right = NULL;
        }
        else // right child has children
        {
//if the node's right child has a left child, move all the way down
// to the left to locate the smallest element
            if((curr->right)->left != NULL)
            {
                tree_node* lcurr;
                tree_node* lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != NULL)
                {
                    lcurrp = lcurr;
                    lcurr = lcurr->left;
                }
                curr->data = lcurr->data;
                delete lcurr;
                lcurrp->left = NULL;
            }// if ends
            else
            {
                tree_node* tmp;
                tmp = curr->right;
                curr->data = tmp->data;
                curr->right = tmp->right;
                delete tmp;
            }// else ends
        }// else ends
        return;
    }// if ends
}
