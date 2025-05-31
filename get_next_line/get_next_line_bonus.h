#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h> 
# include <stdio.h>

char	*ft_strjoin_gnl(char *s, char *d);
size_t	ft_strlen_gnl(const char *s);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_find_line(char *ptr);
char	*ft_save_line(char *set);
char	*get_next_line(int fd);
char	*read_stroke(int fd, char *store);

#endif