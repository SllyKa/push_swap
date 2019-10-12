/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:11:03 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/12 15:15:01 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

int		ft_issorted(int *ar, size_t s)
{
	int i;

	i = 0;
	while (i < s - 1)
	{
		if (ar[i] < ar[i + 1])
			return (0);
		i++;
	}
	return (1);
}