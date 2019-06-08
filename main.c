/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 09:31:12 by pacovali      #+#    #+#                 */
/*   Updated: 2019/03/16 19:32:37 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int		main(int argc, char **argv)
{
	int		fd;

	if (argc > 2)
		print_message(0);
	else if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
			get_map(fd);
		else
			print_message(-1);
	}
	else
		get_map(0);
	return (0);
}
