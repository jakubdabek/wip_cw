#include "list_node.h"

#include <stdlib.h>
#include <stdio.h>

struct ListNode* make_new_node(int value, struct ListNode *next)
{
    struct ListNode *new_node = malloc(sizeof *new_node);
    new_node->value = value;
    new_node->next = next;

    return new_node;
}

void print(struct ListNode *ptr)
{
    if(!ptr) printf("Empty");
    while(ptr)
    {
        printf("%d ", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

struct ListNode* get_node_at(struct ListNode *node, size_t index)
{
    for(size_t i = 0; node && i < index; i++)
    {
        node = node->next;
    }

    return node;
}

struct ListNode* get_node_with_value(struct ListNode *node, int value)
{
    for(size_t i = 0; node && node->value != value; i++)
    {
        node = node->next;
    }

    return node;
}

int index_of_node(struct ListNode *node, int value)
{
    int i;
    for(i = 0; node && node->value != value; i++)
    {
        node = node->next;
    }

    return node ? i : -1;
}

struct ListNode* add_first(struct ListNode **ptr, int value)
{
    *ptr = make_new_node(value, *ptr);

    return *ptr;
}

struct ListNode* add_last(struct ListNode **ptr, int value)
{
    while(*ptr)
    {
        ptr = &((*ptr)->next);
    }
    
    *ptr = make_new_node(value, NULL);

    return *ptr;
}

struct ListNode* add_at(struct ListNode **ptr, size_t index, int value)
{
    size_t i;
    for(i = 0; *ptr && i < index - 1; i++)
    {
        ptr = &((*ptr)->next);
    }

    if(i != index - 1)
    {
        return NULL;
    }

    *ptr = make_new_node(value, (*ptr)->next);

    return *ptr;
}

struct ListNode* add_nonascending(struct ListNode **ptr, int value)
{
    while(*ptr && (*ptr)->value < value)
    {
        ptr = &((*ptr)->next);
    }

    *ptr = make_new_node(value, *ptr);

    return *ptr;
}

void remove_all(struct ListNode **ptr, int value)
{
    while(*ptr)
    {
        if((*ptr)->value == value)
        {
            struct ListNode *temp = (*ptr)->next;
            free(*ptr);
            *ptr = temp;
        }
        else
        {
            ptr = &((*ptr)->next);
        }
    }
}

void reverse(struct ListNode **ptr)
{
    struct ListNode *previous = NULL;
    struct ListNode *next = (*ptr)->next;

    while(next)
    {
        (*ptr)->next = previous;
        previous = *ptr;
        *ptr = next;
        next = next->next;
    }
    (*ptr)->next = previous;
}

void clear(struct ListNode **ptr)
{
    struct ListNode *temp;
    while(*ptr)
    {
        temp = *ptr;
        *ptr = temp->next;
        free(temp);
    }
}
