/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:53:36 by gueberso          #+#    #+#             */
/*   Updated: 2024/11/21 18:45:46 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <stdio.h>

void	test_for_mandatory_part(void)
{
	// int    i;

    // i = 0;
    // //ft_printf("FT_PRINTF_TESTS :\n\nHello World\n");
    // // ft_printf("\n\nINTERESTING TESTS : %x\n\n", INT_MAX);
    // // ft_printf("There is 10 and 30 : %d %d\n", 10, 30);
    // // ft_printf("char Z : %c\n10 : %d\nchar M : %c\n", 'Z', 10, 'M');
    // // ft_printf("str : %s\n","bonjour");
    // // i = ft_printf("-500 en hexa : %x\n", 0);
    // // ft_printf("ret : %d\n", i);
    // // ft_printf("100 : %u\n", 100);
    // // ft_printf("-100 : %u\n", -100);
    // // i = ft_printf("address : %p\n", (void *)-9223372036854775804);
    // // printf("ret : %d\n", i);
    // // ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
    // // ft_printf(" %c \n", '0');
    // // ft_printf(" NULL %s NULL \n\n\n", (char *)NULL);


    // // printf("Hello World\n");
    // // printf("There is 10 : %d \n", 10);
    // // printf("There is 10 and 30 : %d %d\n", 10, 30);
    // // printf("char Z : %c\n10 : %d\nchar M : %c\n", 'Z', 10, 'M');
    // // printf("str : %s\n","bonjour");
    // // i = printf("-500 en hexa : %x\n", 0);
    // // printf("ret : %d\n", i);
    // // printf("100 : %u\n", 100);
    // // printf("-100 : %u\n", -100);
    // // i = printf("address : %p\n", (void *)-9223372036854775804);
    // // printf("ret : %d\n", i);
    // // printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
    // // printf(" %c \n", '0');
    // // printf(" NULL %s NULL \n", (char *)NULL);

    // // int res = ft_printf("%%");
    // // printf("%d\n", res);
    // // int res2 = printf("%%");
    // // printf("%d\n", res2);
    // // res = printf(0);
    // // printf("%d\n", res);
    // // res2 = printf(0);
    // // printf("%d\n", res2);
    // i = ft_printf(0);
    // // i = printf(0);
    // // printf("%d\n", i);
    // // (void)i;
}

// void	test_for_bonus_part_1(void)
// {
// 	unsigned int	x = INT_MAX;
// 	unsigned int	X = INT_MAX;
// 	unsigned int	vnull = INT_MAX;

//     printf("\ntest_for_bonus_part_1 :\n\n\n");
// 	printf("TESTS WITH NO #      %%x    '%x'\n", x);
// 	printf("TESTS WITH NO #      %%X    '%X'\n", X);
// 	printf("TESTS WITH    #      %%#x   '%#x'\n", x);
// 	printf("TESTS WITH    #      %%#X   '%#X'\n", X);
// 	printf("TESTS FOR MULTIPLE # %%###x '%###x'\n", x);
// 	printf("TESTS FOR MULTIPLE # %%###X '%###X'\n\n\n", X);

// 	printf("TESTS WITH NO #      %%vnull    '%x'\n", vnull);
// 	printf("TESTS WITH    #      %%#vnull   '%#x'\n", vnull);
// 	printf("TESTS FOR MULTIPLE # %%###vnull '%###x'\n\n", vnull);

//     //THIS ONE IS UNDEFINED BEHAVIOR
//     //unsigned int    u = 42;
//     //printf("TESTS WITH    #      %%#u   '%+u'\n", u);
// }

// void	test_for_bonus_part_2(void) // FLAG ' ' (ESPACE) --- FORMAT : d ; i
// {
// 	int	d = 42;
// 	int	D = 24;
// 	//unsigned int	u_int = INT_MAX + 1;
//     printf("\ntest_for_bonus_part_2 :\n\n\n");
// 	printf("                         TESTS WITH no ' ' %%d : '%d'\n", d);
// 	printf("                        TESTS WITH one ' ' %%d : '% d'\n", d);
// 	printf("                   TESTS WITH multiple '    ' %%d : '%    d'\n", d);
//     printf("TESTS WITH multiple (before and after) '    d  '    ' %%d : '%    d  '    ''\n", d);
//     printf("TESTS WITH multiple identifier and flags (before and after) '    d '    ' %%d : '%    d '    '%  d'\n", d, D);
// 	//printf("TESTS WITH no ' ' %%x : '% d'\n", u_int);
// }

// void    test_for_bonus_part_3(void) // FLAG'+' --- FORMAT : d ; i
// {
//     int d = 42;
//     int	D = 24;
//     printf("\n\ntest_for_bonus_part_3 :\n\n\n");
//     printf("                         TESTS WITH no '+' %%d : '%d'\n", d);
// 	printf("                        TESTS WITH one '+' %%d : '%+d'\n", d);
// 	printf("                   TESTS WITH multiple '+++' %%d : '%'+++'d'\n", d);
//     printf("TESTS WITH multiple (before and after) '+++d++'    ' %%d : '%+++d++''\n", d);
//     printf("TESTS WITH multiple identifier and flags (before and after) '+++d++'    ' %%d : '%+++d++'    '%+d'\n", d, D);

// }

// void    test_for_bonus_part_4(void) // FLAG '+ ' (ESPACE) --- format : d ; i
// {
//     int d = 42;
//     int	D = 24;

//     printf("\n\ntest_for_bonus_part_4 :\n\n\n");
//     printf("\nTESTS WITH '+' PRIOR TO ' ' (SPACE)\n\n");
//     printf("                         TESTS WITH no '+ ' %%d : '%d'\n", d);
// 	printf("                        TESTS WITH one '+ ' %%d : '%+ d'\n", d);
// 	printf("                   TESTS WITH multiple '+++   ' %%d : '%'+++ d'\n", d);
//     printf("TESTS WITH multiple (before and after) '+++   d++   '    ' %%d : '%+++d++''\n", d);
//     printf("TESTS WITH multiple identifier and flags (before and after) '+++   d++   '    ' %%d : '%+++d++'    '%+d'\n", d, D);

//     printf("\n\nTESTS WITH ' ' (SPACE) PRIOR TO '+'\n\n");
//     printf("shouldnt print anything since flag ' ' is ignored when flag '+' is present prior\n\n");
//     printf("                         TESTS WITH no ' +' %%d : '%d'\n", d);
// 	printf("                        TESTS WITH one ' +' %%d : '% +d'\n", d);
// 	printf("                   TESTS WITH multiple '+++   ' %%d : '%' +++d'\n", d);
//     printf("TESTS WITH multiple (before and after) '   +++   d++   '    ' %%d : '%   +++d   ++''\n", d);
//     printf("TESTS WITH multiple identifier and flags (before and after) '+++   d++   '    ' %%d : '%+++d++'    '%+d'\n", d, D);
// }


void    temporary_test(void)
{
    int res = 0;

    res = (ft_printf("%+d%#x", 42, 255));
    printf("\n%d", res);
}
int    main()
{
    //test_for_mandatory_part();
    // test_for_bonus_part_1();
    // test_for_bonus_part_2();
    // test_for_bonus_part_3();
    // test_for_bonus_part_4();
    temporary_test();
}


