/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:15:12 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/22 18:29:34 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
#include "ft_ps_general.h"

t_stack		*sort(t_stack *st);
int			ft_quicksel_medi(int *arr, size_t s, int *er);
int			ft_ps_sort_stacka(t_stack *st, t_avlt *tr, int ba, int bb);
int			ft_ps_sort_stackb(t_stack *st, t_avlt *tr, int ba, int bb);
int			create_check_med_b(t_stack *st, int bb, int *med);
void		do_op(t_stack *st, t_avlt *tr, char *cmd);
int			check_for_three(t_stack *st, t_avlt *tr, int *ba, int bb);
int			check_for_two(t_stack *st, t_avlt *tr, int *ba, int bb);
int			check_for_one(t_stack *st, int *ba, int bb);
void		do_gen_ops(t_stack *st, t_avlt *tr);
void		do_gen_dbl_ops(t_stack *st, t_avlt *tr);
void		basic_sort(t_stack *st, t_avlt *tr);

#endif