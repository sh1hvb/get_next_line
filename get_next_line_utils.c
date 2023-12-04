/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:34:57 by mchihab           #+#    #+#             */
/*   Updated: 2023/12/04 16:39:19 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list *last_node(t_list *list)
{
	if (list == NULL)
        return NULL;
    while (list->next != NULL)
        list = list->next;
    return list;
}
int ft_strlen(const char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return i;
}
char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!p)
		return (0);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
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
    else
        last->next = new;

    new->str_buf = ft_strdup(p);
    if (!new->str_buf)
    {
        return;
    }

    new->next = NULL;
}
int check_new_line(t_list *lst)
{
    char *a = (char *)lst->str_buf;
    int i = 0;

    while (a[i])
    {
        if (a[i] == '\n')
            return 1;
        i++;
   
	}
	return 0;
}

int len_of_str(t_list *lst)
{
	int len ;
	int i ;
 	if(!lst)
		return 0;
	len = 0 ;
	while (lst)
	{
		i = 0 ;
		while(lst->str_buf[i])
		{
			if(lst->str_buf[i] == '\n')
				return (len);
			i++;
			len++;
		}
		lst = lst->next;
	}
	return (len);
}
void free_all(t_list **list , t_list *node)
{
	t_list *curr;
	t_list *next;

	curr =  *list;
	while(curr)
	{
		next = curr->next;
		if(curr != node)
		{
			free(curr);
		}
		curr = next ;
	}
	*list = node; 
}