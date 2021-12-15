#ifndef HEX_PARSER_H
#define HEX_PARSER_H

#include <stdlib.h>
#include <string.h>

#ifndef HEX_TOKEN_MAX_CHARS
#define HEX_TOKEN_MAX_CHARS 3
#endif

typedef struct token token_t;
typedef struct block block_t;
typedef struct parser parser_t;
typedef unsigned char hex_t;

typedef enum token_type {
	TOKEN_BLOCK,
	TOKEN_INST,
	TOKEN_NONE,
	TOKEN_NUMBER,
	TOKEN_POINTER,
	TOKEN_REGISTER,
	TOKEN_VARIABLE
} token_type_t;

typedef enum inst {
	INST_ADD,
	INST_SUB,
	INST_JMP
} inst_t;

struct block {
	char *name;
	token_t *contents;
};

typedef enum reg {
	REG_0,
	REG_1,
	REG_2,
	REG_3,
	REG_4,
	REG_5,
	REG_6,
	REG_7,
	REG_8,
	REG_9,
	REG_A,
	REG_B,
	REG_C,
	REG_D,
	REG_E,
	REG_F
} reg_t;

typedef enum var {
	VAR_IN,
	VAR_OUT
} var_t;

struct token {
	token_type_t type;

	union {
		block_t block;
		inst_t inst;
		reg_t reg;
		hex_t num;
		var_t var;
	} item;
};

struct parser {
	char *str;
	size_t start;
	size_t end;
};

parser_t Parser_New(char *s);
size_t Parser_SkipToSpace(parser_t *parser, size_t from);
size_t Parser_SkipSpace(parser_t *parser, size_t from);
char *Parser_Sub(parser_t *parser);
token_t Parser_NextToken(parser_t *parser);

// Define the tokens
typedef struct tkn_inst {
	const char *str;
	inst_t inst;
} tkn_inst_t;

typedef struct tkn_var {
	const char *str;
	var_t var;
} tkn_var_t;

typedef struct tkn_reg {
	char num;
	reg_t reg;
} tkn_reg_t;

const tkn_inst_t Parser_RegInst[] = {
	{.str = "add", .inst = INST_ADD},
	{.str = "sub", .inst = INST_SUB},
	{.str = "jmp", .inst = INST_JMP},
};
#define Parser_RegInstL sizeof Parser_RegInst / sizeof(tkn_inst_t)

const tkn_var_t Parser_RegVar[] = {
	{.str = "in", .var = VAR_IN},
	{.str = "out", .var = VAR_OUT},
};
#define Parser_RegVarL sizeof Parser_RegInst / sizeof(tkn_var_t)

const tkn_reg_t Parser_RegTokens[] = {
	{.num = '0', .reg = REG_0},
	{.num = '1', .reg = REG_1},
	{.num = '2', .reg = REG_2},
	{.num = '3', .reg = REG_3},
	{.num = '4', .reg = REG_4},
	{.num = '5', .reg = REG_5},
	{.num = '6', .reg = REG_6},
	{.num = '7', .reg = REG_7},
	{.num = '8', .reg = REG_8},
	{.num = '9', .reg = REG_9},
	{.num = 'A', .reg = REG_A},
	{.num = 'B', .reg = REG_B},
	{.num = 'C', .reg = REG_C},
	{.num = 'D', .reg = REG_D},
	{.num = 'E', .reg = REG_E},
	{.num = 'F', .reg = REG_F},
	{.num = 'a', .reg = REG_A},
	{.num = 'b', .reg = REG_B},
	{.num = 'c', .reg = REG_C},
	{.num = 'd', .reg = REG_D},
	{.num = 'e', .reg = REG_E},
	{.num = 'f', .reg = REG_F}
};
#define Parser_RegTokensL sizeof Parser_RegTokens / sizeof(tkn_reg_t)

#endif // HEX_PARSER_H header guard
