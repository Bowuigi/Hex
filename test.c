#include "parser.h"

int main() {
	char *s = "add r0 0x20 jmp p1 block";
	parser_t parser = Parser_New(s);
	token_t token = Parser_NextToken(&parser);
	while (1)
		token = Parser_NextToken(&parser);
}
