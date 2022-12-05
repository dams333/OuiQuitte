/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:33:41 by dhubleur          #+#    #+#             */
/*   Updated: 2022/12/05 14:02:27 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oui_quitte.h"

void	question(t_list *list)
{
	int	penultime;
	int	last;

	while (list->next->next)
		list = list->next;
	penultime = list->player;
	last = list->next->player;
	putstr("[", 1);
	putnbr(penultime, 1);
	putstr(" -> ", 1);
	putnbr(last, 1);
	putstr("] \"Tu veux un Oui'Quitte ?\"\n", 1);
}

void	descend(t_list *list)
{
	while (list->next)
		list = list->next;
	while (list->prev)
	{
		putstr("[", 1);
		putnbr(list->player, 1);
		putstr(" -> ", 1);
		putnbr(list->prev->player, 1);
		putstr("] \"Un quoi ?\"\n", 1);
		list = list->prev;
	}
}

void	ascend(t_list *list)
{
	while (list->next)
	{
		putstr("[", 1);
		putnbr(list->player, 1);
		putstr(" -> ", 1);
		putnbr(list->next->player, 1);
		putstr("] \"Un Oui'Quitte !\"\n", 1);
		list = list->next;
	}
}

void	answer(t_list *list)
{
	int	penultime;
	int	last;

	while (list->next->next)
		list = list->next;
	penultime = list->player;
	last = list->next->player;
	putstr("[", 1);
	putnbr(last, 1);
	putstr(" -> ", 1);
	putnbr(penultime, 1);
	putstr("] \"Ah ok !\"\n", 1);
}

void	solo(void)
{
	putstr("[0 -> Assemblée] \"Vous voulez un Oui'Quitte ?\"\n", 1);
	putstr("[Assemblée -> 0] \"Non !\"\n", 1);
	exit(0);
}
