/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:29:56 by tserdet           #+#    #+#             */
/*   Updated: 2023/01/10 12:04:31 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (10)
# endif
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char	*read_join(int fd, char	*stat);
void	*ft_calloc_gnl(size_t elementCount, size_t elementSize );
void	ft_bzero_gnl(void *s, size_t n);
void	*ft_calloc_gnl(size_t elementCount, size_t elementSize );
int		check_slash_n_gnl(char *stat);
int		ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*get_next_line(int fd);
#endif