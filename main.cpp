#include "Tree/tree.h"
#include "Tree/dump.h"
#include "Parsering/parser.h"
#include "Stack/stack.h"
#include "Akinator_func/akinator.h"

int main()
{
    Open_Log_File();

    tree_s  my_tree = {};

    /*Tree_Ctor(&my_tree);

    my_tree.root = Tree_Insert_Node(&my_tree, my_tree.root, "foo");
    my_tree.root->left = Tree_Insert_Node(&my_tree, my_tree.root->left, "bar");
    my_tree.root->right = Tree_Insert_Node(&my_tree, my_tree.root->right, "abr");
    my_tree.root->left->left = Tree_Insert_Node(&my_tree, my_tree.root->left->left, "aca");
    my_tree.root->left->left->left = Tree_Insert_Node(&my_tree, my_tree.root->left->left->left, "dab");
    my_tree.root->left->right = Tree_Insert_Node(&my_tree, my_tree.root->left->right, "ra");

    Tree_Dump(&my_tree);

    Tree_Dtor(&my_tree);*/

    Akinator_Download_Tree(&my_tree);

    Close_Log_File();

    /*FILE * fp = fopen("txt.txt", "r");

    Text_Info onegin = {};

    Onegin_Read(&onegin, fp);

    printf("%s\n", strchr(onegin.pointers[1], '\"'));

    fclose(fp);


    char node_item[Max_Length] = "";
    const char * line_start = strchr (onegin.pointers[0], '{');

    printf("%s\n", line_start);

    printf("%s\n", node_item);

    printf("%s\n", line_start[1]);

    Onegin_Dtor(&onegin);*/

    return 0;
}