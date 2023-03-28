#ifndef AKINATOR_FUNC_H_
#define AKINATOR FUNC_H_

#include "architecture.h"
#include "../Tree/tree.h"
#include "../Tree/dump.h"
#include "../Parsering/parser.h"
#include "../Stack/stack.h"

//-------------------------------------------------------------------------------//

/// @brief Function makes tree from source file
/// @param my_tree is ptr on the tree struct
/// @return File_Error if creating tree failed, No_Error if it's ok
int Akinator_Download_Tree(tree_s * const my_tree);

//-------------------------------------------------------------------------------//

/// @brief Function 
/// @param Onegin 
/// @param my_tree 
/// @param cur_node 
/// @return 
int Akinator_Read_Tree(Text_Info * const Onegin, tree_s * const my_tree, tree_node ** cur_node);

//-------------------------------------------------------------------------------//

/// @brief 
/// @param node_item 
/// @param line_start 
/// @return 
int Akinator_Make_Node_Item(char * node_item, const char * line_start);


int Akinator_Guessing(tree_s * const my_tree, tree_node * const cur_node);

//-------------------------------------------------------------------------------//

#endif