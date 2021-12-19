#ifndef HEX_TOKENS_H
#define HEX_TOKENS_H

#include "parser.h"

// Define the tokens
typedef struct {
	const char *str;
	inst_t inst;
} tkn_inst_t;

typedef struct {
	const char *str;
	var_t var;
} tkn_var_t;

typedef struct {
	char num;
	reg_t reg;
} tkn_reg_t;

typedef struct {
	char num;
	ptr_t ptr;
} tkn_ptr_t;

#define Parser_RegInstL sizeof Parser_RegInst / sizeof(tkn_inst_t)
#define Parser_RegVarL sizeof Parser_RegInst / sizeof(tkn_var_t)
#define Parser_RegTokensL sizeof Parser_RegTokens / sizeof(tkn_reg_t)
#define Parser_PtrTokensL sizeof Parser_PtrTokens / sizeof(tkn_ptr_t)

#endif // HEX_TOKENS_H header guard
