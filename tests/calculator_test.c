#include<stdarg.h>
#include<stddef.h>
#include<setjmp.h>
#include<cmocka.h>
#include "calculator.h"

static void add_test(void **state) {
  (void) state;

  int x = add(5, 10);
  assert_int_equal(x, 15);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(add_test),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
