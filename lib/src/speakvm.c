#include <stdlib.h>

#include "speakvm.h"

#include "bclib/stack.h"
#include "bclib/darray.h"
#include "bclib/dbg.h"

SpeakVM *speak_vm_create(DArray *program) {

    // TODO memory checking here
    SpeakVM *vm = malloc(sizeof(SpeakVM));
    Stack *call_stack = stack_create();

    vm->counter = 0;
    vm->call_stack = call_stack;
    vm->program = program;

    return vm;
}

void speak_vm_destroy(SpeakVM *vm) {
    if (vm) {
        darray_clear_destroy(vm->program);
        stack_clear_destroy(vm->call_stack);
        free(vm);
    }
}

int speak_fm_run(SpeakVM *vm) {
    return 0;
}


