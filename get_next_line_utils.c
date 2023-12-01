/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:34:57 by mchihab           #+#    #+#             */
/*   Updated: 2023/12/01 17:44:45 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void add_line(t_list **list, char *p)
{
	t_list *new;
	t_list *last;

	last = last_node(*list);
	new = malloc(sizeof(t_list));
	if(!new)
		return NULL;
	if( last == NULL)
		new = *lst;
	else
		last->next = new;

	new->str_buf = p;
	new->next = NULL;
}

void create_lst(t_list **list ,int fd)
{
	char *p;
	int reader;

	while(!check_new_line(*list))
	{
		p = malloc(BUFFER_SIZE + 1);
		if(!p) return NULL;
		reader = read(fd, p, BUFFER_SIZE);
		if(!reader)
		{
			free(p);
			return ;
		}
	}
	p[reader] = '\0';
	add_line(list, p);
}