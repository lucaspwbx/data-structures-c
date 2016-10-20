#include<stdarg.h>
#include<stddef.h>
#include<setjmp.h>
#include<cmocka.h>
#include<stdlib.h>
#include "double_linked_list.h"

static void create_list_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_list(5, list);
  assert_int_equal(list->data, 5);
  assert_null(list->prev);
  assert_null(list->next);
}

static void insert_end_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_list(5, list);
  list = insert_end(10, list);
  assert_int_equal(list->data, 5);
  assert_null(list->prev);
  assert_non_null(list->next);
  assert_int_equal(list->next->data, 10);
  assert_null(list->next->next);
}

static void insert_begin_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_list(5, list);
  list = insert_begin(10, list);
  assert_int_equal(list->data, 10);
  assert_null(list->prev);
  assert_non_null(list->next);
  assert_int_equal(list->next->data, 5);
  assert_null(list->next->next);
}

static void insert_after_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_list(5, list);
  list = insert_end(10, list);
  list = insert_after(5, 7, list);
  assert_int_equal(list->data, 5);
  assert_null(list->prev);
  assert_non_null(list->next);
  assert_int_equal(list->next->data, 7);
  assert_non_null(list->next->next);
  assert_int_equal(list->next->next->data, 10);
  assert_null(list->next->next->next);
}

static void insert_before_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_list(5, list);
  list = insert_end(10, list);
  list = insert_before(10, 7, list);
  assert_int_equal(list->data, 5);
  assert_null(list->prev);
  assert_non_null(list->next);
  assert_int_equal(list->next->data, 7);
  assert_non_null(list->next->next);
  assert_int_equal(list->next->next->data, 10);
  assert_null(list->next->next->next);
}

static void delete_first_node_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_list(5, list);
  list = insert_end(10, list);
  list = delete_node(5, list);
  assert_int_equal(list->data, 10);
  assert_null(list->next);
  assert_null(list->prev);
}

static void delete_end_node_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_list(5, list);
  list = insert_end(10, list);
  list = delete_node(10, list);
  assert_int_equal(list->data, 5);
  assert_null(list->next);
  assert_null(list->prev);
}

static void delete_middle_node_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_list(5, list);
  list = insert_end(7, list);
  list = insert_end(10, list);
  list = delete_node(7, list);
  assert_int_equal(list->data, 5);
  assert_non_null(list->next->prev);
  assert_int_equal(list->next->data, 10);
  assert_null(list->next->next);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(create_list_test),
    cmocka_unit_test(insert_end_test),
    cmocka_unit_test(insert_begin_test),
    cmocka_unit_test(insert_after_test),
    cmocka_unit_test(insert_before_test),
    cmocka_unit_test(delete_first_node_test),
    cmocka_unit_test(delete_end_node_test),
    cmocka_unit_test(delete_middle_node_test),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
