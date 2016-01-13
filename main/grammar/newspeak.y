%code requires {
#include "ast.h"
#include "ast-print.h"
#include "list.h"
}

%{

#include <stdio.h>
#include <string.h>

#include "y.tab.h"
#include "lex.yy.h"

void yyerror(yyscan_t scanner, const char *str) {
    fprintf(stderr, "error: %s\n", str);
}

int main() {

    yyscan_t scanner;

    yylex_init(&scanner);
    yyset_in(stdin, scanner);

    yyparse(scanner);

    yylex_destroy(scanner);

    return 0;
}


%}

%define parse.error verbose
%define api.pure full
%lex-param {void *scanner}
%parse-param {void *scanner}

%union {
    Block         blockNode;
    List          elementsNode;
    Element       elementNode;
    Application   applicationNode;
    ArgList       argListNode;
    VarDefinition varDefNode;
    Expression    expressionNode;
    Number        numberNode;
    Variable      variableNode;
    Identifier    idNode;
    double        number;
}

%token DEFINE
%token OPAREN
%token CPAREN
%token<number> NUMBER
%token<numberNode> num
%token<idNode> IDENTIFIER
%type<blockNode> body
%type<elementsNode> elements
%type<elementNode> element
%type<applicationNode> application
%type<argListNode> argList
%type<varDefNode> vardefinition
%type<expressionNode> expression
%type<variableNode> variable

%%
body: elements
    {
        Block block = ast_block_create($1);
        ast_print(block);
        $$ = block;
    }
    ;

elements: %empty
        {
            $$ = list_empty();
        }
        | element elements
        {
            $$ = list_prepend($2, $1);
        }
        ;

element: application
       {
           $$ = ast_application_element($1);
       }
       | vardefinition
       {
           $$ = ast_vardefinition_element($1);
       }
       ;

application: OPAREN IDENTIFIER argList CPAREN
           {
               $$ = ast_application_create($2, $3);
           }
           ;

argList: argList expression
       {
           $$ = ast_arg_list_create(list_empty());
       }
       | expression
       {
           $$ = ast_arg_list_create(list_empty());
       }
       ;


vardefinition: OPAREN DEFINE IDENTIFIER OPAREN expression CPAREN CPAREN
          {
               $$ = ast_vardef_create($3, $5);
          }
          ;

expression: variable
          {
              $$ = ast_variable_expression($1);
          }
          | NUMBER
          {
              $$ = ast_number_expression(
                  ast_number_create($1)
              );
          }
          | application
          {
              $$ = ast_application_expression($1);
          }
          ;

variable: IDENTIFIER
        {
            $$ = ast_variable_create($1);
        }
        ;
%%
