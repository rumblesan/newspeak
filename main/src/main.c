#include <stdio.h>

#include "parser.h"
#include "ast.h"
#include "ast-print.h"
#include "interpreter.h"

int main(int argc, char *argv[]) {

    Block ast;

    int parseResult = parse(&ast);

    if (parseResult) {
        printf("Error during parsing");
    } else {
        interpret(ast);
    }

    return parseResult;
}

