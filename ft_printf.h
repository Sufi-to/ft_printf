/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttecleha <ttecleha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:52:06 by ttecleha          #+#    #+#             */
/*   Updated: 2025/11/20 22:10:14 by ttecleha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *fmt, ...);
char	*ft_itoa(int num);
int		ft_numlen(long n);
int		ft_strlen(char *str);
int		ft_putnbr(int num);
int		ft_putchar(int x);

int		ft_putnbru(unsigned int num);
char	*ft_itoau(unsigned int num);
int		ft_numlenu(unsigned int n);

int		ft_ptrlen(uintptr_t ptr);
void	ft_putptr(uintptr_t ptr);
int		ft_padd(uintptr_t ptr);
int		ft_hexa(unsigned int nbr, int upper_case);

#endif
