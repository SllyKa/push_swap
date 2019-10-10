/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlt_service.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:25:53 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/09 23:43:32 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avlt.h"
#include <unistd.h>
#include <stdio.h> // for printf

void	*t_ins(void *src)
{
	return (src);
}

void	t_del(void *item)
{
	*(int*)item = 0;
	return ;
}

void	appt(void *a)
{
	// printf (!) not to 21 directory
	printf("%i\n", *(int*)(a));
}

int		tr_int_cmp(void *a, void *b)
{
	int		ia;
	int		ib;

	ia = *(int*)a;
	ib = *(int*)b;

	return (ia - ib);
}

t_avlt		*add_ar_to_tree(int *ar, size_t s)
{
	t_avlt	*tr;
	size_t		i;

	i = 1;
	if (!(tr = create_node(&ar[0], t_ins)))
		return (NULL);
	while (i < s)
	{
		add_node(&tr, &ar[i], tr_int_cmp, t_ins);
		i++;
	}
	return (tr);
}