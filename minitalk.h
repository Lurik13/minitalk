/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:59:35 by lribette          #+#    #+#             */
/*   Updated: 2024/01/07 23:29:28 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"

void	ft_error(char *str);
int		check_pid(char *str);
int		ft_strlen(char *str);
char	*ft_calloc(int nbelem, int size);
char	*ft_strjoin(char *s1, char c);

#endif