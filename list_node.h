#pragma once

#include <stddef.h>

struct ListNode
{
    int value;
    struct ListNode *next;
};

struct ListNode* make_new_node(int, struct ListNode*);
void print(struct ListNode*);
struct ListNode* get_node_at(struct ListNode*, size_t);
struct ListNode* add_first(struct ListNode**, int);
struct ListNode* add_last(struct ListNode**, int);
struct ListNode* add_nonascending(struct ListNode**, int);
void remove_all(struct ListNode**, int);
void reverse(struct ListNode**);
void clear(struct ListNode**);