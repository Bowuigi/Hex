#include "tokens.h"

const tkn_inst_t Parser_RegInst[] = {
	{.str = "add", .inst = INST_ADD},
	{.str = "sub", .inst = INST_SUB},
	{.str = "jmp", .inst = INST_JMP},
	{.str = "link", .inst = INST_LINK}
};

const tkn_var_t Parser_RegVar[] = {
	{.str = "in", .var = VAR_IN},
	{.str = "out", .var = VAR_OUT},
};

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

const tkn_ptr_t Parser_PtrTokens[] = {
	{.num = '0', .ptr = PTR_0},
	{.num = '1', .ptr = PTR_1},
	{.num = '2', .ptr = PTR_2},
	{.num = '3', .ptr = PTR_3},
	{.num = '4', .ptr = PTR_4},
	{.num = '5', .ptr = PTR_5},
	{.num = '6', .ptr = PTR_6},
	{.num = '7', .ptr = PTR_7},
	{.num = '8', .ptr = PTR_8},
	{.num = '9', .ptr = PTR_9},
	{.num = 'A', .ptr = PTR_A},
	{.num = 'B', .ptr = PTR_B},
	{.num = 'C', .ptr = PTR_C},
	{.num = 'D', .ptr = PTR_D},
	{.num = 'E', .ptr = PTR_E},
	{.num = 'F', .ptr = PTR_F},
	{.num = 'a', .ptr = PTR_A},
	{.num = 'b', .ptr = PTR_B},
	{.num = 'c', .ptr = PTR_C},
	{.num = 'd', .ptr = PTR_D},
	{.num = 'e', .ptr = PTR_E},
	{.num = 'f', .ptr = PTR_F}
};
