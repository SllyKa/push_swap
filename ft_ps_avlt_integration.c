/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_avlt_integration.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:52:42 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/18 12:01:45 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ps_checker.h"
#include "avlt.h"
#include "libftprintf.h"

static t_avlt	*add_to_tree(t_avlt *a, t_opfunc *t, char *s,\
void (*o)(t_stack *))
{
	ft_strcpy(t->line, s);
	t->func = o;
	add_node(&a, t, t_char_cmp, t_ins);
	return (a);
}

t_avlt			*init_ps_avlt(void)
{
	t_avlt		*op_tree;
	t_opfunc	*temp;

	if (!(temp = (t_opfunc*)malloc(sizeof(t_opfunc))))
		return (NULL);
	if (!(temp->line = (char*)malloc(sizeof(char) * 3 + 1)))
		return (NULL);
	op_tree = NULL;
	op_tree = add_to_tree(op_tree, temp, "sa", ps_sa);
	op_tree = add_to_tree(op_tree, temp, "sb", ps_sb);
	op_tree = add_to_tree(op_tree, temp, "ss", ps_ss);
	op_tree = add_to_tree(op_tree, temp, "pa", ps_pa);
	op_tree = add_to_tree(op_tree, temp, "pb", ps_pb);
	op_tree = add_to_tree(op_tree, temp, "ra", ps_ra);
	op_tree = add_to_tree(op_tree, temp, "rb", ps_rb);
	op_tree = add_to_tree(op_tree, temp, "rr", ps_rr);
	op_tree = add_to_tree(op_tree, temp, "rra", ps_rra);
	op_tree = add_to_tree(op_tree, temp, "rrb", ps_rrb);
	op_tree = add_to_tree(op_tree, temp, "rrr", ps_rrr);
	free(temp->line);
	free(temp);
	return (op_tree);
}

void			*srch_avlt(t_avlt *rt, char *it)
{
	if (!rt)
		return (NULL);
	else if (ft_strcmp(it, ((t_opfunc*)rt->item)->line) == 0)
		return (((t_opfunc*)rt->item)->func);
	else if (ft_strcmp(it, ((t_opfunc*)rt->item)->line) > 0)
		return (srch_avlt(rt->right, it));
	else if (ft_strcmp(it, ((t_opfunc*)rt->item)->line) < 0)
		return (srch_avlt(rt->left, it));
	return (NULL);
}
