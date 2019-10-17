/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 10:16:24 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/16 17:20:09 by gbrandon         ###   ########.fr       */
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

static int		check_sort_b(t_stack *st)
{
	if (st->lenb < 3)
		return (-1);
	if ((st->b)[st->lenb - 1] < (st->b)[st->lenb - 2])
	{
		if ((st->b)[st->lenb - 2] < (st->b)[st->lenb - 3])
		{
			return (2);
		}
		else if ((st->b)[st->lenb - 1] < (st->b)[st->lenb - 3])
		{
			return (3);
		}
		else
		{
			return (1);
		}
	}
	else if (((st->b)[st->lenb - 3] < (st->b)[st->lenb - 1])
			&& (st->b)[st->lenb - 2] < (st->b)[st->lenb - 3])
		return (4);
	else if (((st->b)[st->lenb - 2] < (st->b)[st->lenb - 3])
			&& ((st->b)[st->lenb - 2] > (st->b)[st->lenb - 1]))
		return (5);
	return (0);
}


static void		basic_sort(t_stack *st, t_avlt *tr)
{
	int		sb;

	//ft_ps_print_stcks(st);
	sb = check_sort_b(st);
	//sb = -1;
	if ((st->a)[st->lena - 1] > (st->a)[st->lena - 2])
	{
		if ((st->a)[st->lena - 2] > (st->a)[st->lena - 3])
		{

			if (sb >= 1 && sb <= 3)
				do_op(st, tr, "ss");
			else
				do_op(st, tr, "sa");
			if (sb > 1)
				do_gen_dbl_ops(st, tr);
			else
				do_gen_ops(st, tr);
			do_op(st, tr, "sa");
		}
		else if ((st->a)[st->lena - 1] > (st->a)[st->lena - 3])
		{
			if (sb >= 1 && sb <= 3)
				do_op(st, tr, "ss");
			else
				do_op(st, tr, "sa");
			if (sb > 1)
				do_gen_dbl_ops(st, tr);
			else
				do_gen_ops(st, tr);
		}
		else
		{
			if (sb >= 1 && sb <= 3)
				do_op(st, tr, "ss");
			else
				do_op(st, tr, "sa");
		}
	}
	else if ((st->a)[st->lena - 3] > (st->a)[st->lena - 1] &&
			(st->a)[st->lena - 2] > (st->a)[st->lena - 3])
	{
		if (sb > 1)
			do_gen_dbl_ops(st, tr);
		else
			do_gen_ops(st, tr);
	}
	else if (((st->a)[st->lena - 2] > (st->a)[st->lena - 3])
			&& ((st->a)[st->lena - 2] > (st->a)[st->lena - 1]))
	{
		if (sb > 1)
			do_gen_dbl_ops(st, tr);
		else
			do_gen_ops(st, tr);
		do_op(st, tr, "sa");
	}
	if (sb == 5)
		do_op(st, tr, "sb");
}

int		check_for_three(t_stack *st, t_avlt *tr, int ba)
{
	if ((st->lena - ba) == 3)
	{
		if (!ft_issorted(st->a, st->lena))
			basic_sort(st, tr);
		return (1);
	}
	return (0);
}

int		check_for_two(t_stack *st, t_avlt *tr, int ba)
{
	if ((st->lena - ba) == 2)
	{
		if (!ft_issorted(st->a, st->lena))
		{
			if (st->lenb > 1 && (st->b)[st->lenb - 1] < (st->b)[st->lenb - 2])
				do_op(st, tr, "ss");
			else
				do_op(st, tr, "sa");
		}
		return (1);
	}
	return (0);
}

int			create_check_med_a(t_stack *st, int ba, int *med)
{
	int		er;

	er = 0;
	*med = ft_quicksel_medi(&st->a[ba], st->lena - ba, &er);
	if (er < 0)
		return (-1);
	return (0);
}

int			move_from_a(t_stack *st, t_avlt *tr, int ba)
{
	int		pbcntr;
	int		cntr;
	int		med;
	int 	hlen;
	int		len;

	cntr = 0;
	pbcntr = 0;
	len = st->lena - ba;
	hlen = (st->lena - ba) / 2 + 1;
	if (create_check_med_a(st, ba, &med) < 0)
		return (-1);

	while (len-- > 0 && (pbcntr < hlen))
	{
		if ((st->a)[st->lena - 1] <= med)
		{
			pbcntr++;
			do_op(st, tr, "pb");
		}
		else
		{
			ba > 0 ? cntr++ : 0;
			do_op(st, tr, "ra");
		}
	}
	while (cntr-- > 0)
		do_op(st, tr, "rra");
	return (0);
}

int					ft_ps_sort_stacka(t_stack *st, t_avlt *tr, int ba, int bb)
{
	if (st->lena - ba == 1)
		return (0);
	if (check_for_two(st, tr, ba))
		return (0);
	if (check_for_three(st, tr, ba))
		return (0);
	bb = st->lenb;
	if (move_from_a(st, tr, ba) < 0)
		return (-1);
		
	//ft_printf("----->in\n");
	//ft_ps_print_stcks(st);
	if (ft_ps_sort_stacka(st, tr, ba, bb) < 0)
		return (-1);
	//ft_printf("<-----out\n");
	ba = st->lena;
	if (ft_ps_sort_stackb(st, tr, ba, bb) < 0)
			return (-1);
	//ft_ps_print_stcks(st);
	return (0);
}

int		check_for_three_b(t_stack *st, t_avlt *tr, int bb)
{
	if ((st->lenb - bb) == 3)
	{
		do_op(st, tr, "pa");
		do_op(st, tr, "pa");
		do_op(st, tr, "pa");
		if (!ft_issorted(st->a, st->lena))
			basic_sort(st, tr);
		return (1);
	}
	return (0);
}

int				check_for_two_b(t_stack *st, t_avlt *tr, int bb)
{
	if ((st->lenb - bb) == 2)
	{
		do_op(st, tr, "pa");
		do_op(st, tr, "pa");
		if (!ft_issorted(st->a, st->lena))
		{
			//ft_printf("lenb: %d\n", st->lenb);
			//ft_ps_print_stcks(st);
			//if (st->lenb > 1 && ((st->b)[st->lenb - 1] < (st->b)[st->lenb - 2]))
			//	do_op(st, tr, "ss");
			//else
				do_op(st, tr, "sa");
			//ft_ps_print_stcks(st);
		}
		return (1);
	}
	return (0);
}

static int			create_check_med_b(t_stack *st, int bb, int *med)
{
	int		er;

	er = 0;
	*med = ft_quicksel_medi(&st->b[bb], st->lenb - bb, &er);
	if (er < 0)
		return (-1);
	return (0);
}

int			move_from_b(t_stack *st, t_avlt *tr, int bb)
{
	int		pbcntr;
	int		cntr;
	int		med;
	int 	hlen;
	int		len;

	cntr = 0;
	pbcntr = 0;
	len = st->lenb - bb;
	hlen = (st->lenb - bb) / 2 + 1;
	if (create_check_med_b(st, bb, &med) < 0)
		return (-1);
	while (len-- > 0 && (pbcntr < hlen))
	{
		if ((st->b)[st->lenb - 1] >= med)
		{
			do_op(st, tr, "pa");			
			pbcntr++;
		}
		else
		{
			do_op(st, tr, "rb");
			cntr++;
		}
	}
	while (cntr-- > 0)
		do_op(st, tr, "rrb");
	return (0);
}

int				ft_ps_sort_stackb(t_stack *st, t_avlt *tr, int ba, int bb)
{
	if (st->lenb - bb == 1)
	{
		do_op(st, tr, "pa");
		return (0);
	}
	if (check_for_two_b(st, tr, bb))
		return (0);
	if (check_for_three_b(st, tr, bb))
		return (0);
	//ft_printf("--->bb: %d\n", bb);
	//ft_printf("--->lenb: %d\n", st->lenb);
	ba = st->lena;
	if (move_from_b(st, tr, bb) < 0)
		return (-1);

	//ft_printf("----->in_b\n");
	if (ft_ps_sort_stacka(st, tr, ba, bb) < 0)
		return (-1);
	//ft_ps_print_stcks(st);	
	//ft_printf("<-----out_b\n");
	//bb = st->lenb;
	//ft_printf("----->in_b\n");
	if (ft_ps_sort_stackb(st, tr, ba, bb) < 0)
		return (-1);
	//ft_ps_print_stcks(st);	
	//ft_printf("<-----out_b\n");	
	return (0);
}