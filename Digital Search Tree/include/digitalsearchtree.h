#ifndef DIGITALSEARCHTREE_H
#define DIGITALSEARCHTREE_H
#include<iostream>
#include<string>
using namespace std;

class DigitalSearchTree
{
    public:
        DigitalSearchTree();
        bool isEmpty();
        void insertElement(string);
        void removeElement(string);
        bool searchElement(string);
        void print_tree_inorder();
        void print_tree_preorder();
        void print_tree_postorder();
        void makeTreeEmpty();
        int CountNode();

    private:
        struct tree_node
    {
        tree_node* left;
        tree_node* right;
        string data;
    };
        int pos;//Level count
        tree_node* root;
        void makeEmpty(tree_node*&);
        void inorder(tree_node*);
        void preorder(tree_node*);
        void postorder(tree_node*);
        int counts(tree_node*);//Helper function
        bool findx(tree_node*,string);//Helper Function
};

#endif // DIGITALSEARCHTREE_H
