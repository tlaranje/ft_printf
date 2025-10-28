/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:09:59 by tlaranje          #+#    #+#             */
/*   Updated: 2025/10/28 17:20:44 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void test_basic(void);
void test_signed(void);
void test_unsigned(void);
void test_hex(void);
void test_mixed(void);
void test_edge(void);
void test_bonus(void);

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
	// Clear terminal
	printf("\033[H\033[J");
	print_menu();
	printf("\n======================== Test Output =========================\n\n");
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

/* ========== TEST FUNCTIONS ========== */

void test_basic(void)
{
	char c = 'A';
	char *s = "42porto";
	char *null_s = NULL;
	void *ptr = s;
	void *null_ptr = NULL;
	int ft_ret, std_ret;

	printf(" ft_printf = \'%c\' | \"%s\" | \"%p\"    \n", c, s, s);
	ft_ret = ft_printf("	Char: %c | String: %s | Pointer: %p\n", c, s, ptr);
	printf("	ft_printf returned: %d\n\n", ft_ret);

	printf(" printf = \'%c\' | \"%s\" | \"%p\"    \n", c, s, s);
	std_ret = printf("	Char: %c | String: %s | Pointer: %p\n", c, s, ptr);
	printf("	printf returned: %d\n\n", std_ret);

	printf(" ft_printf = \"%s\" | \"%p\"    \n", null_s, null_ptr);
	ft_ret = ft_printf("	Null string: %s | Null pointer: %p\n", null_s, null_ptr);
	printf("	ft_printf returned: %d\n\n", ft_ret);

	printf(" printf = \"%s\" | \"%p\"    \n", null_s, null_ptr);
	std_ret = printf("	Null string: %s | Null pointer: %p\n", null_s, null_ptr);
	printf("	printf returned: %d\n", std_ret);

}

void test_signed(void)
{
	int i_nums[] = {0, 42, -42, INT_MAX, INT_MIN};
	int ft_ret, std_ret;

	for (int i = 0; i < 5; i++)
	{
		printf(" ft_printf = %d | %i\n", i_nums[i], i_nums[i]);
		ft_ret = ft_printf("	%%d: %d | %%i: %i\n", i_nums[i], i_nums[i]);
		printf("	ft_printf returned: %d\n", ft_ret);

		printf("\n printf = %d | %i\n", i_nums[i], i_nums[i]);
		std_ret = printf("	%%d: %d | %%i: %i\n", i_nums[i], i_nums[i]);
		printf("	printf returned: %d\n", std_ret);

		if (i < 4)
			printf("\n");
	}
}

void test_unsigned(void)
{
	unsigned int u_nums[] = {0, 42, UINT_MAX};
	int ft_ret, std_ret;

	printf("\n========== UNSIGNED INTEGERS ==========\n");
	for (int i = 0; i < 3; i++)
	{
		ft_ret = ft_printf("%%u: %u\n", u_nums[i]);
		std_ret = printf("%%u: %u\n", u_nums[i]);
		printf("ft_printf returned: %d | printf returned: %d\n\n", ft_ret, std_ret);
	}
}

void test_hex(void)
{
	unsigned int hex_nums[] = {0, 42, 255, UINT_MAX};
	int ft_ret, std_ret;

	printf("\n========== HEXADECIMAL ==========\n");
	for (int i = 0; i < 4; i++)
	{
		ft_ret = ft_printf("%%x: %x | %%X: %X\n", hex_nums[i], hex_nums[i]);
		std_ret = printf("%%x: %x | %%X: %X\n", hex_nums[i], hex_nums[i]);
		printf("ft_printf returned: %d | printf returned: %d\n\n", ft_ret, std_ret);
	}
}

void test_mixed(void)
{
	char c = 'Z';
	char *s = "42school";
	void *ptr = s;
	int ft_ret, std_ret;

	printf("\n========== MIXED FORMATS ==========\n");
	ft_ret = ft_printf("Mix: %c %s %p %d %i %u %x %X %%\n", c, s, ptr, 123, -123, 456U, 255U, 255U);
	std_ret = printf("Mix: %c %s %p %d %i %u %x %X %%\n", c, s, ptr, 123, -123, 456U, 255U, 255U);
	printf("ft_printf returned: %d | printf returned: %d\n\n", ft_ret, std_ret);
}

void test_edge(void)
{
	int ft_ret, std_ret;

	printf("\n========== EDGE CASES ==========\n");
	ft_ret = ft_printf("Zero: %d %u %x %X | INT_MIN: %d | INT_MAX: %d | UINT_MAX: %u\n",
					   0, 0U, 0U, 0U, INT_MIN, INT_MAX, UINT_MAX);
	std_ret = printf("Zero: %d %u %x %X | INT_MIN: %d | INT_MAX: %d | UINT_MAX: %u\n",
					 0, 0U, 0U, 0U, INT_MIN, INT_MAX, UINT_MAX);
	printf("ft_printf returned: %d | printf returned: %d\n\n", ft_ret, std_ret);
}

void test_bonus(void)
{
	char *s = "42school";
	int ft_ret, std_ret;

	printf("\n========== BONUS TESTS ==========\n");

	ft_ret = ft_printf("Right align width: '%5d'\n", 42);
	std_ret = printf("Right align width: '%5d'\n", 42);

	ft_ret = ft_printf("Left align width: '%-5d'\n", 42);
	std_ret = printf("Left align width: '%-5d'\n", 42);

	ft_ret = ft_printf("Zero padding: '%05d'\n", 42);
	std_ret = printf("Zero padding: '%05d'\n", 42);

	ft_ret = ft_printf("Sign '+' and space: '%+d', '% d'\n", 42, 42);
	std_ret = printf("Sign '+' and space: '%+d', '% d'\n", 42, 42);

	ft_ret = ft_printf("Negative number with width and zero: '%08d'\n", -42);
	std_ret = printf("Negative number with width and zero: '%08d'\n", -42);

	ft_ret = ft_printf("Precision with integer: '%.5d'\n", 42);
	std_ret = printf("Precision with integer: '%.5d'\n", 42);

	ft_ret = ft_printf("Precision with string: '%.5s'\n", s);
	std_ret = printf("Precision with string: '%.5s'\n", s);

	ft_ret = ft_printf("Hex with prefix and zero: '%#08x'\n", 255U);
	std_ret = printf("Hex with prefix and zero: '%#08x'\n", 255U);

	ft_ret = ft_printf("Multiple flags combined: '%-+10.5d'\n", 42);
	std_ret = printf("Multiple flags combined: '%-+10.5d'\n", 42);

	printf("\nft_printf returned: %d | printf returned: %d\n", ft_ret, std_ret);
}

