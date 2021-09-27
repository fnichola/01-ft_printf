/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:55:27 by fnichola          #+#    #+#             */
/*   Updated: 2021/09/27 22:07:20 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void init_base(char **base)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		(*base)[i] = '0' + i;
		i++;
	}
	while (i < 16)
	{
		(*base)[i] = 'a' + i - 10;
		i++;
	}
	(*base)[i] = 0;
}

/**
 * Print a pointer value in HEX to the standard output.
 */

int ft_putptr(void *ptr)
{
	unsigned long	div;
	unsigned long	num;
	int				ret;
	char			*base;

	ret = 0;
	div = 1;
	num = (unsigned long)ptr;
	base = (char *)malloc(sizeof(char) * 17);
	if (!base)
		return (0);
	init_base(&base);
	ret += write(1, "0x", 2);
	while ((num / div) > 15)
		div *= 16;
	if (num == 0)
		ret += write(1, &base[0], 1);
	else 
		while (div >= 1)
		{
			ret += write(1, &base[(num / div)], 1);
			num = num % div;
			div /= 16;
		}
	return (ret);
}
