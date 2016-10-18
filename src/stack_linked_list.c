#include<stdlib.h>
#include "stack_linked_list.h"

struct node *create_stack(int data, struct node *list) {
  struct node *node;
  node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->next = NULL;
  list = node;
  return list;
}

struct node *push(int data, struct node *list) {
  struct node *node;
  node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->next = list;
  list = node;
  return list;
}

struct node *pop(struct node *list) {
  if (list == NULL)
    return NULL;
  list = list->next;
  return list;
}

int peek(struct node *list) {
  if (list == NULL)
    return -1;
  return list->data;
}
