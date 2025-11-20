/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttecleha <ttecleha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:55:24 by ttecleha          #+#    #+#             */
/*   Updated: 2025/11/20 22:15:04 by ttecleha         ###   ########.fr       */
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

// int main(void)
// {
//     int x = ft_printf("hello %s %c %d %% %u %p %x\n", "nigga", 'r', 432, 2342342423, 29834, 0x3224ab);
//     printf("%d\n", x);
// 	printf("%p\n", &x);
// 	ft_printf("%p\n", &x);
//     return (0);

// }
int main(void)
{
    int ft_ret, printf_ret;
    
    printf("=== Testing ft_printf ===\n\n");
    
    // Test %c - character
    printf("--- Testing %%c ---\n");
    ft_ret = ft_printf("ft_printf: char: %c\n", 'A');
    printf_ret = printf("printf:    char: %c\n", 'A');
    printf("Return values - ft: %d, printf: %d\n\n", ft_ret, printf_ret);
    
    // Test %s - string
    printf("--- Testing %%s ---\n");
    ft_ret = ft_printf("ft_printf: string: %s\n", "Hello World");
    printf_ret = printf("printf:    string: %s\n", "Hello World");
    printf("Return values - ft: %d, printf: %d\n", ft_ret, printf_ret);
    
    ft_ret = ft_printf("ft_printf: NULL string: %s\n", NULL);
    printf_ret = printf("printf:    NULL string: %s\n", (char *)NULL);
    printf("Return values - ft: %d, printf: %d\n\n", ft_ret, printf_ret);
    
    // Test %d and %i - integers
    printf("--- Testing %%d and %%i ---\n");
    ft_ret = ft_printf("ft_printf: int: %d, %i\n", 42, -42);
    printf_ret = printf("printf:    int: %d, %i\n", 42, -42);
    printf("Return values - ft: %d, printf: %d\n", ft_ret, printf_ret);
    
    ft_ret = ft_printf("ft_printf: zero: %d, max: %d, min: %d\n", 0, 2147483647, -2147483648);
    printf_ret = printf("printf:    zero: %d, max: %d, min: %d\n", 0, 2147483647, -2147483648);
    printf("Return values - ft: %d, printf: %d\n\n", ft_ret, printf_ret);
    
    // Test %u - unsigned int
    printf("--- Testing %%u ---\n");
    ft_ret = ft_printf("ft_printf: unsigned: %u\n", 4294967295u);
    printf_ret = printf("printf:    unsigned: %u\n", 4294967295u);
    printf("Return values - ft: %d, printf: %d\n\n", ft_ret, printf_ret);
    
    // Test %x and %X - hexadecimal
    printf("--- Testing %%x and %%X ---\n");
    ft_ret = ft_printf("ft_printf: hex: %x, HEX: %X\n", 255, 255);
    printf_ret = printf("printf:    hex: %x, HEX: %X\n", 255, 255);
    printf("Return values - ft: %d, printf: %d\n", ft_ret, printf_ret);
    
    ft_ret = ft_printf("ft_printf: hex: %x, zero: %x\n", 3289391, 0);
    printf_ret = printf("printf:    hex: %x, zero: %x\n", 3289391, 0);
    printf("Return values - ft: %d, printf: %d\n\n", ft_ret, printf_ret);
    
    // Test %p - pointer
    printf("--- Testing %%p ---\n");
    int var = 42;
    ft_ret = ft_printf("ft_printf: pointer: %p\n", &var);
    printf_ret = printf("printf:    pointer: %p\n", &var);
    printf("Return values - ft: %d, printf: %d\n", ft_ret, printf_ret);
    
    ft_ret = ft_printf("ft_printf: NULL pointer: %p\n", NULL);
    printf_ret = printf("printf:    NULL pointer: %p\n", NULL);
    printf("Return values - ft: %d, printf: %d\n\n", ft_ret, printf_ret);
    
    // Test %% - percent
    printf("--- Testing %%%% ---\n");
    ft_ret = ft_printf("ft_printf: percent: %%\n");
    printf_ret = printf("printf:    percent: %%\n");
    printf("Return values - ft: %d, printf: %d\n\n", ft_ret, printf_ret);
    
    // Test mixed formats
    printf("--- Testing mixed formats ---\n");
    ft_ret = ft_printf("ft_printf: Mix: %s %c %d %% %u %p %x\n", "test", 'Z', -123, 456u, &var, 0xABC);
    printf_ret = printf("printf:    Mix: %s %c %d %% %u %p %x\n", "test", 'Z', -123, 456u, &var, 0xABC);
    printf("Return values - ft: %d, printf: %d\n\n", ft_ret, printf_ret);
    
    // Test edge cases
    printf("--- Testing edge cases ---\n");
    ft_ret = ft_printf("ft_printf: empty format\n");
    printf_ret = printf("printf:    empty format\n");
    printf("Return values - ft: %d, printf: %d\n", ft_ret, printf_ret);
    
    ft_ret = ft_printf("");
    printf_ret = printf("");
    printf("Empty string - Return values - ft: %d, printf: %d\n\n", ft_ret, printf_ret);
    
    return (0);
}