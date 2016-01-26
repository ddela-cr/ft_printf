/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 09:26:34 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/26 10:51:26 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "printf.h"
#include "libft.h"

int				ft_get_precision(char *format)
{
	int		i;
	int		ret;
	char	*fmt;
	char	*tmp;

	i = 0;
	ret = -1;
	fmt = format;
	tmp = ft_strnew(ft_strlen(format));
	if (!tmp)
		return (ERR_STRNEW);
	if ((fmt = ft_strchr(fmt, '.')))
	{
		while (++fmt && *fmt && ft_isdigit(*fmt))
			tmp[i++] = *fmt;
		if (i == 0)
			ret = 0;
	}
	if (i > 0)
		ret = ft_atoi(tmp);
	free(tmp);
	return (ret);
}

static char		*ft_prepend_zero(t_precision precision, char *arg)
{
	char	*ret;
	char	*arg_tmp;
	size_t	i;
	size_t	len_zero;
	t_bool	is_negative;

	ret = NULL;
	arg_tmp = arg;
	i = 0;
	len_zero = (size_t)precision - ft_strlen(arg);
	is_negative = arg_tmp[0] == '-' ? TRUE : FALSE;
	ret = ft_strnew(is_negative + precision);
	if (is_negative)
	{
		ret[i++] = '-';
		len_zero += 2;
		arg_tmp++;
	}
	while (i < len_zero)
		ret[i++] = '0';
	while (*arg_tmp)
		ret[i++] = *(arg_tmp++);
	return (ret);
}

char			*ft_apply_precision(t_options *options, char *arg)
{
	char	*ret;
	size_t	len;

	ret = ft_strdup(arg);
	len = (arg[0] == '-') ? ft_strlen(arg) - 1 : ft_strlen(arg);
	if ((int)len < options->precision)
		ret = ft_prepend_zero(options->precision, arg);
	else if (options->precision == 0 && ft_atoi(arg) == 0)
		ret = ft_strdup("");
	free(arg);
	return (ret);
}

static wchar_t		*ft_get_zero_wstr(int len)
{
	wchar_t	*ret;

	ret = ft_memalloc(len * sizeof(wchar_t) + 1);
	if (!ret)
		return (NULL);
	while (len)
		ret[--len] = '0';
	return (ret);
}

wchar_t			*ft_apply_precision_wstr(t_options *options, wchar_t *arg)
{
	wchar_t	*ret;

	ret = NULL;
	if (!arg)
		ret = ft_get_zero_wstr(options->precision);
	else
	{
		if (ft_wstrlen(arg) > options->precision)
			ret = ft_wstrsub(arg, 0, options->precision);
		else
			ret = ft_wstrdup(arg);
	}
	return (ret);
}
