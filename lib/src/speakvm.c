#include <stdlib.h>

#include "stack.h"
#include "darray.h"
#include "dbg.h"

SpeakVM *speak_vm_create(DArray program) {

    SpeakVM *vm = malloc(sizeof(SpeakVM));
    check_mem(vm);
    Stack *call_stack = stack_create();
    check_mem(call_stack);

    vm->counter = 0;
    vm->call_stack = call_stack;
    vm->program = program;

    return vm;
error:
    if (call_stack) free(call_stack);
    if (vm) free(vm);

    return NULL;
}

void speak_vm_destroy(SpeakVM *vm) {
    if (vm) {
        darray_clear_destroy(vm->program);
        stack_clear_destroy(vm->call_stack);
        free(vm);
    }
}

