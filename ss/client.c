/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhrou <amakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:57:36 by amakhrou          #+#    #+#             */
/*   Updated: 2023/05/08 16:23:01 by amakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	pid_check(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] > 57 || str[i] < 48)
			return (0);
		i++;
	}
	return (1);
}

void	send_bits(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(200);
		i--;
	}
}

void	msg_sent(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_bits(msg[i], pid);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		ft_error("Arguments must contain server PID & Msg \n");
	if (!pid_check(av[1]))
		ft_error("PID must contain digits only \n");
	pid = ft_atoi(av[1]);
	if (pid < 0)
		exit (0);
	msg_sent(pid, av[2]);
}
