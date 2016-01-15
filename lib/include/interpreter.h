#ifndef NEWSPEAK_INTERPRETER_H
#define NEWSPEAK_INTERPRETER_H

#include "ast.h"

typedef struct interpreterState *Interpreter;
typedef struct interpreterState {

} InterpreterState;

Interpreter interpreter_create();

void interpreter_destroy();

int interpret(Interpreter interpreter, Block ast);

void interpret_application(Interpreter interpreter, Application application);

void interpret_var_definition(Interpreter interpreter, VarDefinition var_definition);

void interpret_expression(Interpreter interpreter, Expression expression);

void interpret_variable(Interpreter interpreter, Variable variable);

#endif
