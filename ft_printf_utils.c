/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 01:21:42 by tkraikua          #+#    #+#             */
/*   Updated: 2022/02/25 01:21:42 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	cnt;

	if (s == NULL)
		return (ft_putstr("(null)"));
	cnt = 0;
	while (s[cnt])
		cnt++;
	write(1, s, cnt);
	return (cnt);
}

int	ft_putnbr(int n)
{
	int	cnt;

	cnt = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		cnt += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		cnt += ft_putnbr(n / 10);
	cnt += ft_putchar(n % 10 + '0');
	return (cnt);
}

int	ft_putusnbr(unsigned int n)
{
	int	cnt;

	cnt = 0;
	if (n > 9)
		cnt += ft_putusnbr(n / 10);
	cnt += ft_putchar(n % 10 + '0');
	return (cnt);
}
