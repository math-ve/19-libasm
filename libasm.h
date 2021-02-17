/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 12:52:25 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/11/21 12:52:26 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM
# define LIBASM

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *src);
ssize_t	ft_read(int fd, void *buffer, size_t nbyte);
ssize_t ft_write(int fd, void *buffer, size_t nbyte);

#endif