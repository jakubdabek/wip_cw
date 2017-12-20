#include "tree_node.h"

#include <stddef.h>
#include <stdbool.h>

struct TreeNode* add(struct TreeNode **tree, int value)
{

}

void clear(struct TreeNode **tree)
{
    if(*tree == NULL) return;
    struct TreeNode *ptr1 = (*tree)->left, *ptr2 = NULL;

    while(true)
    {
        if((*tree)->right == NULL)
        {
            free(*tree);
            *tree = ptr1;
            if(ptr1 == NULL) return;
            ptr1 = ptr1->left;
        }
        else if(ptr1 != NULL)
        {
            ptr2 = ptr1->left;
            ptr1->left = *tree;
            (*tree)->left = ptr2;
            *tree = ptr1;
            ptr1 = ptr1->left;
        }
    }
}