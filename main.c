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

t_bool	test_bzero(t_bool debug);
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
t_bool	test_strdup(t_bool debug);
t_bool	test_strcmp(t_bool debug);
t_bool	test_strequ(t_bool debug);
t_bool	test_strcpy(t_bool debug);
t_bool	test_memset(t_bool debug);
t_bool	test_memcpy(t_bool debug);
t_bool	test_memcmp(t_bool debug);
t_bool	test_putchar(t_bool debug);
t_bool	test_putchar_fd(t_bool debug);
t_bool	test_cat(t_bool debug);
t_bool	test_cat_fd_0(t_bool debug);


/* Print memory*/
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

/* Print and execute test*/

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
	print_res_test("ft_bzero", test_bzero);
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
	print_res_test("ft_strdup", test_strdup);
	print_res_test("ft_strcmp", test_strcmp);
	print_res_test("ft_strequ", test_strequ);
	print_res_test("ft_strcpy", test_strcpy);
	print_res_test("ft_memset", test_memset);
	print_res_test("ft_memcpy", test_memcpy);
	print_res_test("ft_memcmp", test_memcmp);
	print_res_test("ft_putchar", test_putchar);
	print_res_test("ft_putchar_fd", test_putchar_fd);
	print_res_test("ft_cat", test_cat);
	// print_res_test("ft_cat fd 0", test_cat_fd_0);
	return (0);
}

t_bool	test_bzero(t_bool debug)
{
	#undef SIZE
	#define SIZE 100
	t_bool ret = TRUE;
	t_bool test1 = TRUE;
	t_bool test2 = TRUE;
	char src1[][SIZE] = {
		"test",
		"ok",
		"iciAB",
		"",
		"x\0",
		"\x02",
		"\t",
		"OKokOKokOKOK"
		};
	char src2[][SIZE] = {
		"test",
		"ok",
		"iciAB",
		"",
		"x\0",
		"\x02",
		"\t",
		"OKokOKokOKOK"
		};
	int size_arr[] = {0, 2, 4, 4, 5, 5, 100, 3};

	for (int pos = 0; pos < (sizeof(src1) / SIZE); pos++)
	{
		test1 = TRUE;
		test2 = TRUE;
		bzero(src1[pos], size_arr[pos]);
		ft_bzero(src2[pos], size_arr[pos]);

		if (memcmp(src1[pos], src2[pos], SIZE) != 0)
		{
			ret = FALSE;
			test2 = FALSE;
		}
		if (debug)
		{
			printf("%s | %s | [%s]\n",src1[pos], src2[pos], test2 ? OK : KO);
			print_mem("bzero: src1", src1[pos], TRUE, SIZE);
			print_mem("ft_bzero: src2", src2[pos], TRUE, SIZE);
			printf("\n");
		}
	}
	return (ret);
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
		"\t"
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

t_bool	test_strdup(t_bool debug)
{
	#undef SIZE
	#define SIZE 100
	t_bool ret = TRUE;
	t_bool test1 = TRUE;
	t_bool test2 = TRUE;
	char src1[][SIZE] = {
		"testOkA asd  ddsd 	sww	sadsd",
		"ok",
		"ici",
		"",
		"x\0",
		"\x02",
		"\t",
		"0123456789abcdefgh",
		"\n",
		"||||||\x00|||||||\\ _=+212312340"
		};
	char src2[][SIZE] = {
		"testOkA asd  ddsd 	sww	sadsd",
		"ok",
		"ici",
		"",
		"x\0",
		"\x02",
		"\t",
		"0123456789abcdefgh",
		"\n",
		"||||||\x00|||||||\\ _=+212312340"
		};
	char *dst1;
	char *dst2;

	for (int pos = 0; pos < (sizeof(src1) / SIZE); pos++)
	{
		test1 = TRUE;
		test2 = TRUE;
		dst1 = strdup(src1[pos]);
		dst2 = ft_strdup(src2[pos]);

		if (strcmp(dst1, dst2) != 0)
		{
			ret = FALSE;
			test1 = FALSE;
		}
		if (strcmp(src1[pos], src2[pos]) != 0)
		{
			ret = FALSE;
			test2 = FALSE;
		}
		if (debug)
		{
			printf("=====BY TEST=====\n");
			printf("%s | %s | [%s]\n",dst1, dst2, test1 ? OK : KO);
			print_mem("strdup: dst1", dst1, TRUE, SIZE);
			print_mem("ft_strdup: dst2", dst2, TRUE, SIZE);
			printf("\n");

			printf("%s | %s | [%s]\n",src1[pos], src2[pos], test2 ? OK : KO);
			print_mem("strdup: src1", src1[pos], TRUE, SIZE);
			print_mem("ft_strdup: src2", src2[pos], TRUE, SIZE);
			printf("\n");
		}
	}
	return (ret);
}

t_bool	test_strcmp(t_bool debug)
{
	t_bool ret = TRUE;
	t_bool test = TRUE;
	char *src1[] = {
		"testOkA asd  ddsd 	sww	sadsd",
		"ok",
		"ici",
		"",
		"x\0",
		"\x02",
		"\t",
		"0123456789abcdefgh",
		"\n",
		"||||||\x00|||||||\\ _=+212312340",
		"testOkA asd  ddsd 	sww	sadsd", //DIFF
		"ok",
		"ici",
		"",
		"x\0",
		"\x02",
		"\t",
		"0123456789abcdefgh",
		"\n",
		"||||||\x00|||||||\\ _=+212312340"
		};
	char *src2[] = {
		"testOkA asd  ddsd 	sww	sadsd",
		"ok",
		"ici",
		"",
		"x\0",
		"\x02",
		"\t",
		"0123456789abcdefgh",
		"\n",
		"||||||\x00|||||||\\ _=+212312340",
		"testOkA asd  ddsd 	sww	sadsd ", //DIFF
		"Aok",
		"i1ci",
		"\0",
		"x",
		"\x02\t",
		"\t\n",
		"6789abcdefgh",
		"",
		"||||||\x00|||||||\\ _=+212312340            "
		};

	for (int pos = 0; pos < (sizeof(src1) / (sizeof(char*))); pos++)
	{
		test = TRUE;
		if (strcmp(src1[pos], src2[pos]) != ft_strcmp(src1[pos], src2[pos]))
		{
			ret = FALSE;
			test = FALSE;
		}
		if (debug)
			printf("%s | %s | %d | %d | [%s]\n",src1[pos], src2[pos], strcmp(src1[pos], src2[pos]), ft_strcmp(src1[pos], src2[pos]), test ? OK : KO);
	}
	return (ret);
}

t_bool	test_strequ(t_bool debug)
{
	#undef SIZE
	#define SIZE 100
	t_bool ret = TRUE;
	t_bool test = TRUE;
	char src1[][SIZE] = {
		"testOkA asd  ddsd 	sww	sadsd",
		"ok",
		"ici",
		"",
		"x\0 42",
		"\x02",
		"\t",
		"0123456789abcdefgh",
		"\n",
		"||||||\x00|||||||\\ _=+212312340",
		"testOkA asd  ddsd 	sww	sadsd", //DIFF
		"ok",
		"ici",
		"",
		"x\0",
		"\x02",
		"\t",
		"0123456789abcdefgh",
		"\n",
		"||||||\x00|||||||\\ _=+212312340",
		"A\x00\t"
		};
	char src2[][SIZE] = {
		"testOkA asd  ddsd 	sww	sadsd",
		"ok",
		"ici",
		"",
		"x\0 42",
		"\x02",
		"\t",
		"0123456789abcdefgh",
		"\n",
		"||||||\x00|||||||\\ _=+212312340",
		"testOkA asd  ddsd 	sww	sadsd ", //DIFF
		"Aok",
		"i1ci",
		"\0",
		"x",
		"\x02\t",
		"\t\n",
		"6789abcdefgh",
		"",
		"||||||\x00|||||||\\ _=+212312340            ",
		"A\x00\x01"
		};

	for (int pos = 0; pos < (sizeof(src1) / SIZE); pos++)
	{
		test = TRUE;
		if ((strcmp(src1[pos], src2[pos]) == 0) != ft_strequ(src1[pos], src2[pos]))
		{
			ret = FALSE;
			test = FALSE;
		}
		if (debug)
		{
			printf("%s | %s | %d | %d | [%s]\n",src1[pos], src2[pos], (strcmp(src1[pos], src2[pos]) == 0), ft_strequ(src1[pos], src2[pos]), test ? OK : KO);
			printf("\n");
			print_mem("src1", src1[pos], TRUE, SIZE);
			print_mem("src2", src2[pos], TRUE, SIZE);
			printf("\n");
		}
	}
	return (ret);
}

t_bool	test_strcpy(t_bool debug)
{
	#undef SIZE
	#define SIZE 100
	t_bool ret = TRUE;
	t_bool test1 = TRUE;
	t_bool test2 = TRUE;
	char src1[][SIZE] = {
		"testOkA asd  ddsd 	sww	sadsd",
		"ok",
		"ici",
		"",
		"x\0",
		"\x02",
		"\t",
		"0123456789abcdefgh",
		"\n",
		"||||||\x00|||||||\\ _=+212312340",
		"HelloHelloHelloHelloHello",
		"Hello",
		"OOOOOOOOOOOOOOOOOOOOOOOOOOOO"
		};
	char src2[][SIZE] = {
		"testOkA asd  ddsd 	sww	sadsd",
		"ok",
		"ici",
		"",
		"x\0",
		"\x02",
		"\t",
		"0123456789abcdefgh",
		"\n",
		"||||||\x00|||||||\\ _=+212312340",
		"HelloHelloHelloHelloHello",
		"Hello",
		"OOOOOOOOOOOOOOOOOOOOOOOOOOOO"
		};
	char s_cpy[][SIZE] = {
		"O\x20",
		"B",
		"A",
		"AAsssdsdAsdasd",
		"\0",
		"\x02",
		"\t",
		"POPoPOpO",
		"\00\00ASF",
		"12345",
		"Monsieur",
		"MonsieurMonsieurMonsieurMonsieurMonsieur",
		"H"
	};
	char *dst1;
	char *dst2;

	for (int pos = 0; pos < (sizeof(src1) / SIZE); pos++)
	{
		test1 = TRUE;
		test2 = TRUE;
		dst1 = strcpy(src1[pos], s_cpy[pos]);
		dst2 = ft_strcpy(src2[pos], s_cpy[pos]);

		if (memcmp(dst1, dst2, strlen(dst1)) != 0)
		{
			ret = FALSE;
			test1 = FALSE;
		}
		if (memcmp(src1[pos], src2[pos], strlen(dst1)) != 0)
		{
			ret = FALSE;
			test2 = FALSE;
		}
		if (debug)
		{
			printf("=====BY TEST=====\n");
			printf("%s | %s | [%s]\n",dst1, dst2, test1 ? OK : KO);
			print_mem("strcpy: dst1", dst1, TRUE, SIZE);
			print_mem("ft_strcpy: dst2", dst2, TRUE, SIZE);
			printf("\n");

			printf("%s | %s | [%s]\n",src1[pos], src2[pos], test2 ? OK : KO);
			print_mem("strcpy: src1", src1[pos], TRUE, SIZE);
			print_mem("ft_strcpy: src2", src2[pos], TRUE, SIZE);
			printf("\n");
		}
	}
	return (ret);
}

t_bool	test_memset(t_bool debug)
{
	#undef SIZE
	#define SIZE 100
	t_bool ret = TRUE;
	t_bool test1 = TRUE;
	t_bool test2 = TRUE;
	char src1[][SIZE] = {
		"testOkA asd  ddsd 	sww	sadsd",
		"ok",
		"ici",
		"",
		"x\0",
		"\x02",
		"\t",
		"0123456789abcdefgh",
		"\n",
		"||||||\x00|||||||\\ _=+212312340"
		};
	char src2[][SIZE] = {
		"testOkA asd  ddsd 	sww	sadsd",
		"ok",
		"ici",
		"",
		"x\0",
		"\x02",
		"\t",
		"0123456789abcdefgh",
		"\n",
		"||||||\x00|||||||\\ _=+212312340"
		};
	char c_set[] = {
		'O',
		'B',
		'A',
		'z',
		'\0',
		'\x02',
		'\t',
		'X',
		0,
		'Z'
	};
	int size_arr[] = {0, 2, 4, 4, 5, 5, 100, 2, 13, 5};
	char *dst1;
	char *dst2;

	for (int pos = 0; pos < (sizeof(src1) / SIZE); pos++)
	{
		test1 = TRUE;
		test2 = TRUE;
		dst1 = memset(src1[pos], c_set[pos], size_arr[pos]);
		dst2 = ft_memset(src2[pos], c_set[pos], size_arr[pos]);

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
			printf("%s | %s | %d | [%s]\n",dst1, dst2, size_arr[pos], test1 ? OK : KO);
			print_mem("memset: dst1", dst1, TRUE, SIZE);
			print_mem("ft_memset: dst2", dst2, TRUE, SIZE);
			printf("\n");

			printf("%s | %s | %d | [%s]\n",src1[pos], src2[pos], size_arr[pos], test2 ? OK : KO);
			print_mem("memset: src1", src1[pos], TRUE, SIZE);
			print_mem("ft_memset: src2", src2[pos], TRUE, SIZE);
			printf("\n");
		}
	}
	return (ret);
}

t_bool	test_memcpy(t_bool debug)
{
	#undef SIZE
	#define SIZE 100
	t_bool ret = TRUE;
	t_bool test1 = TRUE;
	t_bool test2 = TRUE;
	char src1[][SIZE] = {
		"testOkA asd  ddsd 	sww	sadsd",
		"ok",
		"ici",
		"",
		"x\0",
		"\x02",
		"\t",
		"0123456789abcdefgh",
		"\n",
		"||||||\x00|||||||\\ _=+212312340"
		};
	char src2[][SIZE] = {
		"testOkA asd  ddsd 	sww	sadsd",
		"ok",
		"ici",
		"",
		"x\0",
		"\x02",
		"\t",
		"0123456789abcdefgh",
		"\n",
		"||||||\x00|||||||\\ _=+212312340"
		};
	char s_cpy[][SIZE] = {
		"O",
		"B",
		"A",
		"AAsssdsdAsdasd",
		"\0",
		"\x02",
		"\t",
		"POPoPOpO",
		"\00\00ASF",
		"12345"
	};
	int size_arr[] = {0, 2, 4, 4, 5, 5, 100, 2, 13, 5};
	char *dst1;
	char *dst2;

	for (int pos = 0; pos < (sizeof(src1) / SIZE); pos++)
	{
		test1 = TRUE;
		test2 = TRUE;
		dst1 = memcpy(src1[pos], s_cpy[pos], size_arr[pos]);
		dst2 = ft_memcpy(src2[pos], s_cpy[pos], size_arr[pos]);

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
			printf("%s | %s | %d | [%s]\n",dst1, dst2, size_arr[pos], test1 ? OK : KO);
			print_mem("memcpy: dst1", dst1, TRUE, SIZE);
			print_mem("ft_memcpy: dst2", dst2, TRUE, SIZE);
			printf("\n");

			printf("%s | %s | %d | [%s]\n",src1[pos], src2[pos], size_arr[pos], test2 ? OK : KO);
			print_mem("memcpy: src1", src1[pos], TRUE, SIZE);
			print_mem("ft_memcpy: src2", src2[pos], TRUE, SIZE);
			printf("\n");
		}
	}
	return (ret);
}

t_bool	test_memcmp(t_bool debug)
{
	#undef SIZE
	#define SIZE 100
	t_bool ret = TRUE;
	t_bool test = TRUE;
	char src1[][SIZE] = {
		"testOkA asd  ddsd 	sww	sadsd",
		"ok",
		"ici",
		"",
		"x\0 42",
		"\x02",
		"\t",
		"0123456789abcdefgh",
		"\n",
		"||||||\x00|||||||\\ _=+212312340",
		"testOkA asd  ddsd 	sww	sadsd", //DIFF
		"ok",
		"ici",
		"",
		"x\0",
		"\x02",
		"\t",
		"0123456789abcdefgh",
		"\n",
		"||||||\x00|||||||\\ _=+212312340",
		"A\x00\t"
		};
	char src2[][SIZE] = {
		"testOkA asd  ddsd 	sww	sadsd",
		"ok",
		"ici",
		"",
		"x\0 42",
		"\x02",
		"\t",
		"0123456789abcdefgh",
		"\n",
		"||||||\x00|||||||\\ _=+212312340",
		"testOkA asd  ddsd 	sww	sadsd ", //DIFF
		"Aok",
		"i1ci",
		"\0",
		"x",
		"\x02\t",
		"\t\n",
		"6789abcdefgh",
		"",
		"||||||\x00|||||||\\ _=+212312340            ",
		"A\x00\x01"
		};

	for (int pos = 0; pos < (sizeof(src1) / SIZE); pos++)
	{
		test = TRUE;
		if (memcmp(src1[pos], src2[pos], SIZE) != ft_memcmp(src1[pos], src2[pos], SIZE))
		{
			ret = FALSE;
			test = FALSE;
		}
		if (debug)
		{
			printf("%s | %s | %d | %d | [%s]\n",src1[pos], src2[pos], memcmp(src1[pos], src2[pos], SIZE/2), ft_memcmp(src1[pos], src2[pos], SIZE/2), test ? OK : KO);
			printf("\n");
			print_mem("src1", src1[pos], FALSE, SIZE);
			print_mem("src2", src2[pos], FALSE, SIZE);
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

#include <fcntl.h>
t_bool	test_cat(t_bool debug)
{
	#undef BUFF_SIZE
	#define BUFF_SIZE 10000
	t_bool	ret = TRUE;
	t_bool	test = TRUE;
	char	buff1[BUFF_SIZE + 1] = {0};
	char	buff2[BUFF_SIZE + 1] = {0};
	int		out_pipe[2];
	int		saved_stdout;
	pid_t	father;
	int		fd;
	char	*files[] = {
		"./src/ft_bzero.s",
		"./src/ft_strcmp.s",
		"./src/ft_memset.s",
		"./Makefile",
		"./auteur"
	};

	char cmd[] = "cat";

	for (int pos = 0; pos < (sizeof(files) / sizeof(char*)); pos++)
	{
		char *args[] = {"cat", files[pos], NULL};

		//TEST 1
		bzero(buff1, BUFF_SIZE);
		saved_stdout = dup(STDOUT_FILENO);
		if(pipe(out_pipe) != 0) {
			exit(1);
		}
		dup2(out_pipe[1], STDOUT_FILENO);
		close(out_pipe[1]);

		//CAT CMD//
		father = fork();
		if (father > 0)
			wait(0);
		else if (father == 0)
		{
			if (execvp(cmd, args) == -1)
				puts("Exec format error.\n");
			exit(0);
		}

		fflush(stdout);
		read(out_pipe[0], buff1, BUFF_SIZE);

		//TEST 2
		bzero(buff2, BUFF_SIZE);
		if(pipe(out_pipe) != 0) {
			exit(1);
		}
		dup2(out_pipe[1], STDOUT_FILENO);
		close(out_pipe[1]);
			//FT_CAT CMD//
			fd = open(files[pos], O_RDONLY);
				ft_cat(fd); //FT_CAT CMD//
			close(fd);

		fflush(stdout);
		read(out_pipe[0], buff2, BUFF_SIZE);

		//AFF
		dup2(saved_stdout, STDOUT_FILENO);

		test = TRUE;
		if (memcmp(buff1, buff2, BUFF_SIZE) != 0)
		{
			ret = FALSE;
			test = FALSE;
		}
		if (debug)
		{
			printf("->%s\n", files[pos]);
			printf("[%s]\n", test ? OK : KO);

			printf("\x1B[1;37mCat:\033[0m\n");
			//CAT CMD//
			father = fork();
			if (father > 0)
				wait(0);
			else if (father == 0)
			{
				if (execvp(cmd, args) == -1)
					puts("Exec format error.\n");
				exit(0);
			}
			//FT_CAT CMD//
			printf("\n\x1B[1;37mft_cat:\033[0m\n");
			fd = open(files[pos], O_RDONLY);
				ft_cat(fd); //FT_CAT CMD//
			close(fd);
		}
	}
	return (ret);
}

t_bool	test_cat_fd_0(t_bool debug)
{
	t_bool	ret = TRUE;
	t_bool	test = TRUE;
	pid_t	father;

	//TEST FD 0//
	//CAT CMD//
	printf("\n\x1B[1;37mcat:\033[0m\n");

	char cmd[] = "cat";
	char *args[] = {"cat", NULL};

	father = fork();
	if (father > 0)
		wait(0);
	else if (father == 0)
	{
		if (execvp(cmd, args) == -1)
			puts("Exec format error.\n");
		exit(0);
	}

	//FT_CAT CMD//
	printf("\n\x1B[1;37mft_cat:\033[0m\n");
	ft_cat(0); //FT_CAT CMD//
	return (ret);
}
