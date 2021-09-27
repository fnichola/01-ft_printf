/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:20:01 by fnichola          #+#    #+#             */
/*   Updated: 2021/09/27 21:06:42 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int eval_format(char flag, va_list *ap)
{
	char    *s;
	int		ret;

	ret = 0;
	if (flag == 'c')
	{
		ft_putchar_fd(va_arg(*ap, int), 1);
		ret++;
	} 
	else if (flag == 's')
	{
		s = va_arg(*ap, char*);
		if (s)
			ret += write(1, s, ft_strlen(s));
		else
			ret += write(1, "(null)", 6);
	}
	else if (flag == 'p')
		ret += ft_putptr((void *)va_arg(*ap, unsigned long));
	return (ret);
}

int ft_printf(const char *format, ...)
{
	int     ret;
	size_t  i;
	va_list ap;

	ret = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ret += eval_format(format[++i], &ap);
		} else
		{
			ret += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(ap);
	return (ret);
}
