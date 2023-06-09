#include "akinator.h"
#include <stdarg.h>


//-------------------------------------------------------------------------------//

/// @brief 
static void Skip_Spaces();

//-------------------------------------------------------------------------------//

/// @brief 
/// @param answer 
static void Input_Answer(int * answer);

//-------------------------------------------------------------------------------//

/// @brief 
/// @param string 
void Speaker(const char * string...);

//-------------------------------------------------------------------------------//

int Akinator_Download_Tree(tree_s * const my_tree, char * file_name)
{
    Text_Info onegin = {};

    FILE * src_file = fopen(file_name, "r");
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
        Speaker("Is he %s?\n", cur_node->data);

        int answer = 0;

        Input_Answer(&answer);

        if (answer == 'y')
            Speaker("Yes Sir. I'm nanomashine, son\n");
        
        else if (answer == 'n')
        {
            Speaker("Oh shit\n");
            Akinator_Add_New_Node(my_tree, cur_node);
        }
        
        return No_Error;
    }

    else
    {
        if (cur_node == my_tree->root)
            Speaker("Okaaaay, lets' go\n");

        Speaker("Is he %s?\n", cur_node->data);

        int answer = 0;
        
        Input_Answer(&answer);

        if (answer == 'y') 
            Akinator_Guessing(my_tree, cur_node->left);
        
        else if (answer == 'n')
            Akinator_Guessing(my_tree, cur_node->right);

        return No_Error;
    }
}

//-------------------------------------------------------------------------------//

int Akinator_Add_New_Node(tree_s * const my_tree, tree_node * const cur_node)
{
    assert(my_tree);

    char new_node[Max_Length] = {};

    Speaker("Who was that?\n");

    fgets(new_node, Max_Length, stdin);

    new_node[strlen(new_node) - 1] = '\0';

    char difference[Max_Length] = {};

    Speaker("What is the difference between %s and %s?\n", new_node, cur_node->data);

    fgets(difference, Max_Length, stdin);

    difference[strlen(difference) - 1] = '\0';

    cur_node->right = Tree_Insert_Node(my_tree, cur_node->right, cur_node->data);
    strncpy(cur_node->data, difference, Max_Length - 1);
    cur_node->left = Tree_Insert_Node(my_tree, cur_node->left, new_node);

    Speaker("Okay, now i'm cleverer than fucking you\n");

    return No_Error;
}

//-------------------------------------------------------------------------------//

int Akinator_Update_Data(tree_node * const cur_node, char * file_name)
{
    assert(cur_node);

    FILE * src_file = fopen(file_name, "w");
    if (src_file == nullptr)
    {
        fprintf(stderr, "Can't open file with tree in function %s\n", __PRETTY_FUNCTION__);
        return File_Error;
    }

    Akinator_Update_Tree_File(cur_node, src_file, 0);

    if (fclose(src_file) == EOF)
    {
        fprintf(stderr, "Failed clothing the source file in function %s\n", __PRETTY_FUNCTION__);
        return File_Error;
    }

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


tree_node * Tree_Find_Item(tree_s * const my_tree, Stack* stack, tree_node * const tree_root, char* item)
{
    assert(my_tree);

    if (tree_root == nullptr)
        return nullptr;

    Stack_Push(stack, tree_root);

    if (strcmp(item, tree_root->data) == 0)
        return tree_root;

    if (tree_root->left && Tree_Find_Item(my_tree, stack, tree_root->left, item))
        return stack->data[stack->size - 1];
    
    if (tree_root->right && Tree_Find_Item(my_tree, stack, tree_root->right, item))
        return stack->data[stack->size - 1];

    Stack_Pop(stack);

    return nullptr;
}

static void Skip_Spaces()
{
    while (getchar() != '\n');
}

//-------------------------------------------------------------------------------//

static void Input_Answer(int * answer)
{
    while ((*answer = getchar()) != EOF)
    {
        Skip_Spaces();

        if (strchr("yn", *answer) != nullptr)
            break;
        else
            printf("You entered incorect symbol\n");
    }
}

//-------------------------------------------------------------------------------//

int Check_Cmdline_Arg(int argc)
{
    if (argc != 2)
    {
        fprintf(stderr, "Error: wrong number of command line args: %d\n", argc);
        return Cmdline_Error;
    }
    return 0;
}

//-------------------------------------------------------------------------------//

void Speaker(const char * string...)
{
    va_list args = {0};
    va_start (args, string);

    char message[100] = {};

    vsprintf(message, string, args);

    printf("%s", message);

    char cmd[150] = {};

    sprintf(cmd, "espeak -s 150 -v ru \"%s\"", message);

    system(cmd);
}