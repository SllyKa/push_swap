/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_services_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:20:57 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/24 16:16:17 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_push_swap.h"
#include "libftprintf.h"
#include "get_next_line.h"
#include <fcntl.h>

char		*read_from_file(char *fname)
{
	int		fd;
	char	*line;

	if ((fd = open(fname, O_RDONLY)) < 0)
	{
		write(2, "of_error\n", 9);
		exit(-1);
	}
	get_next_line(fd, &line);
	close(fd);
	free(fname);
	return (line);
}

void		ft_ps_print_top(int f_sizea, int f_sizeb)
{
	int		i;

	i = 0;
	ft_printf("|");
	while (i++ < f_sizea)
		ft_printf("%c", '-');
	ft_printf("|");
	i = 0;
	while (i++ < f_sizeb)
		ft_printf("%c", '-');
	ft_printf("|\n");
}
