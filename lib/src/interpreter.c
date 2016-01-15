#include <stdio.h>
#include <stdlib.h>

#include "ast.h"
#include "ast-print.h"
#include "interpreter.h"

Interpreter interpreter_create() {
    Interpreter interpreter = malloc(sizeof(InterpreterState));

    return interpreter;
}

void interpreter_destroy(Interpreter interpreter) {
    free(interpreter);
}

int interpret(Interpreter interpreter, Block ast) {
    printf("Interpreting\n");
    ast_print(ast);
    return 0;
}

