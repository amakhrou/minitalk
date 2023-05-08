/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhrou <amakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:09:32 by amakhrou          #+#    #+#             */
/*   Updated: 2023/05/08 15:19:38 by amakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	ft_error(char *str)
{
	ft_putstr(RED);
	ft_putstr(str);
	exit(0);
}

void	ft_putnbr(int nb)
{
	unsigned int	i;

	if (nb < 0)
	{
		ft_putchar('-');
		i = -nb;
	}
	else
		i = nb;
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putchar(i % 10 + '0');
	}
	else
		ft_putchar(i + '0');
}

int	ft_atoi(char *str)
{
	int	o;
	int	c;
	int	p;

	o = 1;
	c = 0;
	p = 0;
	while ((*str <= 13 && *str >= 9) || *str == ' ')
		str++;
	if (*str == '-')
		o *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str <= '9' && *str >= '0')
	{
		c = c * 10 + *str - 48;
		str++;
		p++;
	}
	if (p >= 19 && o > 0)
		return (-1);
	if (p >= 19 && o < 0)
		return (0);
	return (c * o);
}
