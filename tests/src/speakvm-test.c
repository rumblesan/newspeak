#include "minunit.h"

#include "speakvm.h"
#include "bclib/darray.h"

static SpeakVM *vm;

char *test_create() {
    void *program[100];

    vm = speak_vm_create(program);
    mu_assert(vm != NULL, "speak_vm_create failed");
    mu_assert(vm->counter == 0, "vm count is incorrect");

    return NULL;
}

char *test_destroy() {
    speak_vm_destroy(vm);
    return NULL;
}

char *all_tests() {
    mu_suite_start();

    mu_run_test(test_create);
    mu_run_test(test_destroy);

    return NULL;
}

RUN_TESTS(all_tests);
