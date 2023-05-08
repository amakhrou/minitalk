/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhrou <amakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:56:35 by amakhrou          #+#    #+#             */
/*   Updated: 2023/05/08 16:13:23 by amakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

# define RED    "\033[1m\033[31m"

int		ft_atoi(char *str);
void	ft_putstr(char *str);
void	ft_error(char *str);
void	ft_putnbr(int nb);

void	receive_bits(int sig);
void	sigusr(int sign);

int		pid_check(char *str);
void	msg_sent(int pid, char *msg);
void	send_bits(char c, int pid);

#endif