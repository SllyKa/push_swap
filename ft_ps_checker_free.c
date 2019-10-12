/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_checker_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:34:41 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/12 20:24:02 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ps_checker.h"
#include "avlt.h"
#include "libftprintf.h"

void		free_stack(t_stack **stack)
{
	if (!stack || !(*stack))
		return ;
	if ((*stack)->a)
	{
		free((*stack)->a);
		(*stack)->a = NULL;
		(*stack)->lena = 0;
	}
	if ((*stack)->b)
	{
		free((*stack)->b);
		(*stack)->b = NULL;
		(*stack)->lenb = 0;
	}
	free(*stack);
	*stack = NULL;
}

void		free_avlt(t_avlt *tr)
{
	if (!tr)
		return ;
	
	free_avlt(tr->left);
	free_avlt(tr->right);
	if (tr->item)
	{
		free(((t_opfunc*)tr->item)->line);
		free(tr->item);
	}
	free(tr);
}

void		free_ft_list(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}