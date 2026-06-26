/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoura-d <amoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:23:05 by amoura-d          #+#    #+#             */
/*   Updated: 2026/06/25 17:18:16 by amoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE_H 10

char	*get_next_line(int fd);

char	*read_and_accumulate(int fd, char *static_buffer);

char	*extract_line(char *static_buffer);

char	*clean_static_buffer(char *static_buffer);


#endif