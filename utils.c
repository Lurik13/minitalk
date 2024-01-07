/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:44:24 by lribette          #+#    #+#             */
/*   Updated: 2024/01/07 14:54:36 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(char *str)
{
	ft_printf("%s", str);
	exit(1);
}

void	check_pid(char *str)
{
	int	i;
	int	number;
	int	nega;

	i = 0;
	number = 0;
	nega = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			nega *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i] - 48;
		i++;
	}
	if (str[i])
		ft_error("Not an int");
}
