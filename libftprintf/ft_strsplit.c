/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:56:40 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:40:56 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static int		ft_count(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i + count] != c && s[i + count] != '\0')
		count++;
	return (count + 1);
}

static size_t	ft_num_of_c(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			i++;
		if (s[i] == '\0')
			break ;
		j++;
	}
	return (++j);
}

static char		**ft_helper(char const *s, char **new_arr, char c, size_t j)
{
	size_t	k;
	size_t	i;

	k = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != c)
			new_arr[j][k++] = s[i];
		if (s[i] == c || s[i + 1] == '\0')
		{
			new_arr[j++][k] = '\0';
			k = 0;
			while (s[i + 1] == c && s[i] == c)
				i++;
			if (!(new_arr[j] = (char *)malloc(ft_count(&(s[i]), c)))\
			&& s[i + 1] != '\0')
			{
				ft_strdel(new_arr);
				return (NULL);
			}
		}
	}
	new_arr[j] = NULL;
	return (new_arr);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	**new_arr;

	if ((void *)s == 0x0)
		return (NULL);
	i = 0;
	while (s[i] == c)
		i++;
	if (!(new_arr = (char **)malloc(ft_num_of_c(s, c) * sizeof(new_arr))))
		return (NULL);
	if (!(new_arr[0] = (char *)malloc(ft_count(&(s[i]), c) * sizeof(c))))
	{
		free(new_arr);
		return (NULL);
	}
	return (ft_helper(&(s[i]), new_arr, c, 0));
}
