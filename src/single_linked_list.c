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

struct node *insert_begin(int data, struct node *list) {
  struct node *node;
  node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->next = list;
  list = node;
  return list;
}

struct node *insert_after(int search_data, int data, struct node *list) {
  struct node *new_node, *ptr;
  ptr = list;
  while (ptr != NULL) {
    if (ptr->data == search_data) {
      new_node = (struct node *)malloc(sizeof(struct node));
      new_node->data = data;
      new_node->next = ptr->next;
      ptr->next = new_node;
      break;
    }
    ptr = ptr->next;
  }
  return list;
}
