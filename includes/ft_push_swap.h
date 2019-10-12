/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:15:12 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/12 16:12:55 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
#include "ft_ps_general.h"

t_stack		*sort(t_stack *st);
int			ft_quicksel_medi(t_stack *st, int *er);
int			ft_ps_sort_stacks(t_stack *st, t_avlt *tr);
void		do_op(t_stack *st, t_avlt *tr, char *cmd);
int			check_for_three(t_stack *st, t_avlt *tr);
int			check_for_two(t_stack *st, t_avlt *tr);

#endif