i#include<stdlib.h>
#include "double_linked_list.h"

struct node *create_list(int data, struct node *list) {
  struct node *node;
  node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->next = NULL;
  list = node;
  return list;
}

struct node *insert_end(int data, struct node *list) {
}

struct node *insert_begin(int data, struct node *list) {
}

struct node *insert_after(int search_data, int data, struct node *list) {
}

struct node *insert_before(int search_data, int data, struct node *list) {
}

struct node *delete_node(int search_data, struct node *list) {
}
