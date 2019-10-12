/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:09:49 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/12 19:35:40 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"
#include "ft_push_swap.h"
#include "avlt.h"

t_stack		*sort(t_stack *st)
{
	t_avlt	*tr;

	if (!(tr = init_ps_avlt()))
	// free_tree
		return (NULL);
	ft_ps_sort_stacks(st, tr);
	//ft_ps_print_stcks(st);
	return (st);
}

int		main(int argc, char **argv)
{
	t_stack		*st;

	if (!(st = ft_ps_arg_check(argc, argv)))
		write(2, "Error\n", 6);
	else
		sort(st);
	free_stack(&st);
	return (0);
}