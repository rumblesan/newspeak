#ifndef __SPEAK_VM_H__
#define __SPEAK_VM_H__

#include "bclib/stack.h"
#include "bclib/darray.h"

typedef enum {
    NOP,   // NoOperation
    HLT,   // Halt
    ADD,   // Add top two elements of stack
    SUB,   // Subtract top two elements of stack
    MUL,   // Multiply top two elements of stack
    DIV,   // Divide top two elements of stack
    MOD,   // Modulus top two elements of stack
    POW,   // Exponent top two elements of stack
    UNM,   // Unary Minus
    EQL,   // Equality
    LT,    // Less than test
    LE,    // Less than or equal test
    EQ,    // Equality
    LOAD,  // Load from memory to stack
    CNST,  // Load a constant onto the stack
    STR,   // Store the value from the stack to an address
    JMP,   // Unconditional jump
    IF,    // Conditional jump
    CALL,  // Call a function
    RTRN   // Return
} VMInstruction;

typedef struct SpeakVM {

    Stack *call_stack;

    DArray *program;

    unsigned long counter;

} SpeakVM;

SpeakVM *speak_vm_create(DArray *program);
void speak_vm_destroy(SpeakVM *vm);

int speak_vm_run(SpeakVM *vm);

#endif
