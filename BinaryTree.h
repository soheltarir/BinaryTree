/**
 * @file BinaryTree.h
 * @brief A Template for Binary Trees
 * @author Sohel Tarir
 * @version 1.0
 * @date 2014-09-18
 */

#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <stdio.h>
#include <iostream>

struct node{
    int key_value;
    node *left;
    node *right;
};

class bTree{
    public:
        bTree();
        ~bTree();

        void insert(int key);
        node *search(int key);
        void destroy_tree();
    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);
        node *root;
};

#endif
