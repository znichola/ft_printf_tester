/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:08:45 by znichola          #+#    #+#             */
/*   Updated: 2022/10/19 12:39:34 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <limits.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	
	int test = 123; 

	// char *format = "int[%d] char[%c] str[%s] hex[%x] ptr[%p] uin[%u] NULL[%s] percent[%%]\n";
	// int _int = 123; int _hex = -123; int _uint = 123;	char _char = 'b'; char *_str = "test";
	// unsigned int _uin = 12345; 
	
	// size_t len = ft_printf(format, _int, _char, _str, _hex, LONG_MIN, _uin, NULL);
	// printf("\nreturn value is : %zu\n\n", len);
	// size_t len2 = printf(format, _int, _char, _str, _hex, LONG_MIN, _uin, NULL);
	// printf("\nreturn value is : %zu\n", len2);
	// 42-00000000001174475240        42
	// 42-00000000001174475240       42
	// 42        -0000000000117447524042
	// 42       -0000000000117447524042
	// [>------------<-85603645>------------<]
	// [>------------< -85603645>------------<]
	
// #define	FRMT "[42%-28.20d42]"
// #define	TST -1174475240
// 	printf("\nmy   return value is : {%d}\n\n", ft_printf(FRMT, TST)-2);
// 	printf("\nreal return value is : {%d}\n\n",    printf(FRMT, TST)-2);
// #define	FRMT "[42%28.20d42]"
// #define	TST -1174475240
// 	printf("\nmy   return value is : {%d}\n\n", ft_printf(FRMT, TST)-2);
// 	printf("\nreal return value is : {%d}\n\n",    printf(FRMT, TST)-2);
// #define	FRMT "[>------------<%10.5d>------------<]"
// #define	TST -85603645
// 	printf("\nmy   return value is : {%d}\n\n", ft_printf(FRMT, TST)-2);
// 	printf("\nreal return value is : {%d}\n\n",    printf(FRMT, TST)-2);

// #define	FRMT "[%-4d]"
// #define	TST -14
// 	printf("\nmy   return value is : {%d}\n\n", ft_printf(FRMT, TST)-2);
// 	printf("\nreal return value is : {%d}\n\n",    printf(FRMT, TST)-2);
	
//
// -0000000123
// -0000000123

#define	FRMT "[%-.3s]"
#define	TST "-assfsfdd"
	printf("\nmy   return value is : {%d}\n\n", ft_printf(FRMT, TST)-2);
	printf("\nreal return value is : {%d}\n\n",    printf(FRMT, TST)-2);
	
	
	// char *format = "test[%d]";
	// size_t len = ft_printf(format, 1234);
	// printf("\nreturn value is : %zu\n\n", len);
	// size_t len2 = printf(format, 1234);
	// printf("\nreturn value is : %zu\n", len2);

	return (0);
}