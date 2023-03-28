#include "Tree/tree.h"
#include "Tree/dump.h"
#include "Parsering/parser.h"
#include "Stack/stack.h"
#include "Akinator_func/akinator.h"

int main()
{
    Open_Log_File();

    tree_s  my_tree = {};

    Akinator_Download_Tree(&my_tree);

    Tree_Dump(&my_tree);

    Akinator_Guessing(&my_tree, my_tree.root);

    Tree_Dtor(&my_tree);

    Close_Log_File();

    return 0;
}