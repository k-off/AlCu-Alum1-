/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_map.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 09:31:12 by pacovali      #+#    #+#                 */
/*   Updated: 2019/03/16 09:32:24 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void	check_line(int *n, char *line, int *i)
{
	if (ft_str_is_numeric(line))
	{
		*n = ft_atoi(line);
		if (*n < 1 || *n > 10000)
		{
			print_message(-2);
			exit(2);
		}
		(*i)++;
	}
	else
	{
		print_message(-4);
		exit(4);
	}
}

void	get_from_file(int fd, char *line, int *map, int *i)
{
	while (get_next_line(fd, &line) > 0 || line)
	{
		if (*i > 9999)
		{
			print_message(-3);
			exit(3);
		}
		if (line && *line)
		{
			check_line(&map[*i], line, i);
			free(line);
			line = 0;
		}
		if (line && !ft_strlen(line))
		{
			print_message(-5);
			exit(5);
		}
	}
}

void	get_from_stdin(int fd, char *line, int *map, int *i)
{
	while (1)
	{
		ft_putstr("Type number of matches for next line or press enter to");
		ft_putstr(" finish input: ");
		if (*i > 9999)
		{
			print_message(-3);
			exit(3);
		}
		if ((get_next_line(fd, &line) && (line && !ft_strlen(line))) || !line)
		{
			free(line);
			break ;
		}
		else if (line)
		{
			check_line(&map[*i], line, i);
			free(line);
			line = 0;
		}
	}
}

void	get_map(int fd)
{
	char	*line;
	int		map[10002];
	int		i;

	i = 0;
	line = 0;
	if (fd)
		get_from_file(fd, line, map, &i);
	else
		get_from_stdin(0, line, map, &i);
	if (i == 0)
	{
		print_message(-6);
		exit(6);
	}
	else
		play_game(map, i);
}
