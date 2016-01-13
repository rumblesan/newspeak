#ifndef AST_H
#define AST_H

#include "list.h"

/* Pointers */
typedef struct blockNode         *Block;
typedef struct elementNode       *Element;
typedef struct applicationNode   *Application;
typedef struct argListNode       *ArgList;
typedef struct varDefinitionNode *VarDefinition;
typedef struct expressionNode    *Expression;
typedef struct numberNode        *Number;
typedef struct variableNode      *Variable;
typedef char                     *Identifier;

/* Block AST Node */
typedef struct blockNode {

    List elements;

} BlockNode;

Block ast_block_create(List nodes);

void ast_block_cleanup(Block block);

/* Element AST Node */
typedef enum {VARDEFINITIONEL, APPLICATIONEL} ElementNodeType;

typedef struct elementNode {

    ElementNodeType elementType;

    union {
        Application application;
        VarDefinition varDefinition;
    };

} ElementNode;

Element ast_element_create();

void ast_element_cleanup(Element element);

Element ast_application_element(Application application);

Element ast_vardefinition_element(VarDefinition vardefinition);


/* Application AST Node */
typedef struct applicationNode {

    char *name;

    ArgList args;

} ApplicationNode;

Application ast_application_create(char *name, ArgList args);

void ast_application_cleanup(Application application);

/* ArgList AST Node */
typedef struct argListNode {

    List args;

} ArgListNode;

ArgList ast_arg_list_create(List args);

void ast_arg_list_cleanup(List args);

/* Variable Definition AST Node */
typedef struct varDefinitionNode {

    char *name;

    Expression expression;

} VarDefinitionNode;

VarDefinition ast_vardef_create(char *name, Expression expression);

void ast_vardef_cleanup(VarDefinition vardef);


/* Expression AST Node */
typedef enum {APPLICATIONEXPR, NUMBEREXPR, VARIABLEEXPR} ExpressionNodeType;

typedef struct expressionNode {

    ExpressionNodeType expressionType;

    union {
        Application application;
        Number number;
        Variable variable;
    };

} ExpressionNode;

Expression ast_expression_create();

void ast_expression_cleanup(Expression expression);

Expression ast_application_expression(Application application);

Expression ast_number_expression(Number number);

Expression ast_variable_expression(Variable variable);

/* Number Literal AST Node */
typedef struct numberNode {

    double value;

} NumberNode;

Number ast_number_create(double value);

void ast_number_cleanup(Number number);

/* Variable AST Node */
typedef struct variableNode {

    char *name;

} VariableNode;

Variable ast_variable_create(char *name);

void ast_number_cleanup(Number number);

#endif
