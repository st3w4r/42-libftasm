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
#include <ctype.h>
#include <assert.h>
#include <unistd.h>
#include "libfts.h"

#undef KO
#undef OK
#define KO "\x1B[1;31mKO\033[0m"
#define OK "\x1B[1;34mOK\033[0m"

#undef TRUE
#undef FALSE
#define TRUE 1
#define FALSE 0

#undef DEBUG
#define DEBUG 0


typedef unsigned char t_bool;


/* Functions test */

void	test_bzero();
// void	test_isalpha();
// void	test_isdigit();
// void	test_isalnum();
// void	test_isascii();
// void	test_isprint();
// void	test_toupper();
// void	test_tolower();
// void	test_puts();
// void	test_strlen();
// void	test_strcat();
void	test_memset();
void	test_memcpy();
void	test_strdup();
void	test_cat();
void	test_strcmp();
// void	test_putchar();
// void	test_putchar_fd();
void	test_memcmp();
void	test_strequ();
void	test_strcpy();


t_bool	test_isalpha(t_bool debug);
t_bool	test_isdigit(t_bool debug);
t_bool	test_isalnum(t_bool debug);
t_bool	test_isascii(t_bool debug);
t_bool	test_isprint(t_bool debug);
t_bool	test_toupper(t_bool debug);
t_bool	test_tolower(t_bool debug);
t_bool	test_puts(t_bool debug);
t_bool	test_strlen(t_bool debug);
t_bool	test_strcat(t_bool debug);

t_bool	test_putchar(t_bool debug);
t_bool	test_putchar_fd(t_bool debug);


/*
void	test_assert(int x)
{
		assert(x);
}

void	test_assert_string(char *s1, char *s2)
{
	assert(strcmp(s1, s2) == 0);
}
*/

void	print_mem_ascii(unsigned char *buffer)
{
	printf(" |");
	for (int j = 0; j < 16; j++)
		printf("%c", buffer[j]);
	printf("|");
}

void	print_mem(char *desc, void *addr, t_bool ascii, int len)
{
	unsigned char *p = addr;
	unsigned char buffer[16];
	int i = 0;
	int pos = 0;

	printf("%s", desc);
	while (i < len)
	{
		printf("\n");
		//ADDRESS
		if ((i % 16) == 0)
			printf("%p\t", &p[i]);

		//MEMORY
		int l = i + 16;
		int k = 0;
		bzero(buffer, 16);
		for (i = i; (i < l) && (i < len); i++)
		{
			printf("%02x", p[i]);
			buffer[k] = p[i];
			k == 7 ? printf("  ") : printf(" ");
			++k;
		}

		//ASCII
		if ((i % 16) == 0 && ascii)
			print_mem_ascii(buffer);
	}
	if (ascii)
		print_mem_ascii(buffer);
	printf("\n");
}

void	print_res_test(char *name, t_bool (*f)(t_bool))
{
	t_bool b;

	b = (*f)(DEBUG);
	printf("[\x1B[1;37m%s\033[0m] -> [%s]\n", name, (b ? OK : KO));
	if (!b)
		b = (*f)(1);
}


int main(void)
{
	// char str[] = "testabcdefgABCDEFGHIJKLM012345678901234567890123456789";
	// bzero(str, 10);
	// print_mem("s1", str, TRUE, sizeof str);
	//test_assert_string("Hello", "Hello");
	print_res_test("ft_isalpha", test_isalpha);
	print_res_test("ft_isdigit", test_isdigit);
	print_res_test("ft_isalnum", test_isalnum);
	print_res_test("ft_isascii", test_isascii);
	print_res_test("ft_isprint", test_isprint);
	print_res_test("ft_toupper", test_toupper);
	print_res_test("ft_tolower", test_tolower);
	print_res_test("ft_puts", test_puts);
	print_res_test("ft_strlen", test_strlen);
	print_res_test("ft_strcat", test_strcat);

	print_res_test("ft_putchar", test_putchar);
	print_res_test("ft_putchar_fd", test_putchar_fd);

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
	// test_memset();
	// test_memcpy();
	// test_strdup();
	// test_cat();
	// test_strcmp();
	// test_putchar();
	// test_putchar_fd();
	// test_memcmp();
	// test_strequ();
	//test_strcpy();

	return (0);
}

t_bool	test_isalpha(t_bool debug)
{
	t_bool ret = TRUE;
	t_bool test = TRUE;
	int i;
	char buffer[256] = {0};

	for (i = 0; i < 256; i++)
		buffer[i] = i;
	for (i = 0; i < 256; i++)
	{
		test = TRUE;
		if (isalpha(buffer[i]) != ft_isalpha(buffer[i]))
		{
			ret = FALSE;
			test = FALSE;
		}
		if (debug)
			printf("\t%d | %d | %d | [%s]\n", buffer[i], isalpha(buffer[i]), ft_isalpha(buffer[i]), test ? OK : KO);
	}
	return (ret);
}

t_bool	test_isdigit(t_bool debug)
{
	t_bool ret = TRUE;
	t_bool test = TRUE;
	int i;
	char buffer[256] = {0};

	for (i = 0; i < 256; i++)
		buffer[i] = i;
	for (i = 0; i < 256; i++)
	{
		test = TRUE;
		if (isdigit(buffer[i]) != ft_isdigit(buffer[i]))
		{
			ret = FALSE;
			test = FALSE;
		}
		if (debug)
			printf("\t%d | %d | %d | [%s]\n", buffer[i], isdigit(buffer[i]), ft_isdigit(buffer[i]), test ? OK : KO);
	}
	return (ret);
}

t_bool	test_isalnum(t_bool debug)
{
	t_bool ret = TRUE;
	t_bool test = TRUE;
	int i;
	char buffer[256] = {0};

	for (i = 0; i < 256; i++)
		buffer[i] = i;
	for (i = 0; i < 256; i++)
	{
		test = TRUE;
		if (isalnum(buffer[i]) != ft_isalnum(buffer[i]))
		{
			ret = FALSE;
			test = FALSE;
		}
		if (debug)
			printf("\t%d | %d | %d | [%s]\n", buffer[i], isalnum(buffer[i]), ft_isalnum(buffer[i]), test ? OK : KO);
	}
	return (ret);
}

t_bool	test_isascii(t_bool debug)
{
	t_bool ret = TRUE;
	t_bool test = TRUE;
	int i;
	char buffer[256] = {0};

	for (i = 0; i < 256; i++)
		buffer[i] = i;
	for (i = 0; i < 256; i++)
	{
		test = TRUE;
		if (isascii(buffer[i]) != ft_isascii(buffer[i]))
		{
			ret = FALSE;
			test = FALSE;
		}
		if (debug)
			printf("\t%d | %d | %d | [%s]\n", buffer[i], isascii(buffer[i]), ft_isascii(buffer[i]), test ? OK : KO);
	}
	return (ret);
}

t_bool	test_isprint(t_bool debug)
{
	t_bool ret = TRUE;
	t_bool test = TRUE;
	int i;
	char buffer[256] = {0};

	for (i = 0; i < 256; i++)
		buffer[i] = i;
	for (i = 0; i < 256; i++)
	{
		test = TRUE;
		if (isprint(buffer[i]) != ft_isprint(buffer[i]))
		{
			ret = FALSE;
			test = FALSE;
		}
		if (debug)
			printf("\t%d | %d | %d | [%s]\n", buffer[i], isprint(buffer[i]), ft_isprint(buffer[i]), test ? OK : KO);
	}
	return (ret);
}

t_bool	test_toupper(t_bool debug)
{
	t_bool ret = TRUE;
	t_bool test = TRUE;
	int i;
	char buffer[256] = {0};

	for (i = 0; i < 256; i++)
		buffer[i] = i;
	for (i = 0; i < 256; i++)
	{
		test = TRUE;
		if (toupper(buffer[i]) != ft_toupper(buffer[i]))
		{
			ret = FALSE;
			test = FALSE;
		}
		if (debug)
			printf("\t%d | %d | %d | [%s]\n", buffer[i], toupper(buffer[i]), ft_toupper(buffer[i]), test ? OK : KO);
	}
	return (ret);
}

t_bool	test_tolower(t_bool debug)
{
	t_bool ret = TRUE;
	t_bool test = TRUE;
	int i;
	char buffer[256] = {0};

	for (i = 0; i < 256; i++)
		buffer[i] = i;
	for (i = 0; i < 256; i++)
	{
		test = TRUE;
		if (tolower(buffer[i]) != ft_tolower(buffer[i]))
		{
			ret = FALSE;
			test = FALSE;
		}
		if (debug)
			printf("\t%d | %d | %d | [%s]\n", buffer[i], tolower(buffer[i]), ft_tolower(buffer[i]), test ? OK : KO);
	}
	return (ret);
}
/*
t_bool	test_puts(t_bool debug)
{
	t_bool ret = TRUE;
	t_bool test = TRUE;
	FILE *fp;
	char buff[255];
	char buff2[255];
	char *strings[] = {"test", "test2", "\n", "!@#$%^&*()-+", "\t", "A", "", " "};
	int pos = 0;

	while (pos < (sizeof(strings) / sizeof(char*)))
	{
		fp = freopen("test_puts_stdout", "w", stdout);

		ft_puts(strings[pos]);
		puts(strings[pos]);

		fclose(fp);
		freopen("/dev/tty", "w", stdout);
		fp = fopen("test_puts_stdout", "r");

		fscanf(fp, "%s", buff);
		fscanf(fp, "%s", buff2);

		if (strcmp(buff, buff2) != 0)
		{
			ret = FALSE;
			test = FALSE;
		}
		if (debug)
		{
			printf("->%s\n", strings[pos]);
			ft_puts(strings[pos]);
			puts(strings[pos]);
			printf("[%s]\n", test ? OK : KO);
		}
		++pos;
	}
	return (ret);
}
*/


t_bool	test_puts(t_bool debug)
{
	#undef BUFF_SIZE
	#define BUFF_SIZE 50
	t_bool ret = TRUE;
	t_bool test = TRUE;
	char *strings[] = {"test", "test2", "\n", "!@#$%^&*()-+", "\t", "A", "", " ", "0123", "dewdwedew", "lo\x00lololololpas vu", "lol ewf ewf ewf wef 909 ew0 9", NULL};
	char buff1[BUFF_SIZE + 1] = {0};
	char buff2[BUFF_SIZE + 1] = {0};
	int out_pipe[2];
	int saved_stdout;

	for (int pos = 0; pos < (sizeof(strings) / sizeof(char*)); pos++)
	{
		/*TEST 1*/
		bzero(buff1, BUFF_SIZE);
		saved_stdout = dup(STDOUT_FILENO);
		if(pipe(out_pipe) != 0) {
			exit(1);
		}
		dup2(out_pipe[1], STDOUT_FILENO);
		close(out_pipe[1]);
		puts(strings[pos]); /*PUTS CMD*/
		fflush(stdout);
		read(out_pipe[0], buff1, BUFF_SIZE);

		/*TEST 2*/
		bzero(buff2, BUFF_SIZE);
		if(pipe(out_pipe) != 0) {
			exit(1);
		}
		dup2(out_pipe[1], STDOUT_FILENO);
		close(out_pipe[1]);
		ft_puts(strings[pos]); /*FT_PUTS CMD*/
		fflush(stdout);
		read(out_pipe[0], buff2, BUFF_SIZE);

		/*AFF*/
		dup2(saved_stdout, STDOUT_FILENO);

		test = TRUE;
		if (strcmp(buff1, buff2) != 0)
		{
			ret = FALSE;
			test = FALSE;
		}
		if (debug)
		{
			printf("->%s\n", strings[pos]);
			puts(strings[pos]);
			ft_puts(strings[pos]);
			printf("[%s]\n", test ? OK : KO);
		}
	}
	return (ret);
}

t_bool	test_strlen(t_bool debug)
{
	t_bool ret = TRUE;
	t_bool test = TRUE;
	char *strings[] = {
		"test",
		"test2",
		"\n", "!@#$%^&*()-+",
		"\t", "A", "", " ",
		"0123", "dewdwedew",
		"lo\x00lololololpas vu",
		"lol ewf ewf ewf wef 909 ew0 9",
		"salut =)\x90\x90",
		"42 FTW\x01\x00\x90",
		"hey ooo \x90 dewfewfewfew",
		"bon\x00 dwedeeeeeeeeeee",
		"",
		"lolo\x01lol"
		};

	for (int pos = 0; pos < (sizeof(strings) / sizeof(char*)); pos++)
	{
		test = TRUE;
		if (strlen(strings[pos]) != ft_strlen(strings[pos]))
		{
			ret = FALSE;
			test = FALSE;
		}
		if (debug)
			printf("%s -> %lu | %lu | [%s]\n", strings[pos], strlen(strings[pos]), ft_strlen(strings[pos]), test ? OK : KO);
	}
	return (ret);
}

t_bool	test_strcat(t_bool debug)
{
	#undef SIZE
	#define SIZE 100
	t_bool ret = TRUE;
	t_bool test1 = TRUE;
	t_bool test2 = TRUE;
	char src1[][SIZE] = {
		"test",
		"ok",
		"ici",
		"",
		"x\0",
		"\x02",
		"\t"
		};
	char src2[][SIZE] = {
		"test",
		"ok",
		"ici",
		"",
		"x\0",
		"\x02",
		"\t"
		};
	char s_cat[][SIZE] = {
		"O",
		"B",
		"A",
		"AAsssdsdAsdasd",
		"\0",
		"\x02",
		"\t",
	};
	char *dst1;
	char *dst2;

	for (int pos = 0; pos < (sizeof(src1) / SIZE); pos++)
	{
		test1 = TRUE;
		test2 = TRUE;
		dst1 = strcat(src1[pos], s_cat[pos]);
		dst2 = ft_strcat(src2[pos], s_cat[pos]);

		if (memcmp(dst1, dst2, SIZE) != 0)
		{
			ret = FALSE;
			test1 = FALSE;
		}
		if (memcmp(src1[pos], src2[pos], SIZE) != 0)
		{
			ret = FALSE;
			test2 = FALSE;
		}
		if (debug)
		{
			printf("=====BY TEST=====\n");
			printf("%s | %s | [%s]\n",dst1, dst2, test1 ? OK : KO);
			print_mem("strcat: dst1", dst1, TRUE, SIZE);
			print_mem("ft_strcat: dst2", dst2, TRUE, SIZE);
			printf("\n");

			printf("%s | %s | [%s]\n",src1[pos], src2[pos], test2 ? OK : KO);
			print_mem("strcat: src1", src1[pos], TRUE, SIZE);
			print_mem("ft_strcat: src2", src2[pos], TRUE, SIZE);
			printf("\n");
		}
	}
	return (ret);
}

t_bool	test_putchar(t_bool debug)
{
	#undef BUFF_SIZE
	#define BUFF_SIZE 50
	t_bool ret = TRUE;
	t_bool test = TRUE;
	char strings[] = {'a', 'b', 'c', 'd', 'A', 'Z', '\0', ' ', 1, -5, -1, -0, -128, 255, '\t', '\n', 0, '\01'};
	char buff1[BUFF_SIZE + 1] = {0};
	char buff2[BUFF_SIZE + 1] = {0};
	int out_pipe[2];
	int saved_stdout;
	int ret1;
	int ret2;

	for (int pos = 0; pos < (sizeof(strings) / sizeof(char)); pos++)
	{
		/*TEST 1*/
		bzero(buff1, BUFF_SIZE);
		saved_stdout = dup(STDOUT_FILENO);
		if(pipe(out_pipe) != 0) {
			exit(1);
		}
		dup2(out_pipe[1], STDOUT_FILENO);
		close(out_pipe[1]);
		ret1 = 0;
		ret1 = putchar(strings[pos]); /*PUTCHAR CMD*/
		fflush(stdout);
		read(out_pipe[0], buff1, BUFF_SIZE);

		/*TEST 2*/
		bzero(buff2, BUFF_SIZE);
		if(pipe(out_pipe) != 0) {
			exit(1);
		}
		dup2(out_pipe[1], STDOUT_FILENO);
		close(out_pipe[1]);
		ret2 = 0;
		ret2 = ft_putchar(strings[pos]); /*FT_PUTCHAR CMD*/
		fflush(stdout);
		read(out_pipe[0], buff2, BUFF_SIZE);

		/*AFF*/
		dup2(saved_stdout, STDOUT_FILENO);

		test = TRUE;
		if (ret1 != ret2 || strcmp(buff1, buff2) != 0)
		{
			ret = FALSE;
			test = FALSE;
		}
		if (debug)
			printf(" -> %d -> %d | %d | [%s]\n", strings[pos], putchar(strings[pos]), ft_putchar(strings[pos]), test ? OK : KO);
	}
	return (ret);
}

t_bool	test_putchar_fd(t_bool debug)
{
	#undef BUFF_SIZE
	#define BUFF_SIZE 50
	#undef FD_TEST
	#define FD_TEST 1
	t_bool ret = TRUE;
	t_bool test = TRUE;
	char strings[] = {'a', 'b', 'c', 'd', 'A', 'Z', '\0', ' ', 1, -5, -1, -0, -128, 255, '\t', '\n', 0, '\01'};
	char buff1[BUFF_SIZE + 1] = {0};
	char buff2[BUFF_SIZE + 1] = {0};
	int out_pipe[2];
	int saved_stdout;
	int ret1;
	int ret2;

	for (int pos = 0; pos < (sizeof(strings) / sizeof(char)); pos++)
	{
		/*TEST 1*/
		bzero(buff1, BUFF_SIZE);
		saved_stdout = dup(STDOUT_FILENO);
		if(pipe(out_pipe) != 0) {
			exit(1);
		}
		dup2(out_pipe[1], FD_TEST);
		close(out_pipe[1]);
		ret1 = 0;
		ret1 = write(FD_TEST, &strings[pos], 1); /*PUTCHAR_FD FUNC*/
		fflush(stdout);
		read(out_pipe[0], buff1, BUFF_SIZE);

		/*TEST 2*/
		bzero(buff2, BUFF_SIZE);
		if(pipe(out_pipe) != 0) {
			exit(1);
		}
		dup2(out_pipe[1], FD_TEST);
		close(out_pipe[1]);
		ret2 = 0;
		ret2 = ft_putchar_fd(strings[pos], FD_TEST); /*FT_PUTCHAR_FD FUNC*/
		fflush(stdout);
		read(out_pipe[0], buff2, BUFF_SIZE);

		/*AFF*/
		dup2(saved_stdout, STDOUT_FILENO);

		test = TRUE;
		if (strcmp(buff1, buff2) != 0)
		{
			ret = FALSE;
			test = FALSE;
		}
		if (debug)
		{
			printf(" -> %d", strings[pos]);
			write(FD_TEST, &strings[pos], 1);
			ft_putchar_fd(strings[pos], FD_TEST);
			printf("[%s]\n", test ? OK : KO);
		}
	}
	return (ret);
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

/*
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
*/
/*
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
*/

/*
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
*/

/*
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
*/

/*
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
*/

/*
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
*/

/*
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
*/

/*
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
*/
	// puts(NULL);

/*
void test_strlen()
{
	//ft_strlen
	printf("Len: %lu\n", ft_strlen("TESTokTESTokTESTok"));
	printf("Len: %lu\n", ft_strlen("TEST"));
	printf("Len: %lu\n", ft_strlen("123"));
	printf("Len: %lu\n", ft_strlen("12"));
	printf("Len: %lu\n", ft_strlen("1"));
	printf("Len: %lu\n", ft_strlen(""));
	printf("Len: %lu\n", ft_strlen(NULL));
}
*/

/*
void	test_strcat()
{
	char s1[10] = "OK";
	char s2[5] = "test";
	// char s2[5] = "test";
	// char s3[10] = "LOL";

	// ft_strcat(s1, s2);

	// printf("%s", ft_strcat(s1, s2));
	char s10[10] = "OK";
	char s12[5] = "test";
	//char s13[10] = "LOL";
	printf("%s", strcat(s10, s12));
}*/

void	test_memset()
{
	char str[10] = "Salut";
	// ft_memset(&str, 'B', 2);
	printf("%s\n", ft_memset(&str, 'B', 3));

	putchar(str[0]);
	putchar(str[1]);
	putchar(str[2]);
	putchar(str[3]);
	putchar(str[4]);
	putchar(str[5]);
	putchar(str[6]);
	putchar(str[7]);
}

void	test_memcpy()
{
	char str_dst[20] = "0123456789ABCD";
	char str_src[20] = "SalutHello";

	ft_memcpy(&str_dst, &str_src, 5);
	printf("%s\n", str_src);
	printf("%s\n", str_dst);

	putchar(str_dst[0]);
	putchar(str_dst[1]);
	putchar(str_dst[2]);
	putchar(str_dst[3]);
	putchar(str_dst[4]);
	putchar(str_dst[5]);
	putchar(str_dst[6]);
	putchar(str_dst[7]);
	putchar(str_dst[8]);
	putchar(str_dst[9]);
	putchar(str_dst[10]);
	putchar(str_dst[11]);
	putchar(str_dst[12]);
	putchar(str_dst[13]);
}


void	test_strdup()
{

	char str_src[11] = "Salut";
	char *str_dst;
	str_dst = ft_strdup(str_src);
/*
	str_dst[0] = 'H';
	str_dst[1] = 'e';
	str_dst[2] = 'l';
	str_dst[3] = 'l';
	str_dst[4] = 'o';
	str_dst[5] = '\0';
	str_dst[6] = 'A';
	str_dst[7] = 'A';
	str_dst[8] = 'A';
	str_dst[9] = 'A';
	str_dst[10] = 'A';
*/
	// i = ft_strlen(str_src);
	// printf("%d\n", i);

	printf("%s\n", str_dst);

	putchar(str_dst[0]== 0 ? 'Z': str_dst[0]);
	putchar(str_dst[1]== 0 ? 'Z': str_dst[1]);
	putchar(str_dst[2]== 0 ? 'Z': str_dst[2]);
	putchar(str_dst[3]== 0 ? 'Z': str_dst[3]);
	putchar(str_dst[4]== 0 ? 'Z': str_dst[4]);
	putchar(str_dst[5]== 0 ? 'Z': str_dst[5]);
	putchar(str_dst[6]== 0 ? 'Z': str_dst[6]);
	putchar(str_dst[7]== 0 ? 'Z': str_dst[7]);
	putchar(str_dst[8]== 0 ? 'Z': str_dst[8]);
	putchar(str_dst[9]== 0 ? 'Z': str_dst[9]);
	putchar(str_dst[10]== 0 ? 'Z': str_dst[10]);

	free(str_dst);
}

#include <fcntl.h>

void	test_cat()
{
	int fd;

	fd = open("./ft_bzero.s", O_RDONLY);
	ft_cat(fd);
	// fd = open("./ft_cat.s", O_RDONLY);
	// ft_cat(fd);
}

void	test_strcmp()
{
	char s1[10] = "SalutA";
	char s2[10] = "SalutC";
	int diff;

	diff = ft_strcmp(s1, s2);
	printf("Diff: %d\n", diff);
	diff = strcmp(s1, s2);
	printf("Diff: %d\n", diff);
}
/*
void	test_putchar()
{
	ft_putchar('A');
	ft_putchar('a');
	ft_putchar('Z');
	ft_putchar('z');
	ft_putchar('0');
	ft_putchar(' ');
	ft_putchar(0);
	ft_putchar('4');
	ft_putchar('\n');

	putchar('A');
	putchar('a');
	putchar('Z');
	putchar('z');
	putchar('0');
	putchar(' ');
	putchar(0);
	putchar('4');
	putchar('\n');
}
*/
/*
void	test_putchar_fd()
{
	ft_putchar_fd('A', 2);
	ft_putchar_fd('a', 2);
	ft_putchar_fd('Z', 2);
	ft_putchar_fd('z', 1);
	ft_putchar_fd('0', 1);
	ft_putchar_fd(' ', 1);
	ft_putchar_fd(0, 1);
	ft_putchar_fd('4', 1);
	ft_putchar_fd('\n', 1);
}
*/
void	test_memcmp()
{
	char s1[10] = "SalutA";
	char s2[10] = "SalutB";
	int diff;

	diff = ft_memcmp(s1, s2, 5);
	printf("Diff: %d\n", diff);
	diff = memcmp(s1, s2, 5);
	printf("Diff: %d\n", diff);
}

void	test_strequ()
{
	char s1[10] = "SalutA";
	char s2[10] = "SalutA";
	int diff;

	diff = ft_strequ(s1, s2);
	printf("Diff: %d\n", diff);
}

void	test_strcpy()
{
	char str_dst[20] = "0123456789ABCD";
	char str_src[20] = "SalutHello";

	ft_strcpy(str_dst, str_src);
	printf("%s\n", str_src);
	printf("%s\n", str_dst);

	putchar(str_dst[0]);
	putchar(str_dst[1]);
	putchar(str_dst[2]);
	putchar(str_dst[3]);
	putchar(str_dst[4]);
	putchar(str_dst[5]);
	putchar(str_dst[6]);
	putchar(str_dst[7]);
	putchar(str_dst[8]);
	putchar(str_dst[9]);
	putchar(str_dst[10]);
	putchar(str_dst[11]);
	putchar(str_dst[12]);
	putchar(str_dst[13]);
}
