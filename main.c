/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 23:25:31 by ybarbier          #+#    #+#             */
/*   Updated: 2015/04/12 23:25:33 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

//Function ASM
void	ft_bzero(void *s, size_t n);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	ft_puts(char *s);
int		ft_strlen(char *s);
char	*ft_strcat(char *s1, const char *s2);
void	*ft_memset(void *b, int c, size_t len);

//Functions test
void	test_bzero();
void	test_isalpha();
void	test_isdigit();
void	test_isalnum();
void	test_isascii();
void	test_isprint();
void	test_toupper();
void	test_tolower();
void	test_puts();
void	test_strlen();
void	test_strcat();
void	test_memset();

int main(void)
{
	// test_bzero();
	// test_isalpha();
	// test_isdigit();
	// test_isalnum();
	// test_isascii();
	// test_isprint();
	// test_toupper();
	// test_tolower();
	// test_puts();
	// test_strlen();
	// test_strcat();
	test_memset();

	return (0);
}

void test_bzero()
{
	char str[10] = "Salut";
	ft_bzero(&str, 2);
	putchar(str[0]== 0 ? 'Z': str[0]);
	putchar(str[1]== 0 ? 'Z': str[1]);
	putchar(str[2]== 0 ? 'Z': str[2]);
	putchar(str[3]== 0 ? 'Z': str[3]);
	putchar(str[4]== 0 ? 'Z': str[4]);
	putchar(str[5]== 0 ? 'Z': str[5]);
	putchar(str[6]== 0 ? 'Z': str[6]);
	putchar(str[7]== 0 ? 'Z': str[7]);
}

void test_isalpha()
{
	//Is Alpha
	// Majuscule
	printf("Is alpha: %d\n", ft_isalpha('A'));
	printf("Is alpha: %d\n", ft_isalpha('B'));
	printf("Is alpha: %d\n", ft_isalpha('Z'));

	printf("Is alpha: %d\n", ft_isalpha('a'));
	printf("Is alpha: %d\n", ft_isalpha('b'));
	printf("Is alpha: %d\n", ft_isalpha('z'));

	printf("Is alpha: %d\n", ft_isalpha(0x41));
	printf("Is alpha: %d\n", ft_isalpha(0x5a));

	//False
	printf("Is alpha: %d\n", ft_isalpha(0x40));
	printf("Is alpha: %d\n", ft_isalpha(0x5b));
	printf("Is alpha: %d\n", ft_isalpha(0x5c));

	// Minuscule
	//False
	printf("Is alpha: %d\n", ft_isalpha(0x7c));
	printf("Is alpha: %d\n", ft_isalpha(0x5e));
}

void test_isdigit()
{
	//Is Digit
	//True
	printf("Is digit: %d\n", ft_isdigit(0x30));
	printf("Is digit: %d\n", ft_isdigit('0'));
	printf("Is digit: %d\n", ft_isdigit('1'));
	printf("Is digit: %d\n", ft_isdigit('2'));
	printf("Is digit: %d\n", ft_isdigit('3'));
	printf("Is digit: %d\n", ft_isdigit('4'));
	printf("Is digit: %d\n", ft_isdigit('5'));
	printf("Is digit: %d\n", ft_isdigit('6'));
	printf("Is digit: %d\n", ft_isdigit('7'));
	printf("Is digit: %d\n", ft_isdigit('8'));
	printf("Is digit: %d\n", ft_isdigit('9'));
	printf("Is digit: %d\n", ft_isdigit(0x39));

	//False
	printf("Is digit: %d\n", ft_isdigit(0x29));
	printf("Is digit: %d\n", ft_isdigit(0x3a));
	printf("Is digit: %d\n", ft_isdigit('/'));
	printf("Is digit: %d\n", ft_isdigit('.'));
	printf("Is digit: %d\n", ft_isdigit(':'));
}

void test_isalnum()
{
	//Is Alpha num
	printf("__TRUE__\n");
	printf("Is digit: %d\n", ft_isalnum(0x30));
	printf("Is digit: %d\n", ft_isalnum('0'));
	printf("Is digit: %d\n", ft_isalnum('1'));
	printf("Is digit: %d\n", ft_isalnum('2'));
	printf("Is digit: %d\n", ft_isalnum('3'));
	printf("Is digit: %d\n", ft_isalnum('4'));
	printf("Is digit: %d\n", ft_isalnum('5'));
	printf("Is digit: %d\n", ft_isalnum('6'));
	printf("Is digit: %d\n", ft_isalnum('7'));
	printf("Is digit: %d\n", ft_isalnum('8'));
	printf("Is digit: %d\n", ft_isalnum('9'));
	printf("Is digit: %d\n", ft_isalnum(0x39));

	// Majuscule
	printf("Is alpha: %d\n", ft_isalnum('A'));
	printf("Is alpha: %d\n", ft_isalnum('B'));
	printf("Is alpha: %d\n", ft_isalnum('Z'));

	printf("Is alpha: %d\n", ft_isalnum('a'));
	printf("Is alpha: %d\n", ft_isalnum('b'));
	printf("Is alpha: %d\n", ft_isalnum('z'));

	printf("Is alpha: %d\n", ft_isalnum(0x41));
	printf("Is alpha: %d\n", ft_isalnum(0x5a));

	printf("__FALSE__\n");

	//False
	printf("Is alpha: %d\n", ft_isalnum(0x40));
	printf("Is alpha: %d\n", ft_isalnum(0x5b));
	printf("Is alpha: %d\n", ft_isalnum(0x5c));

	// Minuscule
	//False
	printf("Is alpha: %d\n", ft_isalnum(0x7c));
	printf("Is alpha: %d\n", ft_isalnum(0x5e));

	//False
	printf("Is digit: %d\n", ft_isalnum(0x29));
	printf("Is digit: %d\n", ft_isalnum(0x3a));
	printf("Is digit: %d\n", ft_isalnum('/'));
	printf("Is digit: %d\n", ft_isalnum('.'));
	printf("Is digit: %d\n", ft_isalnum(':'));


	//False
	printf("Is digit: %d\n", ft_isalnum(0x29));
	printf("Is digit: %d\n", ft_isalnum(0x3a));
	printf("Is digit: %d\n", ft_isalnum('/'));
	printf("Is digit: %d\n", ft_isalnum('.'));
	printf("Is digit: %d\n", ft_isalnum(':'));
	printf("Is digit: %d\n", ft_isalnum(0));

}

void test_isascii()
{
	//Is ASCII
	//True
	printf("__TRUE__\n");

	printf("Is ascii: %d\n", ft_isascii(0x29));
	printf("Is ascii: %d\n", ft_isascii(0));
	printf("Is ascii: %d\n", ft_isascii(0x51));
	printf("Is ascii: %d\n", ft_isascii(101));
	printf("Is ascii: %d\n", ft_isascii(44));
	printf("Is ascii: %d\n", ft_isascii(127));
	printf("Is ascii: %d\n", ft_isascii('a'));


	//False
	printf("__FALSE__\n");

	printf("Is ascii: %d\n", ft_isascii(-1));
	printf("Is ascii: %d\n", ft_isascii(128));
	printf("Is ascii: %d\n", ft_isascii(0x8a));
	printf("Is ascii: %d\n", ft_isascii(129));
}

void test_isprint()
{
	//Is Print
	//True
	printf("__TRUE__\n");

	printf("Is print: %d\n", ft_isprint(0x29));
	printf("Is print: %d\n", ft_isprint(0x51));
	printf("Is print: %d\n", ft_isprint(101));
	printf("Is print: %d\n", ft_isprint(44));
	printf("Is print: %d\n", ft_isprint('a'));
	printf("Is print: %d\n", ft_isprint(0x20));
	printf("Is print: %d\n", ft_isprint(' '));
	printf("Is print: %d\n", ft_isprint(55));


	//False
	printf("__FALSE__\n");

	printf("Is print: %d\n", ft_isprint('	'));
	printf("Is print: %d\n", ft_isprint('\t'));
	printf("Is print: %d\n", ft_isprint(127));
	printf("Is print: %d\n", ft_isprint(0));
	printf("Is print: %d\n", ft_isprint(-1));
	printf("Is print: %d\n", ft_isprint(128));
	printf("Is print: %d\n", ft_isprint(0x8a));
	printf("Is print: %d\n", ft_isprint(129));
}

void test_toupper()
{
	//ToUpper
	//True
	printf("__TRUE__\n");

	printf("ToUpper: %c\n", ft_toupper('a'));
	printf("ToUpper: %c\n", ft_toupper('b'));
	printf("ToUpper: %c\n", ft_toupper('y'));
	printf("ToUpper: %c\n", ft_toupper('z'));
	printf("ToUpper: %c\n", ft_toupper('e'));
	printf("ToUpper: %c\n", ft_toupper('o'));
	printf("ToUpper: %c\n", ft_toupper(98));
	printf("ToUpper: %c\n", ft_toupper(97));
	printf("ToUpper: %c\n", ft_toupper(122));


	//False
	printf("__FALSE__\n");

	printf("ToUpper: %c\n", ft_toupper('A'));
	printf("ToUpper: %c\n", ft_toupper('B'));
	printf("ToUpper: %c\n", ft_toupper('Z'));
	printf("ToUpper: %c\n", ft_toupper(0));
	printf("ToUpper: %c\n", ft_toupper(92));
	printf("ToUpper: %c\n", ft_toupper(96));
	printf("ToUpper: %c\n", ft_toupper(123));
	printf("ToUpper: %c\n", ft_toupper(' '));
	printf("ToUpper: %c\n", ft_toupper('	'));
	printf("ToUpper: %c\n", ft_toupper('\t'));
	printf("ToUpper: %c\n", ft_toupper(127));
	printf("ToUpper: %c\n", ft_toupper(0));
	printf("ToUpper: %c\n", ft_toupper(-1));
	printf("ToUpper: %c\n", ft_toupper(128));
	printf("ToUpper: %c\n", ft_toupper(0x8a));
	printf("ToUpper: %c\n", ft_toupper(129));
}

void test_tolower()
{
	//ToLower
	printf("__ToLower__\n");
	//True
	printf("__TRUE__\n");
	printf("ToLower: %c\n", ft_tolower('A'));
	printf("ToLower: %c\n", ft_tolower('B'));
	printf("ToLower: %c\n", ft_tolower('C'));
	printf("ToLower: %c\n", ft_tolower('Z'));
	printf("ToLower: %c\n", ft_tolower('E'));
	printf("ToLower: %c\n", ft_tolower('O'));
	printf("ToLower: %c\n", ft_tolower(66));
	printf("ToLower: %c\n", ft_tolower(67));
	printf("ToLower: %c\n", ft_tolower(90));


	//False
	printf("__FALSE__\n");
	printf("ToLower: %c\n", ft_tolower('a'));
	printf("ToLower: %c\n", ft_tolower('b'));
	printf("ToLower: %c\n", ft_tolower('y'));
	printf("ToLower: %c\n", ft_tolower('z'));
	printf("ToLower: %c\n", ft_tolower('e'));
	printf("ToLower: %c\n", ft_tolower('o'));
	printf("ToLower: %c\n", ft_tolower(98));
	printf("ToLower: %c\n", ft_tolower(97));
	printf("ToLower: %c\n", ft_tolower(122));
	printf("ToLower: %c\n", ft_tolower(0));
	printf("ToLower: %c\n", ft_tolower(92));
	printf("ToLower: %c\n", ft_tolower(96));
	printf("ToLower: %c\n", ft_tolower(123));
	printf("ToLower: %c\n", ft_tolower(' '));
	printf("ToLower: %c\n", ft_tolower('	'));
	printf("ToLower: %c\n", ft_tolower('\t'));
	printf("ToLower: %c\n", ft_tolower(127));
	printf("ToLower: %c\n", ft_tolower(0));
	printf("ToLower: %c\n", ft_tolower(-1));
	printf("ToLower: %c\n", ft_tolower(128));
	printf("ToLower: %c\n", ft_tolower(0x8a));
	printf("ToLower: %c\n", ft_tolower(129));
}

void test_puts()
{
	//ft_puts
	// printf("__ft_puts__\n");
	ft_puts("Ok");
	ft_puts("");
	ft_puts("YES");
	ft_puts("PLPLPLPLLASDPALSDLPASDL");
	ft_puts(NULL);
}
	// puts(NULL);

void test_strlen()
{
	//ft_strlen
	printf("Len: %d\n", ft_strlen("TESTokTESTokTESTok"));
	printf("Len: %d\n", ft_strlen("TEST"));
	printf("Len: %d\n", ft_strlen("123"));
	printf("Len: %d\n", ft_strlen("12"));
	printf("Len: %d\n", ft_strlen("1"));
	printf("Len: %d\n", ft_strlen(""));
	printf("Len: %d\n", ft_strlen(NULL));
}

void	test_strcat()
{
	/*
	char s1[10] = "OK";
	char s2[5] = "test";
	// char s2[5] = "test";
	// char s3[10] = "LOL";

	// ft_strcat(s1, s2);

	printf("%s", ft_strcat(s1, s2));
	*/
	char s10[10] = "OK";
	char s12[5] = "test";
	//char s13[10] = "LOL";
	printf("%s", strcat(s10, s12));
/*
*/
}

void	test_memset()
{
	char str[10] = "Salut";
	ft_memset(&str, 'B', 1);
	putchar(str[0]);
	putchar(str[1]);
	putchar(str[2]);
	putchar(str[3]);
	putchar(str[4]);
	putchar(str[5]);
	putchar(str[6]);
	putchar(str[7]);
}
