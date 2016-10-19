#include<stdlib.h>
#include "queue_linked_list.h"

struct node *create_queue(int data, struct node *list) {
  struct node *node;
  node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->next = NULL;
  list = node;
  return list;
}

struct node *enqueue(int data, struct node *list) {
  struct node *node, *ptr;
  ptr = list;
  node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->next = NULL;
  while (ptr->next != NULL)
    ptr = ptr->next;
  ptr->next = node;
  return list;
}

struct node *dequeue(struct node *list) {
  list = list->next;
  return list;
}
