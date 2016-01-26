/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:19:48 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/26 13:10:46 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <stdio.h>
#include <libft.h>
#include <stdint.h>
#include <limits.h>
#include <locale.h>

int	main()
{
	char	*l = setlocale(LC_ALL, "");

	if (l == NULL)
		printf("Locale not set\n");
	else
		printf("Locale set to %s\n", l);
	ft_printf("{red}test{eoc} %d\n", 42);
	return (0);
}
