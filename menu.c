#include "list_node.h"
#include "menu.h"
#include "list_menu.h"

#include <stdio.h>
#include <stdbool.h>

void list_menu(struct ListNode**);
//void tree_menu(struct TreeNode**);

void menu(struct ListNode **list)
{
    fflush(stdin);
    getchar();
    fflush(stdin);
    while (true)
    {
        printf("What do you want to work with?\n");
        printf("1. Singly linked list\n"
               "2. Tree\n");
        fflush(stdin);
        
        int answer = -1;
        if(!scanf("%d", &answer)) return;
        switch (answer)
        {
        case 1:
            list_menu(list);
            break;

        case 2:
            printf("Not implemented!\n");
            break;

        default:
            printf("Sike, it's the wrong number!\n");
        }
    }
}