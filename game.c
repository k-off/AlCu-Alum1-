/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 09:31:12 by pacovali      #+#    #+#                 */
/*   Updated: 2019/03/16 09:12:11 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void	play_game(int *map, int i)
{
	int player;

	refresh(60);
	choose(&player, map, i);
	print_map(map, i);
	refresh(10);
	delay(7);
	while (map[0] > 0)
	{
		refresh(60);
		ft_putstr("Current map:\n");
		print_map(map, i);
		ft_putstr("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		refresh(10);
		get_player_input(map, &i, player);
		if (player)
			delay(2);
		player = (player + 1) % 2;
	}
}

void	choose(int *player, int *map, int i)
{
	int		total;
	int		count;
	char	buf[1];

	count = 0;
	total = 0;
	while (count < i)
	{
		total += map[count];
		count++;
	}
	if (read(open("/dev/urandom", O_RDONLY), buf, 1) > 0)
		*player = (int)((unsigned int)buf[0] % 2);
	else
		*player = 0;
	print_rules(*player, total, i);
}

void	delay(int sec)
{
	int		i;
	int		j;
	int		input;

	input = 0;
	i = 5000 * sec;
	j = 70000;
	while (i > 0 && !input)
	{
		j = 70000;
		while (j > 0)
		{
			j--;
		}
		i--;
	}
}

int		check_map(int *map, int *i, int res, int player)
{
	if (res > 0 && res <= 3 && res <= map[*i - 1])
	{
		map[*i - 1] -= res;
		if (map[*i - 1] <= 0)
			(*i)--;
		if (*i == 0 && map[*i] == 0)
		{
			refresh(60);
			print_map(map, *i);
			print_message(3);
			refresh(8);
			if (!player)
				print_message(2);
			else if (player)
				print_message(1);
			exit(0);
		}
		return (1);
	}
	return (0);
}
