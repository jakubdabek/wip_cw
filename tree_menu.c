#include "tree_menu.h"
#include "tree_node.h"

#include <stdio.h>
#include <stdbool.h>

static void option_print_list(struct TreeNode**);
static void option_print_element(struct TreeNode**);
static void option_add_first(struct TreeNode**);
static void option_add_last(struct TreeNode**);
static void option_add_nonascending(struct TreeNode**);
static void option_reverse(struct TreeNode**);
static void option_remove_occurences(struct TreeNode**);
static void option_clear(struct TreeNode**);

void tree_menu(struct TreeNode **tree)
{
    while (true)
    {
        //flush();
        printf("\033[H\033[2J" "List: ");
        print(*tree);
        printf("\nWhat do you want to do?\n");
        printf("1. Print the tree\n"
               "2. Print an element at a given index\n"
               "3. Add at the beginning\n"
               "4. Add at the end\n"
               "5. Add non-ascending\n"
               "6. Reverse the tree\n"
               "7. Remove all occurences of a given value\n"
               "8. Clear the tree\n"
               "9. Exit\n");

        int answer = -1;
        read_int(&answer);
        
        switch (answer)
        {
        case 1:
            option_print_tree(tree);
            break;
        case 2:
            option_print_element(tree);
            break;
        case 3:
            option_add_first(tree);
            break;
        case 4:
            option_add_last(tree);
            break;
        case 5:
            option_add_nonascending(tree);
            break;
        case 6:
            option_reverse(tree);
            break;
        case 7:
            option_remove_occurences(tree);
            break;
        case 8:
            option_clear(tree);
            break;
        case 9:
            return;
        default:
            printf("WRONG NUMBER FFS");
        }
    }
}