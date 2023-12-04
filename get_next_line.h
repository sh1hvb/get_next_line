/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:23:45 by mchihab           #+#    #+#             */
/*   Updated: 2023/12/03 19:00:25 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#define BUFFER_SIZE ;

typedef struct s_list
{
	const char *str_buf;
	struct s_list *next;
}  t_list ;
char *get_next_line(int fd);
void create_lst(t_list **list ,int fd);
void add_line(t_list **list, char *p);
#endif