/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:39:50 by mchihab           #+#    #+#             */
/*   Updated: 2023/12/07 14:54:52 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_move_buffer(char *buffer);
char	*ft_reader_line(char *buffer);
char	*ft_strchr(char *str, int c);
int		ft_strlen(char *s);
char	*ft_strjoin(char *buffer, char *src);
char	*ft_join(char *dest, char *s1, char *s2);

#endif
