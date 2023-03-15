#include "../includes/tree.h"
#include "../includes/dump.h"

int main()
{
    Open_Log_File();

    tree_s  my_tree = {};

    Tree_Ctor(&my_tree,  "Root");

    tree_node * root = my_tree.root;

    //Tree_Insert_Node(&my_tree, root->left, "left");
    //Tree_Insert_Node(&my_tree, root->right, "right");

    Close_Log_File();


    return 0;
}