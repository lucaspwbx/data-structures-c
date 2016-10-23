#include<stdlib.h>
#include<stdio.h>
#include "binary_search_tree.h"

int is_empty(struct node *tree) {
  if (tree == NULL)
    return 1;
  return 0;
}

struct node *insert_node(int data, struct node *tree) {
  if (is_empty(tree)) {
    struct node *node;
    node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
  } 
  else {
    if (data < tree->data)  {
      tree->left = insert_node(data, tree->left);
    }
    else if (data > tree->data)
      tree->right = insert_node(data, tree->right);
  }
  return tree;
}
