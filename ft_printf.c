/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttecleha <ttecleha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:55:24 by ttecleha          #+#    #+#             */
/*   Updated: 2025/11/20 22:09:06 by ttecleha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int x)
{
	write(1, &x, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		write(1, str, 1);
		str ++;
		count ++;
	}
	return (count);
}

int	ft_whichf(va_list args, const char f)
{
	int	c;

	c = 0;
	if (f == 'c')
		c += ft_putchar(va_arg(args, int));
	else if (f == 'd' || f == 'i')
		c += ft_putnbr(va_arg(args, int));
	else if (f == 's')
		c += ft_putstr(va_arg(args, char *));
	else if (f == 'u')
		c += ft_putnbru(va_arg(args, unsigned int));
	else if (f == 'p')
		c += ft_padd(va_arg(args, uintptr_t));
	else if (f == 'x')
		c += ft_hexa(va_arg(args, ssize_t), 0);
	else if (f == 'X')
		c += ft_hexa(va_arg(args, ssize_t), 1);
	else if (f == '%')
		c += ft_putchar('%');
	return (c);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt ++;
			if (*fmt == '\0')
				break ;
			count += ft_whichf(args, *fmt);
		}
		else
			count += ft_putchar(*fmt);
		fmt ++;
	}
	va_end(args);
	return (count);
}

int main(void)
{
    int x = ft_printf("hello %s %c %d %% %u %p %x\n", "nigga", 'r', 432, 2342342423, 29834, 0x3224ab);
    printf("%d\n", x);
	printf("%p\n", &x);
	ft_printf("%p\n", &x);
    return (0);

}