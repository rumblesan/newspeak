#ifndef AST_H
#define AST_H

#include "list.h"

typedef enum {APPLICATION, VARDEF, NUMBER, VARIABLE} ASTNodeTypes;

/* Pointers */
typedef struct astNode           *AST;
typedef struct applicationNode   *Application;
typedef struct varDefinitionNode *VarDefinition;
typedef struct numberNode        *Number;
typedef struct variableNode      *Variable;

/* General AST Node */
typedef struct astNode {

    ASTNodeTypes nodeType;

    union {
        Application application;
        VarDefinition varDefinition;
        Number number;
        Variable variable;
    };

} ASTNode;

AST ast_create();

void ast_cleanup(AST ast);

/* Application AST Node */
typedef struct applicationNode {

    char *name;

    List args;

} ApplicationNode;

AST ast_application_create(char *name, List args);

void ast_application_cleanup(Application application);

/* Variable Definition AST Node */
typedef struct varDefinitionNode {

    char *name;

    AST expression;

} VarDefinitionNode;

AST ast_vardef_create(char *name, AST expression);

void ast_vardef_cleanup(VarDefinition vardef);

/* Number Literal AST Node */
typedef struct numberNode {

    double value;

} NumberNode;

AST ast_number_create(double value);

void ast_number_cleanup(Number number);

/* Variable AST Node */
typedef struct variableNode {

    char *name;

} VariableNode;

AST ast_variable_create(char *name);

void ast_number_cleanup(Number number);

#endif
