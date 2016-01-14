#include <stdio.h>

#include "ast.h"
#include "ast-print.h"

int interpret(Block ast) {
    printf("Interpreting\n");
    ast_print(ast);
    return 0;
}

