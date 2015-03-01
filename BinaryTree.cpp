/**
 * @file BinaryTree.cpp
 * @brief A Template for Binary Trees
 * @author Sohel Tarir
 * @version 1.0
 * @date 2014-09-18
 */

#include "BinaryTree.h"

bTree::bTree(){
    root = NULL;
}

bTree::~bTree(){
    destroy_tree();
}

void bTree::destroy_tree(node *leaf){
    if (leaf != NULL){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void bTree::insert(int key, node *leaf){
    if (key < leaf->key_value){
        if (leaf->left != NULL)
            insert(key, leaf->left);
        else{
            leaf->left = new node;
            leaf->left->key_value = key;
            leaf->left->left = NULL; //Sets the left child of the child node to null
            leaf->left->right = NULL; //Sets the right child of the child node to null
        }
    }
    else if (key >= leaf->key_value){
        if (leaf->right != NULL)
            insert(key, leaf->right);
        else{
            leaf->right = new node;
            leaf->right->key_value = key;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
    }
}

node *bTree::search(int key, node *leaf){
    if (leaf != NULL){
        if (key == leaf->key_value)
            return leaf;
        if (key < leaf->key_value)
            return search(key, leaf->left);
        else
            return search(key, leaf->right);
    }
    else
        return NULL;
}

void bTree::insert(int key){
    if (root != NULL)
        insert(key, root);
    else{
        root = new node;
        root->key_value = key;
        root->left = NULL;
        root->right = NULL;
    }
}

node* bTree::search(int key){
    return search(key, root);
}

void bTree::destroy_tree(){
    destroy_tree(root);
}
