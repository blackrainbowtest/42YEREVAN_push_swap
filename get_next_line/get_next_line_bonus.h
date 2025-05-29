/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:00:48 by aramarak          #+#    #+#             */
/*   Updated: 2025/05/30 00:12:37 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/*
* BUFFER_SIZE: size of the buffer to read the file
*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

/*
* fd: file descriptor
* str_buf: buffer to store the read line
* next: pointer to the next node
*/
typedef struct s_gnllist
{
	int					fd;
	char				*str_buf;
	struct s_gnllist	*next;
}				t_gnllist;

/*
* get_next_line_utils.c
*/
size_t	ft_strlen_gnl(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_get_first_line(char *s);
char	*ft_remove_read_line(char *s);

/*
* get_next_line.c
*/
void	ft_delete_node(t_gnllist **p_head, int fd);
t_gnllist	*get_or_create_node(t_gnllist **p_head, int fd);
char	*ft_read_line(t_gnllist **head, t_gnllist *node, ssize_t bytes_read, int fd);
char	*get_next_line(int fd);
ssize_t	read_and_append_data(int fd, t_gnllist *node, char *buffer);

#endif
