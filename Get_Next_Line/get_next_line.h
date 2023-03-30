/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:56:13 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2022/12/10 10:56:13 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

typedef unsigned long	t_size_t;

void	*ft_calloc(t_size_t nmemb, t_size_t size);
int		ft_strlen(char *str);
char	*ft_memcpy(char *dest, char *src, int n);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_nllen(char *buff);
char	*ft_read(int fd, char *buff);
int		ft_truenl(char *buff);

#endif
