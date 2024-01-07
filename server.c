/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 21:29:51 by lribette          #+#    #+#             */
/*   Updated: 2024/01/07 23:28:30 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*str = NULL;

void	ft_print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	str = NULL;
	//free(str);
}

void	signal_handler(int signal)
{
	static int	i = 0;
	static int	octet = 0;
	int			sig;

	if (signal == SIGUSR1)
		sig = 1;
	else if (signal == SIGUSR2)
		sig = 0;
	if (i < 8)
	{
		octet = octet * 2 + sig;
		i++;
	}
	if (i == 8)
	{
		if (octet == 0)
			ft_print(str);
		str = ft_strjoin(str, octet);
		i = 0;
		octet = 0;
	}
	
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
		sleep(100);
	}
}
