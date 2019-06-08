/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 09:31:12 by pacovali      #+#    #+#                 */
/*   Updated: 2019/03/16 09:33:59 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void	get_player_input(int *map, int *i, int player)
{
	char	*str;

	str = 0;
	while (1)
	{
		if (!player)
		{
			ft_putstr("YOU TAKE: ");
			while (!get_next_line(0, &str))
				;
		}
		else
			str = cpu_turn(map, *i);
		if (str && ft_str_is_numeric(str) && ft_strlen(str) == 1)
		{
			if (check_map(map, i, ft_atoi(str), player))
			{
				free(str);
				break ;
			}
		}
		free(str);
	}
}

char	*cpu_turn(int *map, int i)
{
	char	*s;
	int		res;

	decide(map, i, &res);
	s = (char*)malloc(sizeof(char) * 2);
	s[1] = '\0';
	ft_putstr("CPU TAKES: ");
	ft_putnbr(res);
	s[0] = res + '0';
	return (s);
}

void	decide(int *map, int i, int *res)
{
	int		count;
	int		plan_b;

	plan_b = 0;
	count = 0;
	while (count < i - 1)
	{
		if (map[count] == 1 || map[count] == 5 || (map[count] > 5 \
			&& (map[count] - 5) % 4 == 0))
			plan_b = (plan_b + 1) % 2;
		count++;
	}
	if (map[i - 1] == 1)
		*res = 1;
	else
		*res = ((map[i - 1] - 1) % 4 + plan_b) % 4;
	if (*res < 1)
		*res = 1;
}
