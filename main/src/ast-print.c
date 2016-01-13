#include <stdio.h>
#include <stdlib.h>

#include "ast-print.h"
#include "ast.h"
#include "list.h"

#define DEPTH 2

void indent(int i) {
    printf("%*s", i, " ");
}

void ast_print(Block block) {
    ast_block_print(block, 0);
}

void ast_block_print(Block block, int indentation) {
    indent(indentation);
    printf("AST Block with %d elements\n", list_length(block->elements));
    List e = block->elements;

    while (!list_is_empty(e)) {
        ast_element_print((Element)list_head(e), indentation + DEPTH);
        e = list_tail(e);
    }
}

void ast_element_print(Element element, int indentation) {
    switch(element->elementType) {
        case VARDEFINITIONEL:
            ast_vardef_print(element->varDefinition, indentation + DEPTH);
            break;
        case APPLICATIONEL:
            ast_application_print(element->application, indentation + DEPTH);
            break;
    }
}

void ast_vardef_print(VarDefinition vardef, int indentation) {
    indent(indentation);
    printf("Var Definition: %s\n", vardef->name);
    ast_expression_print(vardef->expression, indentation + DEPTH);
}

void ast_application_print(Application application, int indentation) {
    indent(indentation);
    printf("Application: %s\n", application->name);
}

void ast_arg_list_print(ArgList argList, int indentation) {
    List args = argList->args;
    while (!list_is_empty(args)) {
        ast_expression_print((Expression)list_head(args), indentation + DEPTH);
        args = list_tail(args);
    }
    indent(indentation);
}

void ast_expression_print(Expression expression, int indentation) {
    indent(indentation);
    printf("Expression\n");
    switch(expression->expressionType) {
        case APPLICATIONEXPR:
            ast_application_print(expression->application, indentation + DEPTH);
            break;
        case NUMBEREXPR:
            ast_number_print(expression->number, indentation + DEPTH);
            break;
        case VARIABLEEXPR:
            ast_variable_print(expression->variable, indentation + DEPTH);
            break;
    }
}

void ast_number_print(Number number, int indentation) {
    indent(indentation);
    printf("Number: %f\n", number->value);

}

void ast_variable_print(Variable variable, int indentation) {
    indent(indentation);
    printf("Variable: %s\n", variable->name);
}


