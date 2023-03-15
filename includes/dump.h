#ifndef DUMP_H_
#define DUMP_H_

#include "tree.h"

#define TREE_DUMP

//-------------------------------------------------------------------------------//

/// @brief 
/// @return 
int Open_Log_File();

/// @brief 
/// @return 
int Close_Log_File();

/// @brief 
/// @param my_tree 
int Tree_Dump(tree_s * const my_tree);

//-------------------------------------------------------------------------------//

#endif