#include<stdlib.h>
#include "single_linked_list.h"

struct node *create_list(int data, struct node *list) {
  struct node *node;
  node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->next = NULL;
  list = node;
  return list;
}

struct node *insert_end(int data, struct node *list) {
  struct node *node, *ptr;
  ptr = list;
  while (ptr->next != NULL)
    ptr = ptr->next;
  node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->next = NULL;
  ptr->next = node;
  return list;
}
