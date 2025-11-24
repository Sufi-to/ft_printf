/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttecleha <ttecleha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:29:11 by ttecleha          #+#    #+#             */
/*   Updated: 2025/11/24 18:40:06 by ttecleha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlenu(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count ++;
	while (n > 0)
	{
		n = n / 10;
		count ++;
	}
	return (count);
}

char	*ft_itoau(unsigned int num)
{
	long	n;
	int		len;
	char	*strnum;
	int		i;

	n = num;
	i = 0;
	len = ft_numlenu(n);
	strnum = malloc(sizeof(char) * (len + 1));
	if (!strnum)
		return (NULL);
	strnum[len] = '\0';
	while (len > i)
	{
		len --;
		strnum[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (strnum);
}

int	ft_putnbru(unsigned int num)
{
	char	*x;
	int		len;
	int		i;

	x = ft_itoau(num);
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
