#ifndef AKINATOR_FUNC_H_
#define AKINATOR FUNC_H_

#include "architecture.h"
#include "../Tree/tree.h"
#include "../Tree/dump.h"
#include "../Parsering/parser.h"
#include "../Stack/stack.h"

int Akinator_Download_Tree(tree_s * const my_tree);

int Akinator_Read_Tree(Text_Info * const Onegin, tree_s * const my_tree, tree_node ** cur_node);

int Akinator_Make_Node_Item(char * node_item, const char * line_start);

#endif