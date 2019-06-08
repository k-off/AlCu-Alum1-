/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alcu.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 09:31:12 by pacovali      #+#    #+#                 */
/*   Updated: 2019/03/16 10:13:21 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ALCU_H
# define __ALCU_H

# include "libft/libft.h"

int		main(int argc, char **argv);
void	print_message(int f);
void	print_map(int *map, int i);
void	ft_put_spaces(int *map, int i, int ctr_i);
void	print_rules(int player, int total, int lines);
void	get_map(int fd);
void	get_from_file(int fd, char *line, int *map, int *i);
void	get_from_stdin(int fd, char *line, int *map, int *i);
void	check_line(int *n, char *line, int *i);
void	play_game(int *map, int i);
void	refresh(int	n);
void	choose(int *player, int *map, int i);
int		check_map(int *map, int *i, int res, int player);
void	get_player_input(int *map, int *i, int player);
void	delay(int sec);
char	*cpu_turn(int *map, int i);
void	decide(int *map, int i, int *res);

#endif
