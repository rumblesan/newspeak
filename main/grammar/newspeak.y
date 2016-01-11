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
%define api.pure 
%lex-param {void *scanner}
%parse-param {void *scanner}

%token DEFINE
%token OPAREN
%token CPAREN
%token NUMBER
%token IDENTIFIER

%%
elements: %empty
        | elements element
        ;

element: application
       | definition
       ;

application: OPAREN IDENTIFIER argList CPAREN
           {
               printf("Got application %d\n", $2);
           }
           ;

argList: argList expression
       | expression
       ;


definition: OPAREN DEFINE IDENTIFIER OPAREN expression CPAREN CPAREN
           {
               printf("defined variable %d\n", $2);
           }
          ;

expression: variable
          | NUMBER
          ;

variable: IDENTIFIER
        ;
%%
