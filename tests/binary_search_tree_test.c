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

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(is_empty_test),
    cmocka_unit_test(insert_node_test),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
