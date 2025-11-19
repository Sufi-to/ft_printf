/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttecleha <ttecleha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:40:22 by ttecleha          #+#    #+#             */
/*   Updated: 2025/11/19 19:06:47 by ttecleha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count ++;
		str ++;
	}
	return (count);
}

int	ft_numlen(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count ++;
	}
	if (n == 0)
		count ++;
	while (n > 0)
	{
		n = n / 10;
		count ++;
	}
	return (count);
}

char	*ft_itoa(int num)
{
	long	n;
	int		len;
	char	*strnum;
	int		i;

	n = num;
	i = 0;
	len = ft_numlen(n);
	strnum = malloc(sizeof(char) * (len + 1));
	if (!strnum)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		strnum [i ++] = '-';
	}
	strnum[len] = '\0';
	while (len > i)
	{
		len --;
		strnum[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (strnum);
}

int	ft_putnbr(int num)
{
	char	*x;
	int		len;
	int		i;

	x = ft_itoa(num);
	len = ft_strlen(x);
	i = 0;
	while (i < len)
	{
		ft_putchar(x[i]);
		i ++;
	}
	free(x);
	return (i);
}
