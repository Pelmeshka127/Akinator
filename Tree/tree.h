#ifndef TREE_H_
#define TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "treeconfig.h"
#include "../Akinator_func/architecture.h"

struct tree_node {
    data_t data[Max_Size];
    tree_node * left;
    tree_node * right;
};

struct tree_s {
    tree_node * root;
    int size;               //number of the uneempty nodes
};

//-------------------------------------------------------------------------------//

/// @brief Function allocates memory for the root of the tree
/// @param my_tree is ptr on the tree struct
/// @param root is ptr on the tree's root
/// @param word is value of the root
/// @return nullptr is there's bad alloc, root if it's ok
int Tree_Ctor(tree_s * const my_tree);

//-------------------------------------------------------------------------------//

/// @brief Function allocates memory for the new node and inserts value to this node
/// @param my_tree is ptr on the tree struct
/// @param inserting_node is ptr on the inserting node
/// @param word is value of the node
/// @return nullptr if there's error, inserting_node if it's ok
tree_node * Tree_Insert_Node(tree_s * const my_tree, tree_node * inserting_node, const char * word);

//-------------------------------------------------------------------------------//

/// @brief 
/// @param my_tree 
/// @return 
int Tree_Walk_In_Order(tree_node * const root);

//-------------------------------------------------------------------------------//

/// @brief 
/// @param root 
/// @return 
int Tree_Walk_Pre_Order(tree_node * const root);

//-------------------------------------------------------------------------------//

/// @brief 
/// @param root 
/// @return 
int Tree_Walk_Post_Order(tree_node * const root);

//-------------------------------------------------------------------------------//

/// @brief Fuction cleans all of the nodes
/// @param root is ptr on the root of the tree
/// @return No_Error
int Tree_Clean(tree_node * const root);

//-------------------------------------------------------------------------------//

/// @brief Function destroys tree
/// @param my_tree is ptr on the tree struct
/// @return No_Error
int Tree_Dtor(tree_s * const my_tree);

//-------------------------------------------------------------------------------//

#endif