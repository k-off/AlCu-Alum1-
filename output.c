/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   output.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 09:31:12 by pacovali      #+#    #+#                 */
/*   Updated: 2019/03/16 09:33:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void	refresh(int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_putstr("\n");
		i++;
	}
}

void	print_rules(int player, int total, int lines)
{
	ft_putstr("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	ft_putstr("RULES:\n\t-This game is based on matches.\n");
	ft_putstr("\t-This time there are ");
	ft_putnbr(total);
	ft_putstr(" matches in total on ");
	ft_putnbr(lines);
	ft_putstr(" lines.\n\t-Players take turns.\n\t");
	ft_putstr("-The game starts from the last line (printed at the bottom).");
	ft_putstr("\n\t-A player can take from 1 to 3 matches");
	ft_putstr(", but no more than amount remaining on the last line.\n");
	ft_putstr("\t-The player taking the very last match from the map loses.\n");
	ft_putstr("\t-The valid input is digits from 1 to 3.\n\n\n");
	ft_putstr("\t-On this map ");
	if (player == 0)
		ft_putstr("YOU START\n\n\n");
	else
		ft_putstr("CPU START\n\n\n");
}

void	ft_put_spaces(int *map, int i, int ctr_i)
{
	int		max;
	int		ctr;
	int		space_qty;

	max = 0;
	ctr = 0;
	while (ctr < i)
	{
		if (map[ctr] > max)
			max = map[ctr];
		ctr++;
	}
	space_qty = ((max - map[ctr_i]) / 2) * 2 + (max - map[ctr_i]) % 2;
	ctr = 0;
	while (ctr < space_qty)
	{
		ft_putstr(" ");
		ctr++;
	}
}

void	print_map(int *map, int i)
{
	int	ctr_i;
	int	ctr_j;

	ctr_i = 0;
	ft_putstr("QTY \tI Matches\n");
	ft_putstr("--------I----------------------------------------\n");
	while (ctr_i < i)
	{
		ft_putnbr(map[ctr_i]);
		ft_putstr("\tI ");
		ft_put_spaces(map, i, ctr_i);
		ctr_j = 0;
		while (ctr_j < map[ctr_i])
		{
			ctr_j++;
			ft_putstr("| ");
		}
		ft_putstr("\n");
		ctr_i++;
	}
}

void	print_message(int f)
{
	if (f == 0)
		ft_putstr("usage: ./alum1 [map_name]\n");
	else if (f == -1)
		ft_putstr("error: file couldn't be opened\n");
	else if (f == -2)
		ft_putstr("error: wrong number of matches in line\n");
	else if (f == -3)
		ft_putstr("error: too many lines\n");
	else if (f == -4)
		ft_putstr("error: non-digit character found\n");
	else if (f == -5)
		ft_putstr("error: empty lines in map-file\n");
	else if (f == -6)
		ft_putstr("error: no matches in input\n");
	else if (f == 1)
		ft_putstr("YOU WIN!\n\nGAME OVER\n");
	else if (f == 2)
		ft_putstr("CPU WIN!\n\nGAME OVER\n");
	else if (f == 3)
		ft_putstr("\nZero matches on board.\n\n");
}
