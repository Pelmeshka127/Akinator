#include "dump.h"

//-------------------------------------------------------------------------------//

static FILE * log_file = nullptr;

static int graph_num  = 1;

//-------------------------------------------------------------------------------//

int Open_Log_File()
{
    log_file = fopen("graphics/log.html", "w");
    if (log_file == nullptr)
    {
        fprintf(stderr, "Failed openning log.html in function %s\n", __PRETTY_FUNCTION__);
        return File_Error;
    }
    return No_Error;
}

//-------------------------------------------------------------------------------//

int Close_Log_File()
{
    if (fclose(log_file) == EOF)
    {
        fprintf(stderr, "Failed closing log.html in function %s\n", __PRETTY_FUNCTION__);
        return File_Error;
    }
    return No_Error;
}

//-------------------------------------------------------------------------------//

int Tree_Dump(tree_s * const my_tree)
{
#ifdef TREE_DUMP

    assert(my_tree);

    FILE * graph_file = fopen("graphics/graph.dot", "w");
    if (graph_file == nullptr)
    {
        fprintf(stderr, "Failed openning graph.dot in function %s\n", __PRETTY_FUNCTION__);
        return File_Error;
    }

    fprintf(graph_file, "digraph Tree\n{\n");
    fprintf(graph_file, "   rankdir = HR;\n");
    fprintf(graph_file, "   node[fontsize=14];\n   edge[color=\"black\",fontcolor=\"blue\",fontsize=12];\n");
    fprintf(graph_file, "   tree[shape = Mrecord, style = filled, filcolor = \"red\", "
                        "label = \"My Tree | size = %d\"];\n", my_tree->size);
    Tree_Draw(my_tree->root, graph_file);
    fprintf(graph_file, "   tree -> \"%s\" [color = \"red\"];\n", my_tree->root->data);
    fprintf(graph_file, "}");

    if (fclose(graph_file) == EOF)
    {
        fprintf(stderr, "Failed closing graph.dot in function %s\n", __PRETTY_FUNCTION__);
        return File_Error;
    }

    char call_graph[100] = " ";

    sprintf(call_graph, "dot graphics/graph.dot -Tpng -o graphics/gpaph%d.png", graph_num++);
    
    system(call_graph);

    fprintf(log_file, "<pre>\n");
    fprintf(log_file, "\n<image src = \"gpaph%d.png\" /image>\n\n\n", graph_num - 1);

    return No_Error;

#endif
}

//-------------------------------------------------------------------------------//

void Tree_Draw(tree_node * const root, FILE * graph_file)
{
    assert(root);

    fprintf(graph_file, "   \"%s\"[shape = Mrecord, style = filled, fillcolor = \"lightgoldenrod\","
                        "   label = \" <value> %s\"];\n", root->data, root->data);
    
    if (root->left != nullptr)
        fprintf(graph_file, "  \"%s\" -> \"%s\" [color = \"green\"];\n", root->data, root->left->data);

    if (root->right != nullptr)
        fprintf(graph_file, "  \"%s\" -> \"%s\" [color = \"red\"];\n", root->data, root->right->data);

    if (root->left != nullptr)
        Tree_Draw(root->left, graph_file);

    if (root->right != nullptr)
        Tree_Draw(root->right, graph_file);
}

//-------------------------------------------------------------------------------//