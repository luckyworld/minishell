/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_signed_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:13:17 by gvillat           #+#    #+#             */
/*   Updated: 2017/05/22 16:13:18 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fpf_printf.h"

static intmax_t		fpf_signed_cast(PF *argument, va_list ap)
{
	intmax_t	n;

	n = va_arg(ap, intmax_t);
	if (argument->flags[12] == 1)
		n = (size_t)n;
	else if (argument->flags[11] == 1)
		return (n);
	else if (argument->flags[9] == 1)
		n = (long long)n;
	else if (argument->flags[10] == 1)
		n = (long)n;
	else if (argument->flags[8] == 1)
		n = (short)n;
	else if (argument->flags[7] == 1)
		n = (char)n;
	else
		n = (int)n;
	return (n);
}

static char			*fpf_test_string(PF *args)
{
	int			octal;

	if (!args->arg)
		return (NULL);
	octal = 0;
	if (args->spec == 'o' || args->spec == 'O')
		octal = 1;
	if (ft_strcmp((const char *)args->arg, "0") == 0 && args->flags[0] == 0)
	{
		if (!octal || (octal && !args->flags[2]))
		{
			args->arg = "\0";
			return (args->arg);
		}
	}
	return (args->arg);
}

int					fpf_signed_handler(PF *argument, va_list ap)
{
	intmax_t	n;

	n = 0;
	if (argument->spec == 'd' || argument->spec == 'i')
		n = fpf_signed_cast(argument, ap);
	else
		n = (long int)va_arg(ap, intmax_t);
	argument->arg = ft_itoa_base(n, 10);
	if (n < 0)
	{
		free(argument->arg);
		argument->arg = ft_itoa_base(-n, 10);
		return (fpf_print_number(argument, "-"));
	}
	else if (argument->flags[5])
		return (fpf_print_number(argument, "+"));
	else if (argument->flags[6])
		return (fpf_print_number(argument, " "));
	return (fpf_print_number(argument, ""));
}

static int			fpf_print_number_bis(PF *argument, int padding)
{
	fpf_buff(argument->arg, argument);
	if (argument->flags[4] == 1)
		fpf_nputchar(' ', padding, argument);
	if (ft_strcmp(argument->arg, "0") != 0 && argument->flags[0] != 0)
		free(argument->arg);
	return (0);
}

int					fpf_print_number(PF *argument, char *pre)
{
	ssize_t		len;
	ssize_t		precision;
	ssize_t		padding;

	fpf_test_string(argument);
	len = (ssize_t)ft_strlen(argument->arg);
	precision = 0;
	padding = 0;
	if (argument->flags[0] > len)
		precision = argument->flags[0] - len;
	len += (ssize_t)ft_strlen(pre) + precision;
	if (argument->flags[1] > len)
		padding = argument->flags[1] - len;
	if (argument->flags[4] == 0 && (argument->flags[3] == 0
		|| argument->flags[0] != -1))
		fpf_nputchar(' ', padding, argument);
	fpf_buff(pre, argument);
	if (argument->flags[3] == 1 && argument->flags[4] == 0
		&& argument->flags[0] == -1)
		fpf_nputchar('0', padding, argument);
	fpf_nputchar('0', precision, argument);
	return (fpf_print_number_bis(argument, padding));
}
