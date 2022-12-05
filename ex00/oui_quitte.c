/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oui_quitte.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:14:57 by dhubleur          #+#    #+#             */
/*   Updated: 2022/12/05 14:00:40 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oui_quitte.h"

bool	is_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	if (strlen(str) > 10)
		return (false);
	if (atoi(str) < 0)
		return (false);
	return (true);
}

void	putstr(char *str, int fd)
{
	write(fd, str, strlen(str));
}

void	putnbr(int n, int fd)
{
	long int	nbr;
	char		c;

	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		write(fd, "-", 1);
	}
	if (nbr >= 10)
	{
		putnbr(nbr / 10, fd);
	}
	c = nbr % 10 + '0';
	write(fd, &c, 1);
}

void	error(char *str)
{
	putstr(str, 2);
	exit(1);
}

int	main(int ac, char **av)
{
	int	players;

	if (ac != 2)
		error("Error: argument\n");
	if (!is_int(av[1]))
		error("Error: argument\n");
	players = atoi(av[1]);
	if (players < 1)
		error("Error: argument\n");
	if (players == 1)
		solo();
	start_game(players);
}
