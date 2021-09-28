/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:20:01 by fnichola          #+#    #+#             */
/*   Updated: 2021/09/28 18:08:30 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	print_s(char *s)
{
	int	ret;

	ret = 0;
	if (s)
		ret += write(1, s, ft_strlen(s));
	else
		ret += write(1, "(null)", 6);
	return (ret);
}

int	eval_format(char flag, va_list *ap)
{
	int		ret;

	ret = 0;
	if (flag == 'c')
		ret += print_c(va_arg(*ap, int));
	if (flag == 's')
		ret += print_s(va_arg(*ap, char *));
	if (flag == 'p')
	{
		ret += write(1, "0x", 2);
		ret += ft_print_unum(va_arg(*ap, unsigned long), "0123456789abcdef", 0);
	}
	if (flag == 'x')
		ret += ft_print_unum(va_arg(*ap, unsigned long), "0123456789abcdef", 1);
	if (flag == 'X')
		ret += ft_print_unum(va_arg(*ap, unsigned long), "0123456789ABCDEF", 1);
	if (flag == 'u')
		ret += ft_print_unum(va_arg(*ap, unsigned long), "0123456789", 1);
	if (flag == 'd' || flag == 'i')
		ret += ft_print_num(va_arg(*ap, int));
	if (flag == '%')
		ret += write(1, "%", 1);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	size_t	i;
	va_list	ap;

	ret = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			ret += eval_format(format[++i], &ap);
		else
			ret += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (ret);
}
