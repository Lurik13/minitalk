/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:31:03 by lribette          #+#    #+#             */
/*   Updated: 2024/01/07 16:34:30 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_char(int argc, char c)
{
	int	i;

	i = 128;
	while (i)
	{
		if (c & i)
			kill(argc, SIGUSR1);
		else
			kill(argc, SIGUSR2);
		i >>= 1;
	}
}

static void	send_str(int argc, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(argc, str[i]);
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
		send_str(argc, argv[2]);
	}
}
