/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:21:27 by fnichola          #+#    #+#             */
/*   Updated: 2021/09/28 17:11:03 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include "libft.h"

#define TRUE 1
#define FALSE 0

int ft_printf(const char *format, ...);
int ft_print_unum(unsigned long num, char *digits, int truncate);
int ft_print_num(int nbr);

#endif
