/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:09:59 by tlaranje          #+#    #+#             */
/*   Updated: 2025/10/29 17:05:08 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
void test_basic(void)
{
	char c = 'A';
	char *s = "42porto";
	char *null_s = NULL;
	void *ptr = s;
	void *null_ptr = NULL;
	int ft_ret, std_ret;

	printf("======= Char: %c | String: %s | Pointer: %p\n\n", c, s, ptr);

	printf(" ft_printf(\"Char: %%c | String: %%s | Pointer: %%p\", c, s, ptr)\n");
	ft_ret = ft_printf("	Char: %c | String: %s | Pointer: %p\n", c, s, ptr);
	printf("	ft_printf returned: %d\n\n", ft_ret);

	printf(" printf(\"Char: %%c | String: %%s | Pointer: %%p\", c, s, ptr)\n");
	std_ret = printf("	Char: %c | String: %s | Pointer: %p\n", c, s, ptr);
	printf("	printf returned: %d\n\n", std_ret);

	printf("======= Null string: %s | Null pointer: %p\n\n", null_s, null_ptr);

	printf(" ft_printf(\"String: %%s | Pointer: %%p\", null_s, null_ptr)\n");
	ft_ret = ft_printf("	Null string: %s | Null pointer: %p\n", null_s, null_ptr);
	printf("	ft_printf returned: %d\n\n", ft_ret);

	printf(" printf(\"String: %%s | Pointer: %%p\", null_s, null_ptr)\n");
	std_ret = printf("	Null string: %s | Null pointer: %p\n", null_s, null_ptr);
	printf("	printf returned: %d\n", std_ret);

}

void test_signed(void)
{
	int i_nums[] = {0, 42, -42, INT_MAX, INT_MIN};
	int ft_ret, std_ret;

	for (int i = 0; i < 5; i++)
	{
		printf("=========================== Test %d ===========================\n\n", i + 1);
		printf("======= Decimal: %d | Base 10: %i\n", i_nums[i], i_nums[i]);
		printf(" ft_printf(\"Decimal: %%d | Base 10: %%i\\n\", i_nums[i], i_nums[i])\n");
		ft_ret = ft_printf("	Decimal: %d | Base 10: %i\n", i_nums[i], i_nums[i]);
		printf("	ft_printf returned: %d\n\n", ft_ret);

		printf("======= Decimal: %d | Base 10: %i\n", i_nums[i], i_nums[i]);
		printf(" printf(\"Decimal: %%d | Base 10: %%i\\n\", i_nums[i], i_nums[i])\n");
		std_ret = printf("	Decimal: %d | Base 10: %i\n", i_nums[i], i_nums[i]);
		printf("	printf returned: %d\n", std_ret);

		if (i < 4)
			printf("\n");
	}
}

void test_unsigned(void)
{
	unsigned int u_nums[] = {0, 42, UINT_MAX};
	int ft_ret, std_ret;

	for (int i = 0; i < 3; i++)
	{
		printf("=========================== Test %d ===========================\n\n", i + 1);
		printf("======= Unsigned: %u\n", u_nums[i]);
		printf(" ft_printf(\"Unsigned: %%u\\n\", u_nums[i])\n");
		ft_ret = ft_printf("	Unsigned: %u\n", u_nums[i]);
		printf("	ft_printf returned: %d\n\n", ft_ret);

		printf("======= Unsigned: %u\n", u_nums[i]);
		printf(" printf(\"Unsigned: %%u\\n\", u_nums[i])\n");
		std_ret = printf("	Unsigned: %u\n", u_nums[i]);
		printf("	printf returned: %d\n", std_ret);

		if (i < 4)
			printf("\n");
	}
}

void test_hex(void)
{
	unsigned int hex_nums[] = {0, 42, 255, UINT_MAX};
	int ft_ret, std_ret;

	for (int i = 0; i < 4; i++)
	{
		printf("=========================== Test %d ===========================\n\n", i + 1);
		printf("======= hex: %x | HEX: %X\n", hex_nums[i], hex_nums[i]);
		printf(" ft_printf(\"hex: %%x | HEX: %%X\\n\", hex_nums[i], hex_nums[i])\n");
		ft_ret = ft_printf("	hex: %x | HEX: %X\n", hex_nums[i], hex_nums[i]);
		printf("	ft_printf returned: %d\n\n", ft_ret);

		printf("======= hex: %x | HEX: %X\n", hex_nums[i], hex_nums[i]);
		printf(" printf(\"hex: %%x | HEX: %%X\\n\", hex_nums[i], hex_nums[i])\n");
		ft_ret = printf("	hex: %x | HEX: %X\n", hex_nums[i], hex_nums[i]);
		printf("	printf returned: %d\n\n", ft_ret);

		if (i < 4)
			printf("\n");
	}
}

void test_mixed(void)
{
	char c = 'Z';
	char *s = "42school";
	void *ptr = s;
	int ft_ret, std_ret;

	printf(" ft_printf\n");
	ft_ret = ft_printf("	%c %s %p %d %i %u %x %X %%\n", c, s, ptr, 123, -123, 456U, 255U, 255U);
	printf("	ft_printf returned: %d\n", ft_ret);

	printf(" printf\n");
	std_ret = printf("	%c %s %p %d %i %u %x %X %%\n", c, s, ptr, 123, -123, 456U, 255U, 255U);
	printf("	printf returned: %d\n", std_ret);
}

void test_edge(void)
{
	int ft_ret, std_ret;

	printf(" ft_printf\n");
	ft_ret = ft_printf("	Zero: %d %u %x %X | INT_MIN: %d\n"
		"	INT_MAX: %d | UINT_MAX: %u\n",
						0, 0U, 0U, 0U, INT_MIN, INT_MAX, UINT_MAX);
	printf("	ft_printf returned: %d\n", ft_ret);

	printf(" printf\n");
	std_ret = printf("	Zero: %d %u %x %X | INT_MIN: %d\n"
		"	INT_MAX: %d | UINT_MAX: %u\n",
						0, 0U, 0U, 0U, INT_MIN, INT_MAX, UINT_MAX);
	printf("	printf returned: %d\n", std_ret);
}

void test_bonus(void)
{
	char *s = "42school";
	int ft_ret, std_ret;
	const char *descriptions[] = {
		"Right align width: '%5d'",
		"Left align width: '%-5d'",
		"Zero padding: '%05d'",
		"Sign '+' and space: '%+d', '% d'",
		"Negative number with width and zero: '%08d'",
		"Precision with integer: '%.5d'",
		"Precision with string: '%.5s'",
		"Hex with prefix and zero: '%#08x'",
		"Multiple flags combined: '%-+10.5d'"
	};

	for (int i = 0; i < 9; i++)
	{
		printf("=========================== Test %d ===========================\n\n", i + 1);
		printf(" ft_printf(\"%s\")\n", descriptions[i]);
		switch (i)
		{
			case 0: ft_ret = ft_printf("	Right align width: '%5d'\n", 42);
				break;
			case 1: ft_ret = ft_printf("	Left align width: '%-5d'\n", 42);
				break;
			case 2: ft_ret = ft_printf("	Zero padding: '%05d'\n", 42);
				break;
			case 3: ft_ret = ft_printf("	Sign '+' and space: '%+d', '% d'\n", 42, 42);
				break;
			case 4: ft_ret = ft_printf("	Negative number with width and zero: '%08d'\n", -42);
				break;
			case 5: ft_ret = ft_printf("	Precision with integer: '%.5d'\n", 42);
				break;
			case 6: ft_ret = ft_printf("	Precision with string: '%.5s'\n", s);
				break;
			case 7: ft_ret = ft_printf("	Hex with prefix and zero: '%#08x'\n", 255U);
				break;
			case 8: ft_ret = ft_printf("	Multiple flags combined: '%-+10.5d'\n", 42);
				break;
		}
		printf("	ft_printf returned: %d\n\n", ft_ret);
		printf(" printf(\"%s\")\n", descriptions[i]);
		switch (i)
		{
			case 0: std_ret = printf("	Right align width: '%5d'\n", 42);
				break;
			case 1: std_ret = printf("	Left align width: '%-5d'\n", 42);
				break;
			case 2: std_ret = printf("	Zero padding: '%05d'\n", 42);
				break;
			case 3: std_ret = printf("	Sign '+' and space: '%+d', '% d'\n", 42, 42);
				break;
			case 4: std_ret = printf("	Negative number with width and zero: '%08d'\n", -42);
				break;
			case 5: std_ret = printf("	Precision with integer: '%.5d'\n", 42);
				break;
			case 6: std_ret = printf("	Precision with string: '%.5s'\n", s);
				break;
			case 7: std_ret = printf("	Hex with prefix and zero: '%#08x'\n", 255U);
				break;
			case 8: std_ret = printf("	Multiple flags combined: '%-+10.5d'\n", 42);
				break;
		}
		printf("	printf returned: %d\n", std_ret);
		if (i < 8)
			printf("\n");
	}
}

void print_menu(void)
{
	printf("\n===================== ft_printf Test Menu ====================\n");
	printf(  "======================== Mandatory Part ======================\n\n");
	printf("  1. Basic Tests (c, s, p)\n");
	printf("  2. Signed Integers (d, i)\n");
	printf("  3. Unsigned Integers (u)\n");
	printf("  4. Hexadecimal (x, X)\n");
	printf("  5. Mixed Formats\n");
	printf("  6. Edge Cases (INT_MIN, UINT_MAX, NULL, etc.)\n");
	printf("\n=========================== Bonus ============================\n\n");
	printf("  7. Flags, Width, and Precision (0, -, +, #, etc.)\n");
	printf("\n==============================================================\n");
	printf("\n  0. Exit\n");
}

void run_test(void (*func)())
{
	printf("\033[H\033[J");
	print_menu();
	printf("\n======================== Tests Output ========================\n\n");
	func();
	printf("\n==============================================================\n\n");
	printf("\nChoose an option: ");
}

int main(void)
{
	int choice;
	print_menu();
	printf("\nEscolha uma opção: ");
	while (scanf("%d", &choice) == 1) {
		int c;
		while ((c = getchar()) != '\n' && c != EOF);

		switch (choice)
		{
			case 1: run_test(test_basic); break;
			case 2: run_test(test_signed); break;
			case 3: run_test(test_unsigned); break;
			case 4: run_test(test_hex); break;
			case 5: run_test(test_mixed); break;
			case 6: run_test(test_edge); break;
			case 7: run_test(test_bonus); break;
			case 0:
				printf("\nExiting...\n");
				return 0;
			default:
				printf("\nInvalid option. Try again.\n");
				printf("\nEscolha uma opção: ");
				break;
		}
	}
	return 0;
}
*/
