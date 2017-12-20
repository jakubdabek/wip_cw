#pragma once

struct TreeNode 
{
    struct TreeNode *left, *right;
    int value;
};

struct TreeNode* add(struct TreeNode**, int);
void clear(struct TreeNode**);