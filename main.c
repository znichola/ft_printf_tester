/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:08:45 by znichola          #+#    #+#             */
/*   Updated: 2022/10/17 19:41:50 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <limits.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	
	int test = 123; 

	char *format = "int[%#8d] char[%c] str[%s] hex[% +#x] ptr[%p] uin[%u] NULL[%s] percent[%%]\n";
	int _int = 123; int _hex = -123; int _uint = 123;	char _char = 'b'; char *_str = "test";
	unsigned int _uin = 12345; 
	// " %p %p ", LONG_MIN, LONG_MAX)
	// printf("test us : <%- .2d>\n", test);
	
	// printf("binary test: %-s\n", ft_itoa_base(56, "01"));
	// size_t len = 1;
	size_t len = ft_printf(format, _int, _char, _str, _hex, LONG_MIN, _uin, NULL);
	printf("\nreturn value is : %zu\n\n", len);
	size_t len2 = printf(format, _int, _char, _str, _hex, LONG_MIN, _uin, NULL);
	printf("\nreturn value is : %zu\n", len2);
	return (0);
}