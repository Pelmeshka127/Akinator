#ifndef TREE_H_
#define TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "architecture.h"
#include "treeconfig.h"

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

/// @brief 
/// @param my_tree 
/// @param root 
/// @param word 
/// @return 
int Tree_Ctor(tree_s * const my_tree, const char * word);

//-------------------------------------------------------------------------------//

/// @brief 
/// @param my_tree 
/// @param inserting_node 
/// @param word 
/// @return 
tree_node * Tree_Insert_Node(tree_s * const my_tree, tree_node * inserting_node, const char * word);

//-------------------------------------------------------------------------------//


#endif