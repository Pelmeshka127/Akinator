#include "akinator.h"

/// @brief 
static void Skip_Spaces();

//-------------------------------------------------------------------------------//

int Akinator_Download_Tree(tree_s * const my_tree, FILE * src_file)
{
    Text_Info onegin = {};

    src_file = fopen("txt.txt", "r");
    if (src_file == nullptr)
    {
        fprintf(stderr, "Can't open file with tree in function %s\n", __PRETTY_FUNCTION__);
        return File_Error;
    }

    if (Onegin_Read(&onegin, src_file) != No_Error)
    {
        fprintf(stderr, "Failed parsering source text in function %s\n", __PRETTY_FUNCTION__);
        return File_Error;
    }

    if (fclose(src_file) == EOF)
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

    return No_Error;
}

//-------------------------------------------------------------------------------//

int Akinator_Read_Tree(Text_Info * const onegin, tree_s * const my_tree, tree_node ** cur_node)
{
    assert(onegin);
    assert(my_tree);

    while (**onegin->pointers != '{')
        (*onegin->pointers)++;

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

int Akinator_Guessing(tree_s * const my_tree, tree_node * const cur_node)
{
    assert(my_tree);

    if (cur_node->right == nullptr && cur_node->left == nullptr)
    {
        printf("Он %s?\n", cur_node->data);
        char answer[Max_Size] = { };
        scanf("%s", answer);

        if (strcmp(answer, "yes") == 0)
            printf("Сюда! Я гений\n");
        
        else if (strcmp(answer, "no") == 0)
        {
            printf("Фак, меня наебали(((\n");
            Akinator_Add_New_Node(my_tree, cur_node);
        }
        
        return No_Error;
    }

    else
    {
        if (cur_node == my_tree->root)
            printf("Погнали сучки, я знаю все нахой\n");

        printf("Он %s?\n", cur_node->data);
        char answer[Max_Size] = {};
        scanf("%s", answer);

        if (strcmp(answer, "yes") == 0) 
            Akinator_Guessing(my_tree, cur_node->left);
        
        else if (strcmp(answer, "no") == 0)
            Akinator_Guessing(my_tree, cur_node->right);

        return No_Error;
    }
}

//-------------------------------------------------------------------------------//

int Akinator_Add_New_Node(tree_s * const my_tree, tree_node * const cur_node)
{
    assert(my_tree);

    char new_node[Max_Length] = {};

    printf("Це кто?\n");

    Skip_Spaces();

    fgets(new_node, Max_Length, stdin);

    new_node[strlen(new_node) - 1] = '\0';

    char difference[Max_Length] = {};

    printf("В чем разница между %s и %s?\n", new_node, cur_node->data);

    fgets(difference, Max_Length, stdin);

    difference[strlen(difference) - 1] = '\0';

    cur_node->right = Tree_Insert_Node(my_tree, cur_node->right, cur_node->data);
    strncpy(cur_node->data, difference, Max_Length - 1);
    cur_node->left = Tree_Insert_Node(my_tree, cur_node->left, new_node);

    return No_Error;
}

//-------------------------------------------------------------------------------//

int Akinator_Update_Tree_File(tree_node * const cur_node, FILE * src_file, int tabular_count)
{
    for (int count = 0; count < tabular_count; count++)
        fprintf(src_file, "\t");
        
    fprintf(src_file, "{\"%s\"", cur_node->data);

    if (cur_node->left == nullptr & cur_node->right == nullptr)
        fprintf(src_file, "}");
    
    fprintf(src_file, "\n");

    if (cur_node->left != nullptr)
        Akinator_Update_Tree_File(cur_node->left, src_file, tabular_count + 1);
    
    if (cur_node->right != nullptr)
        Akinator_Update_Tree_File(cur_node->right, src_file, tabular_count + 1);

    if (cur_node->left != nullptr && cur_node->right != nullptr)
    {
        for (int count = 0; count < tabular_count; count++)
            fprintf(src_file, "\t");
        fprintf(src_file, "}\n");
    }

    return No_Error;  
}

//-------------------------------------------------------------------------------//

static void Skip_Spaces()
{
    while (getchar() != '\n');
}