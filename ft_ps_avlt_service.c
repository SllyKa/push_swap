/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_avlt_service.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:41:34 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/10 13:24:31 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ps_checker.h"
#include "avlt.h"
#include "libftprintf.h"

void		*t_ins(void *item)
{
	t_opfunc	*it;

	if (!(it = (t_opfunc*)malloc(sizeof(t_opfunc))))
		return (NULL);
	if (!(it->line = strdup(((t_opfunc*)item)->line)))
		return (NULL);
	it->func = ((t_opfunc*)item)->func;
	return (it); 
}

void		t_del(void *item)
{
	free(((t_opfunc*)item)->line);
	free(item);
}

int			t_char_cmp(void *a, void *b)
{
	return (ft_strcmp(((t_opfunc*)a)->line,((t_opfunc*)b)->line));
}