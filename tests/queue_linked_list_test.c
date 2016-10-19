#include<stdarg.h>
#include<stddef.h>
#include<setjmp.h>
#include<cmocka.h>
#include<stdlib.h>
#include "queue_linked_list.h"

static void create_queue_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_queue(5, list);
  assert_int_equal(list->data, 5);
  assert_null(list->next);
}

static void enqueue_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_queue(5, list);
  list = enqueue(10, list);
  assert_int_equal(list->data, 5);
  assert_int_equal(list->next->data, 10);
}

static void dequeue_test(void **state) {
  (void) state;

  struct node *list;
  list = (struct node *)malloc(sizeof(struct node));
  list = create_queue(5, list);
  list = enqueue(10, list);
  list = dequeue(list);
  assert_int_equal(list->data, 10);
  assert_null(list->next);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(create_queue_test),
    cmocka_unit_test(enqueue_test),
    cmocka_unit_test(dequeue_test),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
