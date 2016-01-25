/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 21:28:38 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/25 14:46:40 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printf.h"
#include "libft.h"

int			ft_get_width(char *format)
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
	while (!ft_isdigit(*fmt) && *fmt)
	{
		fmt++;
		if (*fmt == F_ZERO)
			fmt++;
		if (*fmt == '.')
			return (ret);
	}
	while (ft_isdigit(*fmt) && *fmt)
		tmp[i++] = *(fmt++);
	if (i > 0)
		ret = ft_atoi(tmp);
	free(tmp);
	return (ret);
}

char		*ft_get_spaces(t_width width)
{
	char	*spaces;
	int		i;

	spaces = ft_strnew(width);
	i = 0;
	if (!spaces)
		return (NULL);
	while (i < width)
	{
		spaces[i] = ' ';
		i++;
	}
	return (spaces);
}

char		*ft_apply_width(t_options *options, char *arg)
{
	size_t	len;
	char	*ret;
	char	*spaces;

	len = (options->type == T_CHAR) ? 1 : ft_strlen(arg);
	ret = NULL;
	spaces = NULL;
	if (options->width > (int)len)
	{
		if (options->flags->sharp && options->flags->minus &&
		(options->specifier == UNS_OCTAL || options->specifier == UNS_LONG_OCTAL))
			--options->width;
		spaces = ft_get_spaces(options->width - len);
		if (options->flags->minus ||
			(options->type == T_VOID_PTR && options->flags->zero))
			ret = ft_strjoin(arg, spaces);
		else
			ret = ft_strjoin(spaces, arg);
		if (!ret)
			return (NULL);
	}
	else
		return (arg);
	return (ret);
}

wchar_t		*ft_get_spaces_wstr(t_width width)
{
	wchar_t	*spaces;
	int		i;

	spaces = ft_memalloc(sizeof(wchar_t) * width + 1);
	i = 0;
	if (!spaces)
		return (NULL);
	while (i < width)
	{
		spaces[i] = ' ';
		i++;
	}
	spaces[i] = '\0';
	return (spaces);
}

wchar_t		*ft_apply_width_wstr(t_options *options, wchar_t *arg)
{
	t_width	width;
	int		len;
	wchar_t	*ret;
	wchar_t	*spaces;

	width = options->width;
	len = ft_wstrlen(arg);
	ret = NULL;
	spaces = NULL;
	if (width > (int)len)
	{
		spaces = ft_get_spaces_wstr(width - len);
		if (options->flags->minus ||
			(options->type == T_VOID_PTR && options->flags->zero))
			ret = ft_wstrjoin(arg, spaces);
		else
			ret = ft_wstrjoin(spaces, arg);
		if (!ret)
			return (NULL);
	}
	else
		return (arg);
	return (ret);
}
