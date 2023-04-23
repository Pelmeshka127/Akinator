#include "Tree/tree.h"
#include "Tree/dump.h"
#include "Parsering/parser.h"
#include "Stack/stack.h"
#include "Akinator_func/akinator.h"

int main(int argc, char ** argv)
{
    if (Check_Cmdline_Arg(argc) == Cmdline_Error)
        return Cmdline_Error;

    Open_Log_File();

    tree_s my_tree = {};

    Akinator_Download_Tree(&my_tree, argv[1]);

    Stack stack = {};
    Stack_Ctor(&stack);

    Tree_Find_Item(&my_tree, &stack, my_tree.root, "Наташааа");

    Stack_Dtor(&stack);

    //Akinator_Guessing(&my_tree, my_tree.root);

    Akinator_Update_Data(my_tree.root, argv[1]);

    Tree_Dump(&my_tree);

    Tree_Dtor(&my_tree);

    Close_Log_File();

    return 0;
}