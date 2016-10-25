#include<stdarg.h>
#include<stddef.h>
#include<setjmp.h>
#include<cmocka.h>
#include<stdlib.h>
#include "binary_search_tree.h"

static void is_empty_test(void **state) {
  (void) state;

  struct node *tree = NULL;
  assert_int_equal(is_empty(tree), 1);
}

static void insert_node_test(void **state) {
  (void) state;

  struct node *tree = NULL;
  tree = insert_node(2, tree);
  assert_int_equal(tree->data, 2);
  assert_null(tree->left);
  assert_null(tree->right);

  tree = insert_node(1, tree);
  assert_int_equal(tree->data, 2);
  assert_int_equal(tree->left->data, 1);
  tree = insert_node(5, tree);
  assert_int_equal(tree->right->data, 5);
}

static void find_min_test(void **state) {
  (void) state;
  struct node *tree = NULL;
  struct node *min = NULL;
  tree = insert_node(2, tree);
  tree = insert_node(6, tree);
  tree = insert_node(1, tree);
  min = find_min(tree);
  assert_int_equal(min->data, 1);
}

static void find_max_test(void **state) {
  (void) state;
  struct node *tree = NULL;
  struct node *max = NULL;
  tree = insert_node(2, tree);
  tree = insert_node(6, tree);
  tree = insert_node(1, tree);
  max = find_max(tree);
  assert_int_equal(max->data, 6);
}

static void find_test(void **state) {
  (void) state;
  struct node *tree = NULL;
  struct node *found = NULL;
  tree = insert_node(2, tree);
  tree = insert_node(6, tree);
  tree = insert_node(1, tree);
  found = find(6, tree);
  assert_int_equal(found->data, 6);
}

static void height_test(void **state) {
  (void) state;
  struct node *tree = NULL;
  int _height;
  tree = insert_node(2, tree);
  tree = insert_node(6, tree);
  tree = insert_node(1, tree);
  _height = height(tree);
  assert_int_equal(_height, 2);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(is_empty_test),
    cmocka_unit_test(insert_node_test),
    cmocka_unit_test(find_min_test),
    cmocka_unit_test(find_max_test),
    cmocka_unit_test(find_test),
    cmocka_unit_test(height_test),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
