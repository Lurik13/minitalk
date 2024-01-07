/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:31:03 by lribette          #+#    #+#             */
/*   Updated: 2024/01/07 19:01:03 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_char(int argv, char c)
{
	int	i;

	i = 128;
	while (i)
	{
		ft_printf("%d", !!(c & i));
		if (c & i)
			kill(argv, SIGUSR1);
		else
			kill(argv, SIGUSR2);
		usleep(100);
		i >>= 1;
	}
	ft_printf("\n");
}

static void	send_str(int argv, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(argv, str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		ft_printf("It requires two params: the server's PID and a string\n");
	else
	{
		check_pid(argv[1]);
		send_str(check_pid(argv[1]), argv[2]);
	}
}
