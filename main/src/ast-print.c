#include <stdlib.h>

#include "ast-print.h"
#include "ast.h"
#include "list.h"

void indent(int i) {
    printf("%*s", i);
}

void ast_print(Block block) {
    ast_block_print(block);
}

void ast_block_print(Block block, int indentation) {
    indent(indentation);
    printf("AST Block with %d elements\n", list_length(block->elements));
    List e = block->elements;

    while (!list_is_empty(e)) {
        ast_element_print((Element)list_head(e), indentation + 2);
        e = list_tail(e);
    }
}

void ast_element_print(Element element, int indentation) {
    switch(element->elementType) {
        case VARDEFINITIONEL: ast_vardef_print(element->varDefinition, indentation + 2); break;
        case APPLICATIONEL: ast_application_print(element->application, indentation + 2); break;
    }
}

void ast_vardef_print(VarDefinition vardef, int indentation) {
    indent(indentation);
    printf("Var Definition\n");
}

void ast_application_print(Application application, int indentation) {
    indent(indentation);
    printf("Application\n");
}

