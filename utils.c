/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosinga <tosinga@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 15:03:29 by tosinga       #+#    #+#                 */
/*   Updated: 2022/03/08 15:03:30 by tosinga       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_malloc_check(void *s)
{
	if (s == 0)
	{
		ft_printf("Error\n", 1);
		exit(1);
	}
	return (s);
}

char	*ft_strjoin_free_so_long(char const *s1, char const *s2)
{
	char	*str;
	size_t	a;
	size_t	b;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
	{
		free ((char *)s1);
		free ((char *)s2);
		return (NULL);
	}
	a = ft_strlen(s1);
	b = 0;
	ft_memcpy(str, s1, a);
	while (s2[b])
	{
		str[a] = s2[b];
		a++;
		b++;
	}
	str[a] = '\0';
	free((char *)s1);
	free((char *)s2);
	return (str);
}

int	check_ber(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (len == 0 || ft_strncmp(&argv[len - 4], ".ber", 4) != 0)
		print_error("No .ber file!");
	return (0);
}

void	new_window(t_program *program, int width, int height, char *name)
{
	program->window = mlx_new_window(program->mlx, width, height, name);
	program->program_size->width = width;
	program->program_size->height = height;
}

void	print_error(char *message)
{
	ft_printf("Error\n");
	ft_printf("%s\n", message);
	exit (1);
}
