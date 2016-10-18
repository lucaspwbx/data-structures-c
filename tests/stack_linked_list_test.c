#include<stdarg.h>
#include<stddef.h>
#include<setjmp.h>
#include<cmocka.h>
#include<stdlib.h>
#include "stack_linked_list.h"

static void create_stack_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_stack(5, list);
  assert_int_equal(list->data, 5);
  assert_null(list->next);
}

static void push_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_stack(5, list);
  list = push(10, list);
  assert_int_equal(list->data, 10);
  assert_int_equal(list->next->data, 5);
}

static void pop_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_stack(5, list);
  list = push(10, list);
  list = pop(list);
  assert_int_equal(list->data, 5);
  assert_null(list->next);
}

static void peek_test(void **state) {
  (void) state;

  struct node *list;
  int peeked;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_stack(5, list);
  list = push(10, list);
  peeked = peek(list);
  assert_int_equal(peeked, 10);
  assert_int_equal(list->data, 10);
  assert_int_equal(list->next->data, 5);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(create_stack_test),
    cmocka_unit_test(push_test),
    cmocka_unit_test(peek_test),
    cmocka_unit_test(pop_test),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
