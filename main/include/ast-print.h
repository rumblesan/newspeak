#ifndef AST_DISPLAY_H
#define AST_DISPLAY_H

#include "ast.h"

void ast_print(Block block);

void ast_block_print(Block block, int indentation);

void ast_element_print(Element element, int indentation);

void ast_vardef_print(VarDefinition vardef, int indentation);

#endif
