#include "list_node.h"
#include "menu.h"
#include "list_menu.h"
#include "utility.h"

#include <stdio.h>
#include <stdbool.h>

void list_menu(struct ListNode**);
//void tree_menu(struct TreeNode**);

void menu(struct ListNode **list)
{
    while (true)
    {
        flush();
        printf("\033[H\033[2JWhat do you want to work with?\n");
        printf("1. Singly linked list\n"
               "2. Tree\n"
               "3. Exit");
        
        int answer = -1;
        read_int(&answer);
        switch (answer)
        {
        case 1:
            list_menu(list);
            break;

        case 2:
            printf("Not implemented!\n");
            break;

        case 3:
            return;
        default:
            printf("Sike, it's the wrong number!\n");
        }
    }
}
