/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:25:29 by mchihab           #+#    #+#             */
/*   Updated: 2023/12/04 19:25:32 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

void filter_list(t_list **list)
{
    t_list *last;
    t_list *clean_node;
    int i;
    int j;
    char *buf;
    char *tmp;

    buf = malloc(BUFFER_SIZE + 1);
    clean_node = malloc(sizeof(t_list));
    if (!buf || !clean_node)
    {
        free(buf);
        free(clean_node);
        return;
    }
    last = last_node(*list);
    tmp = (char *)last->str_buf;
    i = 0;
    j = 0;
    while (tmp[i] && tmp[i] != '\n')
        i++;
    while (tmp[i] && tmp[++i])
        buf[j++] = tmp[i];
    buf[j] = '\0';
    if (!buf)
    {
        return;
    }
    clean_node->str_buf = buf;
    clean_node->next = NULL;
    free_all(list, clean_node);
}

static void add_str(t_list *lst, char *str)
{
    int i;
    int j;

    j = 0;
    if (!lst)
        return;
    while (lst)
    {
        i = 0;
        while (lst->str_buf[i])
        {
            if (lst->str_buf[i] == '\n')
            {
                str[j] = '\n';
                str[++j] = '\0';
            }
            str[j++] = lst->str_buf[i++];
        }
        lst = lst->next;
    }
    str[j] = '\0';
}

static char *get_line(t_list *lst)
{
    int len;
    char *str;
    if (!lst)
        return NULL;

    len = len_of_str(lst);
    str = malloc(len + 1);
    if (!str)
        return NULL;
    add_str(lst, str);
    return str;
}

// static void create_lst(t_list **list, int fd)
// {
//     char *p;
//     int reader;

//     while (!check_new_line(*list))
//     {
//         p = malloc(BUFFER_SIZE + 1);
//         if (!p)
//             return;
//         reader = read(fd, p, BUFFER_SIZE);
//         if (reader <= 0)
//         {
//             free(p);
//             return;
//         }
//     }
//     p[reader] = '\0';
//     add_line(list, p);
// }

char *get_next_line(int fd)
{
    static t_list *list = NULL;

    char *next_line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    char buffer[BUFFER_SIZE + 1];
    ssize_t bytesRead = read(fd, buffer, BUFFER_SIZE);

    if (bytesRead < 0 || bytesRead == 0)
        return NULL;


    buffer[bytesRead] = '\0';

    add_line(&list, buffer);

    next_line = get_line(list);

    if (next_line)
        filter_list(&list);

    return next_line;
}
