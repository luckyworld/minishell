/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_unsigned_conv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:13:56 by gvillat           #+#    #+#             */
/*   Updated: 2017/05/22 16:13:58 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fpf_printf.h"

static uintmax_t		fpf_unsigned_cast(PF *argument, va_list ap)
{
	uintmax_t			n;

	n = va_arg(ap, uintmax_t);
	if (argument->flags[7] == 1)
		n = (unsigned char)(n);
	else if (argument->flags[8] == 1)
		n = (unsigned short)(n);
	else if (argument->flags[10] == 1)
		n = (unsigned long)(n);
	else if (argument->flags[9] == 1)
		n = (unsigned long long)(n);
	else if (argument->flags[11] == 1)
		n = (uintmax_t)(n);
	else if (argument->flags[12] == 1)
		n = (size_t)(n);
	else
		n = (unsigned int)(n);
	return (n);
}

static int				fpf_unsigned_helper(PF *argument)
{
	ssize_t				len;
	int					nullstr;

	if (!argument->arg)
		return (-1);
	len = (ssize_t)ft_strlen(argument->arg);
	nullstr = (len == 1 && argument->arg[0] == '0') ? 0 : 1;
	if (argument->flags[2] == 1)
	{
		if (argument->spec == 'o' || argument->spec == 'O')
		{
			if (argument->flags[0] <= len && argument->arg[0] != '0')
				argument->flags[0] = len + 1;
		}
		else if (argument->spec == 'x' && nullstr != 0)
			return (fpf_print_number(argument, "0x"));
		else if (argument->spec == 'X' && nullstr != 0)
			return (fpf_print_number(argument, "0X"));
	}
	return (fpf_print_number(argument, ""));
}

int						fpf_unsigned_handler(PF *argument, va_list ap)
{
	uintmax_t			n;

	if (argument->spec == 'x' || argument->spec == 'X'
		|| argument->spec == 'u' || argument->spec == 'o'
		|| argument->spec == 'b')
		n = fpf_unsigned_cast(argument, ap);
	else
		n = (unsigned long int)va_arg(ap, uintmax_t);
	if (argument->spec == 'o' || argument->spec == 'O')
		argument->arg = ft_itoa_base(n, 8);
	else if (argument->spec == 'u' || argument->spec == 'U')
		argument->arg = ft_itoa_base(n, 10);
	else if (argument->spec == 'x')
		argument->arg = ft_strlower(ft_itoa_base(n, 16));
	else if (argument->spec == 'b')
		argument->arg = ft_itoa_base(n, 2);
	else
		argument->arg = ft_itoa_base(n, 16);
	return (fpf_unsigned_helper(argument));
}
