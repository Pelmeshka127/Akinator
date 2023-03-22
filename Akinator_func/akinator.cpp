#include "akinator.h"

//-------------------------------------------------------------------------------//

int Akinator_Download_Tree(tree_s * const my_tree)
{
    Text_Info onegin = {};

    FILE * input_file = fopen("txt.txt", "r");
    if (input_file == nullptr)
    {
        fprintf(stderr, "Can't open file with tree in function %s\n", __PRETTY_FUNCTION__);
        return File_Error;
    }

    if (Onegin_Read(&onegin, input_file) != No_Error)
    {
        fprintf(stderr, "Failed parsering source text in function %s\n", __PRETTY_FUNCTION__);
        return File_Error;
    }

    if (fclose(input_file) == EOF)
    {
        fprintf(stderr, "Failed clothing the source file in function %s\n", __PRETTY_FUNCTION__);
        return File_Error;
    }

    Tree_Ctor(my_tree);

    if (Akinator_Read_Tree(&onegin, my_tree, &my_tree->root) != No_Error)
    {
        fprintf(stderr, "Reading of thr tree failed ion function %s\n", __PRETTY_FUNCTION__);
        return File_Error;
    }

    Tree_Dump(my_tree);

    Tree_Dtor(my_tree);

    return No_Error;
}

//-------------------------------------------------------------------------------//

int Akinator_Read_Tree(Text_Info * const onegin, tree_s * const my_tree, tree_node ** cur_node)
{
    assert(onegin);
    assert(my_tree);

    if (**onegin->pointers == '{')
    {
        while (**onegin->pointers != '\"')
            (*onegin->pointers)++;

        char node_item[Max_Length] = "";

        Akinator_Make_Node_Item(node_item, *onegin->pointers);

        *cur_node = Tree_Insert_Node(my_tree, my_tree->root, node_item);
    

        while (**onegin->pointers != '{' && **onegin->pointers != '}')
            (*onegin->pointers)++;

        if (**onegin->pointers == '}')
            return No_Error;

        Akinator_Read_Tree(onegin, my_tree, &(*cur_node)->left);

        while (**onegin->pointers != '{')
            (*onegin->pointers)++;

        Akinator_Read_Tree(onegin, my_tree, &(*cur_node)->right);
    }


    return No_Error;
}

//-------------------------------------------------------------------------------//

int Akinator_Make_Node_Item(char * node_item, const char * line_start)
{
    assert(node_item);
    assert(line_start);

    line_start = strchr (line_start, '\"');
    line_start += 1;
    const char * line_end = strchr (line_start, '\"');

    if (line_start == nullptr || line_end == nullptr)
    {
        fprintf(stderr, "Incorrect item of the node\n");
        return File_Error;
    }

    strncpy(node_item, line_start, (size_t) (line_end - line_start));

    return No_Error;
}

//-------------------------------------------------------------------------------//