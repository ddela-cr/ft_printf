/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 12:16:24 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/19 10:08:06 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <inttypes.h>
#include "printf.h"
#include "libft.h"

char	*ft_check_char(t_options *options, long long arg)
{
	char	*ret;

	ret = NULL;
	if (options->type == T_CHAR && options->modifier != M_HH)
	{
		if (!arg)
		{
			ft_putstr("");
		}
		else
		{
			ret = ft_strnew(1);
			ret[0] = arg;
		}
	}
	else
		ret = ft_itoa_long_long(arg);
	return (ret);
}

char	*ft_get_signed_args(t_options *options, va_list ap)
{
	long long			arg;
	t_type				type;
	char				*ret;

	arg = 0;
	type = options->type;
	ret = NULL;
	if (type == T_INT)
		arg = va_arg(ap, int);
	if (type == T_LONG)
		arg = va_arg(ap, long);
	if (type == T_LONG_LONG)
		arg = va_arg(ap, long long);
	if (type == T_SHORT)
		arg = va_arg(ap, int);
	if (type == T_CHAR)
		arg = va_arg(ap, int);
	if (type == T_INTMAX_T)
		arg = va_arg(ap, intmax_t);
	ret = ft_check_char(options, arg);
	return (ret);
}

char	*ft_check_o_x(t_options *options, unsigned long long arg)
{
	char	*ret;
	t_specifier	specifier;

	ret = NULL;
	specifier = options->specifier;
	if (specifier == UNS_OCTAL || specifier == UNS_LONG_OCTAL)
		ret = ft_itoa_base((unsigned long long)arg, "01234567");
	else if (specifier == UNS_HEXA)
		ret = ft_itoa_base((unsigned long long)arg, "0123456789abcdef");
	else if (specifier == UNS_HEXA_MAJ)
		ret = ft_itoa_base((unsigned long long)arg, "0123456789ABCDEF");
	else
		ret = ft_itoa_long_long(arg);
	return (ret);
}

char	*ft_get_unsigned_args(t_options *options, va_list ap)
{
	unsigned long long	arg;
	t_type				type;
	char				*ret;

	arg = 0;
	type = options->type;
	ret = NULL;
	if (type == T_UNS_INT)
		arg = va_arg(ap, unsigned int);
	if (type == T_UNS_LONG)
		arg = va_arg(ap, unsigned long);
	if (type == T_UNS_LONG_LONG)
		arg = va_arg(ap, unsigned long long);
	if (type == T_UNS_SHORT)
		arg = va_arg(ap, int);
	if (type == T_UNS_CHAR)
		arg = va_arg(ap, int);
	if (type == T_UINTMAX_T)
		arg = va_arg(ap, uintmax_t);
	if (type == T_SIZE_T)
		arg = va_arg(ap, size_t);
	if (type == T_SSIZE_T)
		arg = va_arg(ap, ssize_t);
	ret = ft_check_o_x(options, arg);
	return (ret);
}
