#include<stdlib.h>
#include "circular_double_linked_list.h"

struct node *create_list(int data, struct node *list) {
  struct node *node;
  node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->prev = node;
  node->next = node;
  list = node;
  return list;
}

struct node *insert_end(int data, struct node *list) {
  struct node *node, *ptr;
  ptr = list;
  node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  while (ptr->next != list)
    ptr = ptr->next;
  node->prev = ptr->prev;
  node->next = ptr->next;
  list->prev = node;
  ptr->next = node;
  return list;
}

struct node *insert_begin(int data, struct node *list) {
  struct node *node;
  node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->prev = list->prev;
  node->next = list;
  list->prev->next = node;
  list = node;
  return list;
}

struct node *insert_after(int search_data, int data, struct node *list) {
  struct node *node, *ptr;
  ptr = list;
  node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  while (ptr->next != list && ptr->data != search_data)
    ptr = ptr->next;
  node->prev = ptr;
  node->next = ptr->next;
  ptr->next = node;
  ptr->next->prev = node;
  return list;
}

struct node *insert_before(int search_data, int data, struct node *list) {
  return list;
}

// adapt to circular double linked list
struct node *delete_node(int search_data, struct node *list) {
  struct node *ptr;
  ptr = list;
  if (ptr->data == search_data) {
    ptr->next->next = ptr->next;
    list = ptr->next;
    return list;
  }
  while (ptr->next != list && ptr->next->data != search_data) {
    ptr = ptr->next;
  }
  // searched node is the "last" node
  if (ptr->next->next == list) {
    ptr->next = list;
  // searched node is in the middle of the list
  } else {
    ptr->next = ptr->next->next;
  }
  return list;
}
