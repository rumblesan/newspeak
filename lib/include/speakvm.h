#ifndef __SPEAK_VM_H__
#define __SPEAK_VM_H__

#include "bclib/stack.h"
#include "bclib/darray.h"

typedef enum {
    INOP,   // NoOperation
    IHLT,   // Halt
    IADD,   // Add top two elements of stack
    ISUB,   // Subtract top two elements of stack
    IMUL,   // Multiply top two elements of stack
    IDIV,   // Divide top two elements of stack
    IMOD,   // Modulus top two elements of stack
    IPOW,   // Exponent top two elements of stack
    IUNM,   // Unary Minus
    IEQL,   // Equality
    ILT,    // Less than test
    ILE,    // Less than or equal test
    IEQ,    // Equality
    ILOAD,  // Load from memory to stack
    ICNST,  // Load a constant onto the stack
    ISTOR,  // Store the value from the stack to an address
    IJMP,   // Unconditional jump
    IIF,    // Conditional jump
    ICALL,  // Call a function
    IRTRN   // Return
} VMInstruction;

typedef uint32_t Instruction;

typedef struct SpeakVM {

    Stack *call_stack;

    void **program;

    unsigned long counter;

} SpeakVM;

SpeakVM *speak_vm_create(void *program[]);
void speak_vm_destroy(SpeakVM *vm);

int speak_vm_run(SpeakVM *vm);

#endif
