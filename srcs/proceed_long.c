/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 22:02:10 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/20 09:12:08 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		ft_proceed_long(t_options *options, char *arg)
{
	int 	ret;
	(void)options;

	ret = 0;
	if (ft_has_flags(options->flags))
		arg = (char *)ft_apply_flags(options, (wchar_t *)arg);
	ret = ft_putstr(arg);
	return (ret);
}

int		ft_proceed_long_long(t_options *options, char *arg)
{
	int 	ret;
	(void)options;

	ret = 0;
	if (ft_has_flags(options->flags))
		arg = (char *)ft_apply_flags(options, (wchar_t *)arg);
	ret = ft_putstr(arg);
	return (ret);
}

int		ft_proceed_intmax_t(t_options *options, char *arg)
{
	int 	ret;
	(void)options;

	ret = 0;
	if (ft_has_flags(options->flags))
		arg = (char *)ft_apply_flags(options, (wchar_t *)arg);
	ret = ft_putstr(arg);
	return (ret);
}

int		ft_proceed_uns_long(t_options *options, char *arg)
{
	int 	ret;
	(void)options;

	ret = 0;
	if (ft_has_flags(options->flags))
		arg = (char *)ft_apply_flags(options, (wchar_t *)arg);
	ret = ft_putstr(arg);
	return (ret);
}

int		ft_proceed_uns_long_long(t_options *options, char *arg)
{
	int 	ret;
	(void)options;

	ret = 0;
	if (ft_has_flags(options->flags))
		arg = (char *)ft_apply_flags(options, (wchar_t *)arg);
	ret = ft_putstr(arg);
	return (ret);
}

int		ft_proceed_uintmax_t(t_options *options, char *arg)
{
	int 	ret;
	(void)options;

	ret = 0;
	if (ft_has_flags(options->flags))
		arg = (char *)ft_apply_flags(options, (wchar_t *)arg);
	ret = ft_putstr(arg);
	return (ret);
}
