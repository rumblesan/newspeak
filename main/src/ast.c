#include <stdlib.h>

#include "ast.h"
#include "list.h"

/* Block AST Node */
Block ast_block_create(List elements) {
    Block block = malloc(sizeof(BlockNode));
    block->elements = elements;

    return block;
}

void ast_block_cleanup(Block block) {
    // TODO Free up nodes
    free(block);
}

/* Element AST Node */
Element ast_element_create() {
    Element element = malloc(sizeof(ElementNode));

    return element;
}

void ast_element_cleanup(Element element) {
    // TODO Free up node
    free(element);
}

Element ast_application_element(Application application) {
    Element element = ast_element_create();
    element->elementType = APPLICATIONEL;
    element->application = application;
    return element;
}

Element ast_vardefinition_element(VarDefinition varDefinition) {
    Element element = ast_element_create();
    element->elementType = VARDEFINITIONEL;
    element->varDefinition = varDefinition;
    return element;
}

/* Application AST Node */
Application ast_application_create(char *name, ArgList args) {
    Application application = malloc(sizeof(ApplicationNode));
    application->name = name;
    application->args = args;

    return application;
}

void ast_application_cleanup(Application application) {
    // TODO Free up name and args
    free(application);
}

/* ArgList AST Node */
ArgList ast_arg_list_create(List args) {
    ArgList argList = malloc(sizeof(ArgListNode));
    argList->args = args;

    return argList;
}

void ast_arg_list_cleanup(List argList) {
    // TODO Free up args
    free(argList);
}

/* Variable Definition AST Node */
VarDefinition ast_vardef_create(char *name, Expression expression) {
    VarDefinition varDef = malloc(sizeof(VarDefinitionNode));
    varDef->name = name;
    varDef->expression = expression;

    return varDef;
}

void ast_vardef_cleanup(VarDefinition vardef) {
    // TODO Free up name and expr
    free(vardef);
}

/* Expression AST Node */
Expression ast_expression_create() {
    Expression expression = malloc(sizeof(ExpressionNode));
    return expression;
}

void ast_expression_cleanup(Expression expression) {
    // TODO Free up expr
    free(expression);
}

Expression ast_application_expression(Application application) {
    Expression expression = ast_expression_create();
    expression->expressionType = APPLICATIONEXPR;
    expression->application = application;
    return expression;
}

Expression ast_number_expression(Number number) {
    Expression expression = ast_expression_create();
    expression->expressionType = NUMBEREXPR;
    expression->number = number;
    return expression;
}

Expression ast_variable_expression(Variable variable) {
    Expression expression = ast_expression_create();
    expression->expressionType = VARIABLEEXPR;
    expression->variable = variable;
    return expression;
}

/* Number Literal AST Node */
Number ast_number_create(double value) {
    Number number = malloc(sizeof(NumberNode));
    number->value = value;

    return number;
}

void ast_number_cleanup(Number number) {
    free(number);
}

/* Variable AST Node */
Variable ast_variable_create(char *name) {
    Variable variable = malloc(sizeof(VariableNode));
    variable->name = name;

    return variable;
}

void ast_variable_cleanup(Number number) {
    // TODO Free up name as well?
    free(number);
}

