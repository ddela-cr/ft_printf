/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:19:48 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/12 15:59:29 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <stdio.h>
#include <libft.h>

int	main()
{
	int a, b, c;
	a = 0;
	b = 0;
	c = 2;
	ft_putstr("-------FT_PRINTF TESTS---------\n\n");

	ft_printf("abcdef %-23c test % ls ok %d 42 %%");

	ft_putstr("\n\n-------PRINTF TESTS---------\n\n");

	printf("%%o ->\t %o\n", 42);
	printf("%%#o ->\t %#o\n", 42);
	return (0);
}
