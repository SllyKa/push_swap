/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:33:00 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:38:30 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*arr;

	arr = malloc(size);
	if (arr)
		return (ft_memset(arr, 0, size));
	else
		return (0);
}
