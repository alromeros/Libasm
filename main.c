/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alromero <alromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 21:49:35 by alromero          #+#    #+#             */
/*   Updated: 2020/02/20 18:26:13 by alromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t	ft_strlen(const char *str);

int		ft_strcmp(const char *s1, const char *s2);

char	*ft_strcpy(char *dst, const char *src);

ssize_t	ft_write(int fd, const void *buf, size_t nbyte);

ssize_t	ft_read(int fd, void *buf, size_t nbyte);

char	*ft_strdup(const char *s1);


int		main(void)
{
	int		i;
	long	r;
	char	buffer[100];
	char	buffer1[100];
	char	buffer2[100];
	char	buffer3[100];
	char	buffer4[100];
	
	r = 0;
	i = 0;
	while (i < 100)
		buffer[i++] = '\0';
	i = 0;
	while (i < 100)
		buffer1[i++] = '\0';
	i = 0;
	while (i < 100)
		buffer2[i++] = '\0';
	i = 0;
	while (i < 100)
		buffer3[i++] = '\0';
	i = 0;
	while (i < 100)
		buffer4[i++] = '\0';
	
	printf("\n***STRLEN***\n");
	printf("Función original: %lu, %lu, %lu, %lu, %lu\n", strlen("hola"), strlen("abcdefghijklmnopqrstuvwxyz"),
	strlen(""), strlen("jamon"), strlen("el lenguaje ensamblador me ha lavado el cerebro"));
	printf("Función en ensamblador: %lu, %lu, %lu, %lu, %lu\n", ft_strlen("hola"), ft_strlen("abcdefghijklmnopqrstuvwxyz"),
	ft_strlen(""), ft_strlen("jamon"), ft_strlen("el lenguaje ensamblador me ha lavado el cerebro"));

	printf("\n***STRCMP***\n");
	printf("Función original: %i, %i, %i, %i, %i\n", strcmp("hola", "hola"), strcmp("", ""),
	strcmp("", "ey"), strcmp("ey", ""), strcmp("el lenguaje ensamblador me ha lavado el cerebro", "el "));
	printf("Función en ensamblador: %i, %i, %i, %i, %i\n", ft_strcmp("hola", "hola"), ft_strcmp("", ""),
	ft_strcmp("", "ey"), ft_strcmp("ey", ""), ft_strcmp("el lenguaje ensamblador me ha lavado el cerebro", "el "));

	printf("\n***STRCPY***\n");
	printf("Función original: %s, %s, %s, %s, %s\n", strcpy(buffer, "hola mundo!"), strcpy(buffer1, ""),
	strcpy(buffer2, "ey"), strcpy(buffer3, "jamon"), strcpy(buffer4, "el lenguaje ensamblador me ha lavado el cerebro"));
	printf("Función en ensamblador: %s, %s, %s, %s, %s\n", ft_strcpy(buffer, "hola mundo!"), ft_strcpy(buffer1, ""),
	ft_strcpy(buffer2, "ey"), ft_strcpy(buffer3, "jamon"), ft_strcpy(buffer4, "el lenguaje ensamblador me ha lavado el cerebro"));

	printf("\n***WRITE***\n");
	write(1, "Función original:\n", 19);
	write(1, "hola\n", 5), write(1, "adios\n", 6), write(1, "prueba\n", 7);	
	write(1, "Función en ensamblador:\n", 25);
	ft_write(1, "hola\n", 5), ft_write(1, "adios\n", 6), ft_write(1, "prueba\n", 7);	
	
	
	char buff[400];
	char buff1[400];
	printf("\n***READ***\n");
	printf("Función original: %zi, %zi\n", read(1, buff, 10), read(1, buff1, 10));
	printf("%s\n", buff);
	printf("%s\n", buff1);
	printf("Función en ensamblador: %zi, %zi\n", read(1, buff, 10), read(1, buff1, 10));
	printf("%s\n", buff);
	printf("%s\n", buff1);

	printf("\n***STRDUP***\n");
	char *prueba;
	prueba = strdup("haciendo e libasm");
	printf("Función original: %s, %s, %s, %s, %s\n", strdup("El lenguaje ensamblador me está lavando el cerebro"), strdup(""), prueba, strdup("ey"), strdup("a"));
	free(prueba);
	prueba = ft_strdup("haciendo e libasm");
	printf("Función en ensamblador: %s, %s, %s, %s, %s\n", ft_strdup("El lenguaje ensamblador me está lavando el cerebro"), ft_strdup(""), prueba, ft_strdup("ey"), ft_strdup("a"));
	free(prueba);

	return (0);
}
