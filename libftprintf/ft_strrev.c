/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 20:10:02 by lshanaha          #+#    #+#             */
/*   Updated: 2019/02/02 21:08:28 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_strrev(char *s)
{
	int		i;
	int		len;
	char	first;

	if (s == NULL)
		return ;
	len = ft_strlen(s) - 1;
	i = 0;
	while (i < len - i)
	{
		first = s[i];
		s[i] = s[len - i];
		s[len - i] = first;
		i++;
	}
}
