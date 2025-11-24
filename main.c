/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttecleha <ttecleha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:34:11 by ttecleha          #+#    #+#             */
/*   Updated: 2025/11/24 18:41:35 by ttecleha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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