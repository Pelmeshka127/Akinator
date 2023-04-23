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
int Akinator_Download_Tree(tree_s * const my_tree, char * file_name);

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

//-------------------------------------------------------------------------------//

/// @brief 
/// @param my_tree 
/// @param cur_node 
/// @return 
int Akinator_Guessing(tree_s * const my_tree, tree_node * cur_node);

//-------------------------------------------------------------------------------//

/// @brief 
/// @param my_tree 
/// @param cur_node 
/// @return 
int Akinator_Add_New_Node(tree_s * const my_tree, tree_node * const cur_node);

//-------------------------------------------------------------------------------//

/// @brief 
/// @param cur_node 
/// @param src_file 
/// @param tabular_count 
/// @return 
int Akinator_Update_Tree_File(tree_node * const cur_node, FILE * src_file, int tabular_count);

//-------------------------------------------------------------------------------//

/// @brief 
/// @param cur_node 
/// @return 
int Akinator_Update_Data(tree_node * const cur_node, char * file_name);

//-------------------------------------------------------------------------------//

tree_node * Tree_Find_Item(tree_s * const my_tree, Stack* stack, tree_node * const tree_root, char* item);

/// @brief 
/// @param argc 
/// @return 
int Check_Cmdline_Arg(int argc);

//-------------------------------------------------------------------------------//

#endif