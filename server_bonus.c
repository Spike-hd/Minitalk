/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:15:38 by spike             #+#    #+#             */
/*   Updated: 2024/11/26 18:29:05 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 0;
	pid_t		client;
	(void)context;

	client = info->si_pid;
	if (signal == SIGUSR1)
		signal = 1;
	else
		signal = 0;
	c |= signal << (7 - i);
	i++;
	if (i == 8)
	{
		i = 0;
		if (c == '\0')
			kill(client, SIGUSR1);
		else
			ft_printf("%c", c);
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	ft_printf("pid = %d\n", getpid());
	ft_printf("Waiting for signal ...\n");

	while (1)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
		{
			ft_printf("sigaction");
			return (1);
		}
		pause();
	}
}
