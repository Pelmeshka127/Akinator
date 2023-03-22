#include "tree.h"
#include "dump.h"

//-------------------------------------------------------------------------------//

FILE * log_file = nullptr;

//-------------------------------------------------------------------------------//

int Tree_Ctor(tree_s * const my_tree)
{
    my_tree->size = 0;

    my_tree->root = nullptr;

    return No_Error;
}

//-------------------------------------------------------------------------------//

tree_node * Tree_Insert_Node(tree_s * const my_tree, tree_node * inserting_node, const char * word)
{
    assert(my_tree);

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

int Tree_Walk_In_Order(tree_node * const root)
{
    assert(root);

    if (root->left != nullptr)
        Tree_Walk_In_Order(root->left);    

    printf("%s\n", root->data);

    if (root->right != nullptr)
        Tree_Walk_In_Order(root->right);
    
    return No_Error;
}

//-------------------------------------------------------------------------------//

int Tree_Walk_Pre_Order(tree_node * const root)
{
    assert(root);

    printf("%s\n", root->data);
    
    if (root->left != nullptr)
        Tree_Walk_Pre_Order(root->left);

    if (root->right != nullptr)
        Tree_Walk_Pre_Order(root->right);

    return No_Error;
}

//-------------------------------------------------------------------------------//

int Tree_Walk_Post_Order(tree_node * const root)
{
    assert(root);

    if (root->left != nullptr)
        Tree_Walk_Post_Order(root->left);
    
    if (root->right != nullptr) 
        Tree_Walk_Post_Order(root->right);

    printf("%s\n", root->data);

    return No_Error;
}

//-------------------------------------------------------------------------------//

int Tree_Clean(tree_node * const root)
{
    assert(root);

    if (root->left != nullptr)
        Tree_Clean(root->left);

    if (root->right != nullptr)
        Tree_Clean(root->right);

    free(root->data);

    return No_Error;
}

//-------------------------------------------------------------------------------//

int Tree_Dtor(tree_s * const my_tree)
{
    assert(my_tree);

    Tree_Clean(my_tree->root);

    my_tree->root = nullptr;

    my_tree->size = 0;

    return No_Error;
}

//-------------------------------------------------------------------------------//