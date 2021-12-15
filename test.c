#include "parser.h"

int main() {
	char *s = "Hello world!";
	parser_t parser = Parser_New(s);
	Parser_NextToken(&parser);
	Parser_NextToken(&parser);
}
