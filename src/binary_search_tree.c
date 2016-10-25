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

struct node *find_min(struct node *tree) {
  if (tree == NULL)
    return NULL;
  if (tree->left)
    return find_min(tree->left);
  else
    return tree;
}

struct node *find_max(struct node *tree) {
  if (tree == NULL)
    return NULL;
  if (tree->right)
    return find_max(tree->right);
  else
    return tree;
}

struct node *find(int data, struct node *tree) {
  if (tree == NULL)
    return NULL;
  if (data < tree->data)
    return find(data, tree->left);
  else if (data > tree->data)
    return find(data, tree->right);
  else
    return tree;
}

int height(struct node *tree) {
  if (tree == NULL) return 0;
  return 1 + max(height(tree->left), height(tree->right));
}

int level(int data, struct node *tree) {
  if (tree == NULL) return 0;
  if (tree->data == data)
    return 1;
  if (data > tree->data)
    return 1 + level(data, tree->right);
  else if (data < tree->data)
    return 1 + level(data, tree->left);
}
