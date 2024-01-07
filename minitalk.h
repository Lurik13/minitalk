/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:59:35 by lribette          #+#    #+#             */
/*   Updated: 2024/01/07 18:37:19 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "./ft_printf/ft_printf.h"

typedef struct s_char
{
	
}	t_char;

void	ft_error(char *str);
int 	check_pid(char *str);
void	ft_bzero(void *src, size_t n);

#endif