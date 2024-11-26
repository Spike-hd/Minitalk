/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:22:39 by spike             #+#    #+#             */
/*   Updated: 2024/11/26 10:35:50 by hduflos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Le message a bien ete recu cote client");
}

int	compare_bits(char c, int i)
{
	return ((c >> i) & 1);
}

int	end_of_transmission(int serv_pid)
{
	int	bits;

	bits = 7;
	while (bits >= 0)
	{
		if (kill(serv_pid, SIGUSR2) == -1)
			return (-1);
		usleep(500);
		bits--;
	}
	return (0);
}

int	send_to_server(int serv_pid, char *str)
{
	int	i;
	int	bits;

	i = -1;
	while (str[++i])
	{
		bits = 8;
		while (--bits >= 0)
		{
			if (compare_bits(str[i], bits) == 1)
			{
				if (kill(serv_pid, SIGUSR1) == -1)
					return (-1);
			}
			else
			{
				if (kill(serv_pid, SIGUSR2) == -1)
					return (-1);
			}
			usleep(500);
		}
	}
	if (end_of_transmission(serv_pid) == -1)
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	signal(SIGUSR1, handle_signal);
	if (ac != 3)
	{
		ft_printf("Wrong nb of args");
		return (1);
	}
	if (send_to_server(ft_atoi(av[1]), av[2]) == -1)
	{
		ft_printf("Erreur au niveau du pid");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
