/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoura-d <amoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:23:13 by amoura-d          #+#    #+#             */
/*   Updated: 2026/06/25 17:12:57 by amoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

char	*read_and_accumulate(int fd, char *static_buffer);

char	*extract_line(char *static_buffer);

char	*clean_static_buffer(char *static_buffer);