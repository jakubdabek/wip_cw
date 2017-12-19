#include "list_node.h"
#include "menu.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define SIZEOF(t) sizeof((t)) / sizeof(*(t))

int main(void)
{
    srand(time(NULL));

    struct ListNode *first_node = NULL;
    int to_add_nonascending[] = { 3, 5, 2, 2, 4, 4 };
    for(int i = 0; i < SIZEOF(to_add_nonascending); i++)
    {
        add_nonascending(&first_node, to_add_nonascending[i]);
        print(first_node);
    }

    for(int i = 0; i < 4; i++)
    {
        int to_be_added = (rand() % 10) + 16;
        printf("adding %d last\n", to_be_added);
        add_last(&first_node, to_be_added);
        print(first_node);
    }

    for(int i = 0; i < 4; i++)
    {
        int to_be_added = (rand() % 10) + 6;
        printf("adding %d first\n", to_be_added);
        add_first(&first_node, to_be_added);
        print(first_node);
    }

    getchar();
    menu(&first_node);

    clear(&first_node);
    return 0;
}
