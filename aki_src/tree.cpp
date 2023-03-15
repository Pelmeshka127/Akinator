#include "../includes/tree.h"
#include "../includes/dump.h"

//-------------------------------------------------------------------------------//

FILE * log_file = nullptr;

//-------------------------------------------------------------------------------//

int Tree_Ctor(tree_s * const my_tree, const char * word)
{
    my_tree->size = 1;

    my_tree->root = (tree_node *)calloc (1, sizeof(tree_node));
    if (my_tree->root == nullptr)
    {
        fprintf(stderr, "Failed allocation memory for tree root in function %s\n", __PRETTY_FUNCTION__);
        return Bad_Alloc;
    }

    my_tree->root->left = my_tree->root->right = nullptr;
    strcpy(my_tree->root->data, word);

    Tree_Dump(my_tree);

    return No_Error;
}

//-------------------------------------------------------------------------------//

tree_node * Tree_Insert_Node(tree_s * const my_tree, tree_node * inserting_node, const char * word)
{
    assert(my_tree);

    if (inserting_node != nullptr)
    {
        fprintf(stderr, "Incorrect adress of node %p."
                        "You cannot insert there because it isn't empty\n", inserting_node);
        return nullptr;
    }

    inserting_node = (tree_node *)calloc (1, sizeof(tree_node));
    if (inserting_node == nullptr)
    {
        fprintf(stderr, "Failed allocation new node in function %s\n", __PRETTY_FUNCTION__);
        return nullptr;
    }

    strcpy(inserting_node->data, word);
    inserting_node->left  = nullptr;
    inserting_node->right = nullptr;

    my_tree->size++;

    return inserting_node;

}

//-------------------------------------------------------------------------------//