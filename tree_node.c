#include "tree_node.h"

#include <stddef.h>
#include <stdbool.h>

struct TreeNode* add(struct TreeNode **tree, int value)
{

}

void clear(struct TreeNode **tree)
{
    struct TreeNode **node = tree;
    
    while(*node)
    {
        node = &((*node)->left);
    }
    while(*tree)
    {
        *node = (*tree)->right;
        while(*node)
        {
            node = &((*node)->left);
        }
        struct TreeNode *tmp = (*tree)->left;
        free(*tree);
        *tree = tmp;
    }
}

void clear2(struct TreeNode **tree)
{
    struct TreeNode *current = *tree;
    while(*tree)
    {
        if(current->left)
        {
            current = current->left;
        }
        else
        {
            current->left = (*tree)->left;
            struct TreeNode *tmp = (*tree)->left;
            if(current == *tree)
                current = current->left;
            free(*tree);
            *tree = tmp;
        }
        
    }
}