/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:44:24 by lribette          #+#    #+#             */
/*   Updated: 2024/01/07 18:46:00 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(char *str)
{
	ft_printf("%s", str);
	exit(1);
}

int	check_pid(char *str)
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
	return (number * nega);
}

void	ft_bzero(void *src, size_t n)
{
	char	*dest;

	dest = src;
	while (n)
	{
		*dest++ = 0;
		n--;
	}
}
