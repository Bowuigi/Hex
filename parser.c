#include "parser.h"
#include <stdio.h>

parser_t Parser_New(char *s) {
	parser_t parser = {
		.str = s,
		.start = -1,
		.end = -1
	};
	return parser;
}

size_t Parser_SkipSpace(parser_t *parser, size_t from) {
	size_t pos = from;

	for (; parser->str[pos] == ' ' || parser->str[pos] == '\t' || parser->str[pos] == '\n'; pos++);

	return pos;
}

size_t Parser_SkipToSpace(parser_t *parser, size_t from) {
	size_t pos = from;

	for (; parser->str[pos] != ' ' && parser->str[pos] != '\t' && parser->str[pos] != '\n' && parser->str[pos] != '\0'; pos++);

	return pos;
}

char *Parser_Sub(parser_t *parser) {
	size_t len = parser->end - parser->start + 1;
	char *sub = calloc(len, sizeof(char));

	for (size_t i = 0; i < len; i++) {
		sub[i] = parser->str[parser->start+i];
	}

	sub[len] = '\0';

	return sub;
}

token_t Parser_NextToken(parser_t *parser) {
	token_t token;
	token.type = TOKEN_NONE;

	parser->start = Parser_SkipSpace(parser, parser->end + 1);
	parser->end = Parser_SkipToSpace(parser, parser->start) - 1;

	char *tkn = Parser_Sub(parser);
	printf("{token = '%s', start = '%zu', end = '%zu'};\n", tkn, parser->start, parser->end);

	for (size_t i = 0; i < Parser_RegInstL; i++) {
		if (strcmp(Parser_RegInst[i].str, tkn) == 0) {
			token.type = TOKEN_INST;
			token.item.inst = Parser_RegInst[i].inst;
		}
	}

	if (token.type == TOKEN_NONE) {
		for (size_t i = 0; i < Parser_RegVarL; i++) {
			if (strcmp(Parser_RegVar[i].str, tkn) == 0) {
				token.type = TOKEN_VARIABLE;
				token.item.var = Parser_RegVar[i].var;
			}
		}
	}

	if (tkn[0] == 'r' && token.type == TOKEN_NONE) {
		for (size_t i = 0; i < Parser_RegTokensL; i++) {
			if (tkn[1] == Parser_RegTokens[i].num) {
				token.type = TOKEN_REGISTER;
				token.item.reg = Parser_RegTokens[i].reg;
				break;
			}
		}
	}

	if (tkn[0] == '[' && token.type == TOKEN_NONE) {
		
	}

	return token;
}
