/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:22:53 by dhubleur          #+#    #+#             */
/*   Updated: 2022/12/05 14:05:24 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oui_quitte.h"

void	exit_clean(t_list *list, char *str, int code)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	if (str)
		putstr(str, 2);
	exit(code);
}

t_list	*create_element(int num)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (!element)
		exit_clean(NULL, "Error: malloc\n", 1);
	element->player = num;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}

void	add_player(t_list **list, int player_count)
{
	t_list	*tmp;

	if (!*list)
	{
		*list = create_element(rand() % player_count);
		(*list)->prev = NULL;
		(*list)->next = create_element(rand() % player_count);
		(*list)->next->prev = *list;
	}
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_element(rand() % player_count);
		tmp->next->prev = tmp;
	}
}

void	start_game(int players)
{
	t_list	*list;

	srand(time(NULL));
	list = NULL;
	while (1)
	{
		add_player(&list, players);
		question(list);
		descend(list);
		ascend(list);
		answer(list);
	}
}
