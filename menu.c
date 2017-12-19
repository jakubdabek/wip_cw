#include "list_node.h"
#include "menu.h"
#include "list_menu.h"

#include <stdio.h>
#include <stdbool.h>

void list_menu(struct ListNode**);
//void tree_menu(struct TreeNode**);

static void flush() { char c; while ((c = getchar()) != '\n' && c != EOF){} }

void menu(struct ListNode **list)
{
    while (true)
    {
        flush();
        printf("\033[H\033[2JWhat do you want to work with?\n");
        printf("1. Singly linked list\n"
               "2. Tree\n");
        
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
