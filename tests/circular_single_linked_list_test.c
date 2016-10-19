#include<stdarg.h>
#include<stddef.h>
#include<setjmp.h>
#include<cmocka.h>
#include<stdlib.h>
#include "circular_single_linked_list.h"

static void create_list_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_list(5, list);
  assert_int_equal(list->data, 5);
  assert_int_equal(list->next->data, 5);
}

static void insert_end_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_list(5, list);
  list = insert_end(10, list);
  assert_int_equal(list->data, 5);
  assert_int_equal(list->next->data, 10);
  assert_int_equal(list->next->next->data, 5);
}

static void insert_begin_test(void **state) {
  (void) state;
}

static void insert_after_test(void **state) {
  (void) state;
}

static void insert_before_test(void **state) {
  (void) state;

}

static void delete_node_test(void **state) {
  (void) state;

}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(create_list_test),
    cmocka_unit_test(insert_end_test),
   // cmocka_unit_test(insert_begin_test),
   // cmocka_unit_test(insert_after_test),
   // cmocka_unit_test(insert_before_test),
   // cmocka_unit_test(delete_node_test),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
