#include <stdlib.h>

#include "ast.h"
#include "list.h"

/* General AST Node */
AST ast_create() {
    AST ast = malloc(sizeof(ASTNode));
    return ast;
}

void ast_cleanup(AST ast) {
    // FIXME Implement
}

/* Application AST Node */
AST ast_application_create(char *name, List args) {
    Application application = malloc(sizeof(ApplicationNode));
    application->name = name;
    application->args = args;

    AST ast = ast_create();
    ast->nodeType = APPLICATION;
    ast->application = application;

    return ast;
}

void ast_application_cleanup(Application application) {
    // TODO Free up name and args as well?
    free(application);
}

/* Variable Definition AST Node */
AST ast_vardef_create(char *name, AST expression) {
    VarDefinition varDef = malloc(sizeof(VarDefinitionNode));
    varDef->name = name;
    varDef->expression = expression;

    AST ast = ast_create();
    ast->nodeType = VARDEF;
    ast->varDefinition = varDef;

    return ast;
}

void ast_vardef_cleanup(VarDefinition vardef) {
    // TODO Free up name and expr as well?
    free(vardef);
}

/* Number Literal AST Node */
AST ast_number_create(double value) {
    Number number = malloc(sizeof(NumberNode));
    number->value = value;

    AST ast = ast_create();
    ast->nodeType = NUMBER;
    ast->number = number;

    return ast;
}

void ast_number_cleanup(Number number) {
    free(number);
}

/* Variable AST Node */
AST ast_variable_create(char *name) {
    Variable variable = malloc(sizeof(VariableNode));
    variable->name = name;

    AST ast = ast_create();
    ast->nodeType = VARIABLE;
    ast->variable = variable;

    return ast;
}

void ast_variable_cleanup(Number number) {
    // TODO Free up name as well?
    free(number);
}

