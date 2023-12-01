/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:25:29 by mchihab           #+#    #+#             */
/*   Updated: 2023/12/01 17:36:26 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
	static t_list *list = NULL;

	char *next_line;

	if(fd < 0 || BUFFER_SIZE <= 0  || read(fd, &next_line,0) < 0)
		return NULL;
	
	create_lst(&list,fd);

	if(list == NULL)
		return NULL;

	next_line = get_line(list);

	filter_list(&list);
	return (next_line);
}