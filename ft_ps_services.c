/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_services.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:02:43 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/09 16:13:45 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ps_checker.h"

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
