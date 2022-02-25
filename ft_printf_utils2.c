/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:20:13 by tkraikua          #+#    #+#             */
/*   Updated: 2022/02/25 12:20:13 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_lower(unsigned int n)
{
	int	cnt;

	cnt = 0;
	if (n > 15)
		cnt += ft_puthex_lower(n / 16);
	cnt += ft_putchar("0123456789abcdef"[n % 16]);
	return (cnt);
}

int	ft_puthex_upper(unsigned int n)
{
	int	cnt;

	cnt = 0;
	if (n > 15)
		cnt += ft_puthex_upper(n / 16);
	cnt += ft_putchar("0123456789ABCDEF"[n % 16]);
	return (cnt);
}

int	ft_puthex_ptr(unsigned long n)
{
	int	cnt;

	cnt = 0;
	if (n > 15)
		cnt += ft_puthex_ptr(n / 16);
	cnt += ft_putchar("0123456789abcdef"[n % 16]);
	return (cnt);
}

int	ft_putptr(void *ptr)
{
	int				cnt;
	unsigned long	n;

	if (ptr == 0)
		return (ft_putstr("(nil)"));
	n = (unsigned long) ptr;
	cnt = 0;
	write(1, "0x", 2);
	cnt += ft_puthex_ptr(n);
	return (cnt + 2);
}
