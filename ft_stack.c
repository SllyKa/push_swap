/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:32:34 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/10 16:04:08 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		push(int *stk, int *s_len, int num)
{
	stk[*s_len] = num;
	(*s_len)++;
}

int			pop(int *stk, int *s_len)
{
	int res;

	res = stk[*s_len - 1];
	(*s_len)--;
	return (res);
}