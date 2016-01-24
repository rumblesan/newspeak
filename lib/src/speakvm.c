#include <stdlib.h>

#include "speakvm.h"

#include "bclib/stack.h"
#include "bclib/dbg.h"

SpeakVM *speak_vm_create(void *program[]) {

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
        stack_clear_destroy(vm->call_stack);
        free(vm);
    }
}

int speak_fm_run(SpeakVM *vm) {

    int running = 1;
    while(running == 1) {

        Instruction inst = (Instruction)vm->program[vm->counter];

        switch(inst) {

            case INOP:
                printf("NOP");
                break;
            case IHLT:
                printf("HLT");
                running = 0;
                break;
            case IADD:
                printf("ADD");
                break;
            case ISUB:
                printf("SUB");
                break;
            case IMUL:
                printf("MUL");
                break;
            case IDIV:
                printf("DIV");
                break;
            case IMOD:
                printf("MOD");
                break;
            case IPOW:
                printf("POW");
                break;
            case IUNM:
                printf("UNM");
                break;
            case IEQL:
                printf("EQL");
                break;
            case ILT:
                printf("LT");
                break;
            case ILE:
                printf("LE");
                break;
            case IEQ:
                printf("EQ");
                break;
            case ILOAD:
                printf("LOAD");
                break;
            case ICNST:
                printf("CNST");
                break;
            case ISTOR:
                printf("STOR");
                break;
            case IJMP:
                printf("JMP");
                break;
            case IIF:
                printf("IF");
                break;
            case ICALL:
                printf("CALL");
                break;
            case IRTRN:
                printf("RTRN");
                break;
        }

        vm->counter += 1;

    }

    return 0;
}


