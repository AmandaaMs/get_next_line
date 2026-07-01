/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoura-d <amoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:23:05 by amoura-d          #+#    #+#             */
/*   Updated: 2026/07/01 08:42:00 by amoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef  BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef  FD_MAX
#  define FD_MAX 1024
# endif

char	*get_next_line(int fd);
char	*read_and_accumulate(int fd, char *static_buffer);
char	*extract_line(char *static_buffer);
char	*update_storage(char *static_buffer);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif