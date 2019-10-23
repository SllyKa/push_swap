/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:09:49 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 09:08:56 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"
#include "ft_push_swap.h"
#include "avlt.h"

extern int pacntr;  // global
extern int pbcntr;  // global
extern int racntr;  // global
extern int rbcntr;  // global
extern int rracntr;  // global
extern int rrbcntr;  // global

t_stack		*sort(t_stack *st)
{
	t_avlt	*tr;

	if (!(tr = init_ps_avlt()))
	// free_tree
		return (NULL);
	if (ft_ps_sort_stacka(st, tr, 0, 0) < 0)
		ft_printf("lol!\n"); // lol!
	//print_lst(st->op_lst);
	//ft_ps_print_stcks(st);
	/*ft_printf("pa: %d\n", pacntr);
	ft_printf("pb: %d\n", pbcntr);
	ft_printf("ra: %d\n", racntr);
	ft_printf("rb: %d\n", rbcntr);
	ft_printf("rra: %d\n", rracntr);
	ft_printf("rrb: %d\n", rrbcntr);*/
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