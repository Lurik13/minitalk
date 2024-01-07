/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:02:30 by lribette          #+#    #+#             */
/*   Updated: 2024/01/07 19:02:21 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("1");
	else if (signal == SIGUSR2)
		ft_printf("0");
}

int main (void)
{
	pid_t	id;

	id = getpid();
	ft_printf("PID: %i\n", id);
	signal(SIGUSR1, &signal_handler);
	signal(SIGUSR2, &signal_handler);
	while (1)
	{
		ft_printf("\n");
		sleep(1);
	}
}
/*
int sigaction(int signum, const struct sigaction *restrict act,
              struct sigaction *restrict oldact);*/