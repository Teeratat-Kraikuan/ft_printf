/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:41:32 by tkraikua          #+#    #+#             */
/*   Updated: 2022/02/25 00:41:32 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	manage_arg(char c, va_list arg)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(arg, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (c == 'u')
		return (ft_putusnbr(va_arg(arg, unsigned int)));
	else if (c == 'x')
		return (ft_puthex_lower(va_arg(arg, unsigned int)));
	else if (c == 'X')
		return (ft_puthex_upper(va_arg(arg, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c != '\0')
		return (ft_putchar(c));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	args;

	va_start(args, format);
	ret = 0;
	while (*format)
	{
		if (*format == '%')
			ret += manage_arg(*(++format), args);
		else
			ret += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (ret);
}
