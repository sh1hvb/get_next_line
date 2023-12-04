/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:34:57 by mchihab           #+#    #+#             */
/*   Updated: 2023/12/04 11:50:58 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
t_list *last_node(t_list *list)
{
	if (list == NULL)
    {
        return NULL;
    }
    while (list->next != NULL)
    {
        list = list->next;
    }
    return list;
}
void add_line(t_list **list, char *p)
{
    t_list *new;
    t_list *last;

    last = last_node(*list);

    new = malloc(sizeof(t_list));
    if (!new)
        return; 
    if (last == NULL)
        *list = new;
    new->str_buf = strdup(p);
    if (!new->str_buf)
    {
        free(new);
        return; 
    }
    new->next = NULL;
    if (last != NULL)
        last->next = new;
}
int check_new_line(t_list *lst)
{
    char *a = lst->str_buf;
    int i = 0;

    while (a[i])
    {
        if (a[i] == '\n')
            return 1;
        i++;
    return 0;
	}
}
void create_lst(t_list **list ,int fd)
{
	char *p;
	int reader;
	char *a = *list;

	while(!check_new_line(*list))
	{
		p = malloc(BUFFER_SIZE + 1);
		if(!p) return ;
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