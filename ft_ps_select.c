/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:31:44 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/16 13:30:21 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_push_swap.h"
#include "libftprintf.h"

static t_stack	*fill_arrs(t_stack *arrs, int *arr, size_t s, int pv)
{
	size_t		i;
	int			cura;
	int			curb;

	i = 0;
	cura = 0;
	curb = 0;
	while (i < s)
	{
		if (arr[i] < pv)
		{
			(arrs->a)[cura] = arr[i];
			cura++;
		}
		else if (arr[i] > pv)
		{
			(arrs->b)[curb] = arr[i];
			curb++;
		}
		i++;
	}
	return (arrs);
}

static t_stack	*split_arr(int *arr, size_t s, int pv)
{
	t_stack		*arrs;
	size_t		i;

	if (!(arrs = (t_stack*)malloc(sizeof(t_stack))))
		exit (-1);
	i = 0;
	arrs->a = NULL;
	arrs->b = NULL;
	arrs->lena = 0;
	arrs->lenb = 0;
	arrs->op_lst = NULL;
	while (i < s)
	{
		if (arr[i] < pv)
			(arrs->lena)++;
		else if (arr[i] > pv)
			(arrs->lenb)++;
		i++;
	}
	if ((arrs->lena) && !(arrs->a = (int*)malloc(sizeof(int) * arrs->lena)))
		exit (-1);
	if ((arrs->lenb) && !(arrs->b = (int*)malloc(sizeof(int) * arrs->lenb)))
		exit (-1);
	return (fill_arrs(arrs, arr, s, pv));
}	

/*
**				arr[0] is a pivot
*/

static int		ft_quicksel(int	*arr, size_t s, int q)
{
	int			med;
	t_stack		*arrs;

	if (s == 1)
		return (arr[0]);
	arrs = split_arr(arr, s, arr[0]);
	if (arrs->lena > q)
	{
		free (arrs->b);
		arrs->b = NULL;
		med = ft_quicksel(arrs->a, arrs->lena, q);
	}
	else if (arrs->lena + 1 > q)
		med = arr[0];
	else
	{
		free(arrs->a);
		arrs->a = NULL;
		med = ft_quicksel(arrs->b, arrs->lenb, q - arrs->lena - 1);
	}
	free_stack(&arrs);
	return (med);
}

int				ft_quicksel_medi(int *arr, size_t s, int *er)
{
	if (!arr || s <= 0)
	{
		*er = -1;
		return (0);
	}
	if (s % 2 == 1)
		return (ft_quicksel(arr, s, s / 2));
	else
		return (0.5 * (ft_quicksel(arr, s, s / 2 - 1) 
		+ ft_quicksel(arr, s, s / 2)));
	return (-1);
}
