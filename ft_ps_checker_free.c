/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_checker_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:34:41 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 23:00:44 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ps_general.h"
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
	if ((*stack)->op_lst)
		free_ft_list_from_stck((*stack)->op_lst);
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

void		free_ft_liststckalone(t_list **lst)
{
	t_list	*temp;

	if (!lst | !(*lst))
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	if (temp->content)
		free(temp->content);
	free(temp);
}

void		free_tab(char **tab)
{
	char	**tab_head;

	if (!tab)
		return ;
	tab_head = tab;
	while (*tab_head)
	{
		free(*tab_head);
		tab_head++;
	}
	free(tab);
}
