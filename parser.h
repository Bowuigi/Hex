#ifndef HEX_PARSER_H
#define HEX_PARSER_H

#include <stdlib.h>
#include <string.h>

#define PARSE_ERR(msg) do { fprintf(stderr, "Hex, parsing error near '%s': %s", tkn, msg); exit(1); } while (0)

typedef struct token token_t;
typedef struct block block_t;
typedef struct parser parser_t;
typedef long hex_t;

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
	INST_JMP,
	INST_LINK
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

typedef enum ptr {
	PTR_0,
	PTR_1,
	PTR_2,
	PTR_3,
	PTR_4,
	PTR_5,
	PTR_6,
	PTR_7,
	PTR_8,
	PTR_9,
	PTR_A,
	PTR_B,
	PTR_C,
	PTR_D,
	PTR_E,
	PTR_F
} ptr_t;

typedef enum var {
	VAR_IN,
	VAR_OUT
} var_t;

struct token {
	token_type_t type;

	union {
		block_t block;
		inst_t inst;
		var_t var;
		reg_t reg;
		ptr_t ptr;
		hex_t num;
	} item;
};

struct parser {
	char *str;
	size_t start;
	size_t end;
	block_t *latest_block;
};

parser_t Parser_New(char *s);
size_t Parser_SkipToSpace(parser_t *parser, size_t from);
size_t Parser_SkipSpace(parser_t *parser, size_t from);
char *Parser_Sub(parser_t *parser);
token_t Parser_NextToken(parser_t *parser);

#endif // HEX_PARSER_H header guard
