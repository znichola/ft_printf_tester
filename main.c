/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:08:45 by znichola          #+#    #+#             */
/*   Updated: 2022/10/31 13:53:52 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"
#include <limits.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	
#define	FRMT "[%#.8b]"
#define	TST 2

	printf("\nmy   return value is : {%d}\n\n", ft_printf(FRMT, TST) - 2);
	// printf("\nreal return value is : {%d}\n\n",    printf(FRMT, TST));

#undef TST
#define	TST 123

	printf("\nmy   return value is : {%d}\n\n", ft_printf(FRMT, TST) - 2);

	// char *format = "test[%d]";
	// size_t len = ft_printf(format, 1234);
	// printf("\nreturn value is : %zu\n\n", len);
	// size_t len2 = printf(format, 1234);
	// printf("\nreturn value is : %zu\n", len2);

	return (0);
}