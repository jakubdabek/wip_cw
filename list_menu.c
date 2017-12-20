#include "list_node.h"
#include "list_menu.h"
#include "utility.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static void option_print_list(struct ListNode **);
static void option_print_element(struct ListNode **);
static void option_add_first(struct ListNode **);
static void option_add_last(struct ListNode **);
static void option_add_nonascending(struct ListNode **);
static void option_reverse(struct ListNode **);
static void option_remove_occurences(struct ListNode **);
static void option_clear(struct ListNode **);

void list_menu(struct ListNode **list)
{
    while (true)
    {
        //flush();
        printf("\033[H\033[2J" "List: ");
        print(*list);
        printf("\nWhat do you want to do?\n");
        printf("1. Print the list\n"
               "2. Print an element at a given index\n"
               "3. Add at the beginning\n"
               "4. Add at the end\n"
               "5. Add non-ascending\n"
               "6. Reverse the list\n"
               "7. Remove all occurences of a given value\n"
               "8. Clear the list\n"
               "9. Exit\n");

        int answer = -1;
        char buffer[50];
        read(buffer, 50);
        
        printf("%d\n", answer);
        switch (answer)
        {
        case 1:
            option_print_list(list);
            break;
        case 2:
            option_print_element(list);
            break;
        case 3:
            option_add_first(list);
            break;
        case 4:
            option_add_last(list);
            break;
        case 5:
            option_add_nonascending(list);
            break;
        case 6:
            option_reverse(list);
            break;
        case 7:
            option_remove_occurences(list);
            break;
        case 8:
            option_clear(list);
            break;
        case 9:
            return;
        default:
            printf("WRONG NUMBER FFS");
        }
    }
}

static void option_print_list(struct ListNode **list)
{
    print(*list);
}

static void option_print_element(struct ListNode **list)
{
    printf("Enter an index:\n");
    while (true)
    {
        int index =  -1;
        int success = read_int(&index);
        if (success < 1 || index < 0)
            break;
        struct ListNode *node = get_node_at(*list, index);
        char write_buffer[15];
        printf("Node at %d %s\n", index, 
            node ? snprintf(write_buffer, 15, "has value %d", node->value), write_buffer : "is out of range");
    }
}

static void option_add_first(struct ListNode **list)
{
    printf("Enter a value:\n");
    while (true)
    {
        int value = 0;
        int success = read_int(&value);
        if (success < 1)
            break;
        add_first(list, value);
        printf("Added node with value %d at the beginning\n", value);
    }
}

static void option_add_last(struct ListNode **list)
{
    printf("Enter a value:\n");
    while (true)
    {
        int value = 0;
        int success = read_int(&value);
        if (success < 1)
            break;
        add_last(list, value);
        printf("Added node with value %d at the end\n", value);
    }
}

static void option_add_nonascending(struct ListNode **list)
{
    printf("Enter a value:\n");
    while (true)
    {
        int value = 0;
        int success = read_int(&value);
        if (success < 1)
            break;
        add_nonascending(list, value);
        printf("Added node with value %d at position %d\n", value, index_of_node(*list, value));
    }
}

static void option_reverse(struct ListNode **list)
{
    reverse(list);
    printf("List reversed\n");
}

static void option_remove_occurences(struct ListNode **list)
{
    printf("Enter a value to remove:\n");
    while (true)
    {
        int value = 0;
        int success = read_int(&value);
        if (success < 1)
            break;
        remove_all(list, value);
        printf("Removed occurences of %d", value);
    }
}

static void option_clear(struct ListNode **list)
{
    printf("Do you really want to clear the list? [Y/N]\n");
    char answer = 'N';
    scanf("%c", &answer);
    flush();
    if (answer == 'Y' || answer == 'y')
    {
        clear(list);
        printf("List cleared\n");
    }
}
