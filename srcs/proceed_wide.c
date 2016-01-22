/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_wide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:07:37 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/22 16:26:54 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printf.h"
#include "libft.h"

wchar_t		*ft_apply_precision_wstr(t_options *options, wchar_t *arg);
wchar_t		*ft_apply_width_wstr(t_options *options, wchar_t *arg);

int			ft_proceed_wchar(t_options *options, wchar_t *arg)
{
	(void)options;
	int		ret;

	ret = ft_putwchar(arg[0]);
	return (ret);
}

int			ft_proceed_wstr(t_options *options, wchar_t *arg)
{
	(void)options;
	int		ret;

	if (options->precision >= 0)
		arg = ft_apply_precision_wstr(options, arg);
	if (options->width > 0)
		arg = ft_apply_width_wstr(options, arg);
	if (ft_has_flags(options->flags))
		arg = ft_apply_flags(options, arg);
	ret = ft_putwstr(arg);
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

wchar_t	*ft_wstrsub(wchar_t *str, unsigned int start, unsigned int len)
{
	size_t			i;
	wchar_t			*new;
	unsigned int	this;

	this = 0;
	new = ft_memalloc(sizeof(wchar_t) * (len + 1));
	if (new)
	{
		i = 0;
		while (this + ft_wcharlen(str[i + start]) <= len)
		{
			new[i] = str[i + start];
			this += ft_wcharlen(new[i]);
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}

wchar_t	*ft_wstrdup(wchar_t const *s1)
{
	int		x;
	wchar_t	*s2;

	x = 0;
	while (s1[x])
		x++;
	s2 = (wchar_t *)ft_memalloc((sizeof(wchar_t) * (x + 1)));
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, sizeof(wchar_t) * x);
	return (s2);
}

wchar_t		*ft_apply_precision_wstr(t_options *options, wchar_t *arg)
{
	wchar_t 	*ret;

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
		if (options->flags->minus 
			|| (options->type == T_VOID_PTR && options->flags->zero))
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
