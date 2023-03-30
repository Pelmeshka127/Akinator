#include "Tree/tree.h"
#include "Tree/dump.h"
#include "Parsering/parser.h"
#include "Stack/stack.h"
#include "Akinator_func/akinator.h"

int main(int argc, char ** argv)
{
    Open_Log_File();

    tree_s  my_tree = {};

    FILE * src_file = nullptr;

    Akinator_Download_Tree(&my_tree, src_file);

    Akinator_Guessing(&my_tree, my_tree.root);

    src_file = fopen("txt.txt", "w");

    Akinator_Update_Tree_File(my_tree.root, src_file, 0);

    fclose(src_file);

    Tree_Dump(&my_tree);

    Tree_Dtor(&my_tree);

    Close_Log_File();

    return 0;
}