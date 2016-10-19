#include<stdlib.h>
#include "single_linked_list.h"

struct node *create_list(int data, struct node *list) {
  struct node *node;
  node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->next = node;
  list = node;
  return list;
}

struct node *insert_end(int data, struct node *list) {
  struct node *node, *ptr;
  ptr = list;
  node = (struct node *)malloc(sizeof(struct node));
  while (ptr->next != list)
    ptr = ptr->next;
  node->data = data;
  node->next = list;
  ptr->next = node;
  return list;
}

struct node *insert_begin(int data, struct node *list) {
  return list;
}

struct node *insert_before(int search_data, int data, struct node *list) {
  return list;
}

struct node *insert_after(int search_data, int data, struct node *list) {
  return list;
}

struct node *delete_node(int search_data, struct node *list) {
  return list;
}
