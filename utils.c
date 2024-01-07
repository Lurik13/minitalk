/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:44:24 by lribette          #+#    #+#             */
/*   Updated: 2024/01/07 23:20:03 by lribette         ###   ########.fr       */
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		return (i);
	}
	else
		return (1);
}

char	*ft_calloc(int nbelem, int size)
{
	char	*str;
	int		i;

	str = malloc(nbelem * size);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < nbelem * size)
		str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char c)
{
	int	i;
	char	*str;

	i = 0;
	if (!s1)
		str = ft_calloc(2, 1);
	else
		str = ft_calloc(ft_strlen(s1) + 2, 1);
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s1);
	return (str);
}
