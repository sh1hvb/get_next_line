/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:23:45 by mchihab           #+#    #+#             */
/*   Updated: 2023/12/04 19:12:34 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_list
{
     char *str_buf;
    struct s_list *next;
} t_list;
void filter_list(t_list **list);
char *get_next_line(int fd);
int len_of_str(t_list *lst);
void free_all(t_list **list, t_list *node);
void create_lst(t_list **list, int fd);
void add_line(t_list **list, char *p);
int check_new_line(t_list *lst);
char *ft_strdup(const char *s1);
t_list *last_node(t_list *list);

#endif