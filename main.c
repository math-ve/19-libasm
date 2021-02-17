/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 12:52:02 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/11/24 11:24:44 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int main(void)
{
	int		fd;
	int		ret;
	char	*buf = malloc(1024);
	char	*dest = malloc(sizeof(char) * 10);

	printf("\n---------------------------------------------");
	printf("\n                 FT_STRLEN               \n");
	printf("---------------------------------------------");

	printf("\n[a]    REAL : (%zu)    MINE : (%zu)\n", strlen("a"), ft_strlen("a"));
	printf("[abcdefgh]    REAL : (%zu)    MINE : (%zu)\n", strlen("abcdefgh"), ft_strlen("abcdefgh"));
	printf("[abcdefghijklmnopqrstuvwxyz]    REAL : (%zu)    MINE : (%zu)\n", strlen("abcdefghijklmnopqrstuvwxyz"), ft_strlen("abcdefghijklmnopqrstuvwxyz"));
	printf("[]    REAL : (%zu)    MINE : (%zu)\n", strlen(""), ft_strlen(""));
	printf("[abc\\0def]    REAL : (%zu)    MINE : (%zu)\n", strlen("abc\0def"), ft_strlen("abc\0def"));

	printf("\n---------------------------------------------");
	printf("\n                 FT_STRCMP               \n");
	printf("---------------------------------------------");

	printf("\n[abc] [abcdef]    REAL : (%d)    MINE : (%d)\n", strcmp("abc", "abcdef"), ft_strcmp("abc", "abcdef"));
	printf("[abc] [abc]    REAL : (%d)    MINE : (%d)\n", strcmp("abc", "abc"), ft_strcmp("abc", "abc"));
	printf("[abcdef] [abc]    REAL : (%d)    MINE : (%d)\n", strcmp("abcdef", "abc"), ft_strcmp("abcdef", "abc"));

	printf("\n---------------------------------------------");
	printf("\n                 FT_STRCPY               \n");
	printf("---------------------------------------------");

	printf("\n[abcdef]    REAL : (%s)    MINE : (%s)\n", strcpy(dest, "abcdef"), ft_strcpy(dest, "abcdef"));
	printf("[]    REAL : (%s)    MINE : (%s)\n", strcpy(dest, ""), ft_strcpy(dest, ""));
	printf("[abc\\0def]    REAL : (%s)    MINE : (%s)\n", strcpy(dest, "abc\0def"), ft_strcpy(dest, "abc\0def"));

	printf("\n---------------------------------------------");
	printf("\n                 FT_STRDUP               \n");
	printf("---------------------------------------------");

	printf("\n[abcdef]    REAL : (%s)    MINE : (%s)\n", strdup("abcdef"), ft_strdup("abcdef"));
	printf("[]    REAL : (%s)    MINE : (%s)\n", strdup(""), ft_strdup(""));
	printf("[abc\\0def]    REAL : (%s)     MINE : (%s)\n", strdup("abc\0def"), ft_strdup("abc\0def"));

	printf("\n---------------------------------------------");
	printf("\n                  FT_WRITE               \n");
	printf("---------------------------------------------\n");

	printf("\n[abcdef]    LEN : %d  ||  REAL : (%zd)    MINE : (%zd)\n", 6, write(1, "abcdef", 6), ft_write(1, "abcdef", 6));
	printf("[abc def]    LEN : %d  ||  REAL : (%zd)     MINE : (%zd)\n", 3, write(1, "abc def", 3), ft_write(1, "abc def", 3));
	printf("[abc def]    LEN : %d  ||  REAL : (%zd)     MINE : (%zd)\n", 0, write(1, "abc def", 0), ft_write(1, "abc def", 0));

	printf("\n---------------------------------------------");
	printf("\n                  FT_READ                \n");
	printf("---------------------------------------------\n");

	fd = open("./ft_strcpy.s", O_RDONLY);
	errno = 0;
	printf("REAL ||  ret : (%zd)     buff : (%s)     errno:: (%d)\n", read(fd, buf, 30), buf, errno);
	close(fd);
	fd = open("./ft_strcpy.s", O_RDONLY);
	errno = 0;
	printf("MINE ||  ret : (%zd)     buff : (%s)     errno:: (%d)\n", ft_read(fd, buf, 30), buf, errno);
	close(fd);

	fd = -1;
	errno = 0;
	printf("REAL ||  ret : (%zd)     buff : (%s)     errno:: (%d)\n", read(fd, buf, 30), buf, errno);
	errno = 0;
	printf("MINE ||  ret : (%zd)     buff : (%s)     errno:: (%d)\n", ft_read(fd, buf, 30), buf, errno);
	close(fd);

	return (0);
}