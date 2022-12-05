/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oui_quitte.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:23:29 by dhubleur          #+#    #+#             */
/*   Updated: 2022/12/05 13:50:15 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUI_QUITTE_H
# define OUI_QUITTE_H

# include <unistd.h>
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				player;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

void	start_game(int players);
void	putstr(char *str, int fd);
void	exit_clean(t_list *list, char *str, int code);
void	putnbr(int n, int fd);
void	question(t_list *list);
void	descend(t_list *list);
void	ascend(t_list *list);
void	answer(t_list *list);

#endif