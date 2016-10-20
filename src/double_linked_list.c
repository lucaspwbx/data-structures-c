#include<stdlib.h>
#include "double_linked_list.h"

struct node *create_list(int data, struct node *list) {
  struct node *node;
  node = (struct node *)malloc(sizeof(struct node));
  node->prev = NULL;
  node->data = data;
  node->next = NULL;
  list = node;
  return list;
}

struct node *insert_end(int data, struct node *list) {
  struct node *node, *ptr;
  ptr = list;
  node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->next = NULL;
  while (ptr->next != NULL)
    ptr = ptr->next;
  node->prev = ptr;
  ptr->next = node;
  return list;
}

struct node *insert_begin(int data, struct node *list) {
  struct node *node;
  node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->prev = NULL;
  node->next = list;
  list->prev = node;
  list = node;
  return list;
}

struct node *insert_after(int search_data, int data, struct node *list) {
  struct node *node, *ptr;
  ptr = list;
  node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  while (ptr != NULL && ptr->data != search_data)
    ptr = ptr->next;
  node->next = ptr->next;
  node->prev = ptr;
  ptr->next->prev = node;
  ptr->next = node;
  return list;
}

struct node *insert_before(int search_data, int data, struct node *list) {
  struct node *node, *ptr;
  ptr = list;
  node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  while (ptr != NULL && ptr->next->data != search_data)
    ptr = ptr->next;
  node->prev = ptr;
  node->next = ptr->next;
  ptr->next->prev = node;
  ptr->next = node;
  return list;
}

struct node *delete_node(int search_data, struct node *list) {
  return list;
}
