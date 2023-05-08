/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhrou <amakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:58:15 by amakhrou          #+#    #+#             */
/*   Updated: 2023/05/08 16:13:13 by amakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_bits(int sig)
{
	static int	i;
	static char	c;

	c = c << 1 | sig;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
	}
}

void	sigusr(int sign)
{
	if (sign == SIGUSR1)
		receive_bits(0);
	if (sign == SIGUSR2)
		receive_bits(1);
}

int	main(void)
{
	signal(SIGUSR1, sigusr);
	signal(SIGUSR2, sigusr);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
}
