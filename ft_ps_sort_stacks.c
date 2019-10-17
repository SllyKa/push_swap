/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 10:16:24 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/17 21:20:39 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "ft_push_swap.h"
#include "avlt.h"

int pacntr = 0;  // global
int pbcntr = 0;  // global
int racntr = 0;  // global
int rbcntr = 0;  // global
int rracntr = 0;  // global
int rrbcntr = 0;  // global

void		do_op(t_stack *st, t_avlt *tr, char *cmd)
{
	void	(*op)(t_stack *);
	t_list	*tmp;

	op = srch_avlt(tr, cmd);
	
	!ft_strcmp(cmd, "pa") ? pacntr++ : 0;
	!ft_strcmp(cmd, "pb") ? pbcntr++ : 0;
	!ft_strcmp(cmd, "ra") ? racntr++ : 0;
	!ft_strcmp(cmd, "rb") ? rbcntr++ : 0;
	!ft_strcmp(cmd, "rra") ? rracntr++ : 0;
	!ft_strcmp(cmd, "rrb") ? rrbcntr++ : 0;

	op(st);
	if (st->op_lst && !ft_strcmp(cmd, "ra") && !ft_strcmp(st->op_lst->content, "rra"))
		free_ft_liststckalone(&(st->op_lst));
	else if (st->op_lst && !ft_strcmp(cmd, "rb") && !ft_strcmp(st->op_lst->content, "rrb"))
		free_ft_liststckalone(&(st->op_lst));
	else if (st->op_lst && !ft_strcmp(cmd, "rra") && !ft_strcmp(st->op_lst->content, "ra"))
		free_ft_liststckalone(&(st->op_lst));
	else if (st->op_lst && !ft_strcmp(cmd, "rrb") && !ft_strcmp(st->op_lst->content, "rb"))
		free_ft_liststckalone(&(st->op_lst));
	else
	{
		if (!(tmp = ft_lstnew(NULL, 0)))
			exit(-1);
		if (!(tmp->content = ft_strdup(cmd)))
			exit(-1);
		ft_lstadd(&(st->op_lst), tmp);
	}
	//ft_printf("%s\n", cmd);
}

void		do_gen_ops(t_stack *st, t_avlt *tr)
{
	do_op(st, tr, "ra");
	do_op(st, tr, "sa");
	do_op(st, tr, "rra");
}

void		do_gen_dbl_ops(t_stack *st, t_avlt *tr)
{
	do_op(st, tr, "rr");
	do_op(st, tr, "ss");
	do_op(st, tr, "rrr");
}
