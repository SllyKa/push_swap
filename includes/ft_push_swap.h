/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:15:12 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/24 14:33:11 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include "ft_ps_general.h"

typedef struct		s_conter
{
	int		cntr;
	int		med;
	int		hlen;
	int		len;
	int		gh_med;
	int		i;
	int		bb;
	int		ba;
}					t_conter;

t_stack				*sort(t_stack *st, t_avlt **tr);
int					ft_quicksel_medi(int *arr, size_t s, int *er);
int					ft_ps_sort_stacka(t_stack *st, t_avlt *tr, int ba, int bb);
int					ft_ps_sort_stackb(t_stack *st, t_avlt *tr, int ba, int bb);
int					create_check_med_b(t_stack *st, int bb, int *med);
int					create_check_med_a(t_stack *st, int ba, int *med);
void				do_op(t_stack *st, t_avlt *tr, char *cmd);
int					check_for_three(t_stack *st, t_avlt *tr, int *ba);
int					check_for_two(t_stack *st, t_avlt *tr, int *ba);
int					check_for_one(t_stack *st, int *ba);
void				do_gen_ops(t_stack *st, t_avlt *tr);
void				do_gen_dbl_ops(t_stack *st, t_avlt *tr);
void				basic_sort(t_stack *st, t_avlt *tr);
void				for_three(t_stack *st, t_avlt *tr);
void				for_five(t_stack *st, t_avlt *tr);
void				for_two(t_stack *st, t_avlt *tr);
int					move_from_b_med(t_stack *st, t_avlt *tr, int ba, int bb);
int					move_from_a(t_stack *st, t_avlt *tr, int ba, int bb);
int					check_for_two_b(t_stack *st, t_avlt *tr, int bb);
int					check_for_three_b(t_stack *st, t_avlt *tr, int bb);
int					find_ghost_med_b(t_stack *st, int bb, int med);
int					find_ghost_med_a(t_stack *st, int ba, int med);
void				bsrt_case1(t_stack *st, t_avlt *tr, int sb);
void				bsrt_case2(t_stack *st, t_avlt *tr, int sb);
void				bsrt_case3(t_stack *st, t_avlt *tr, int sb);
void				bsrt_case4(t_stack *st, t_avlt *tr, int sb);
void				bsrt_case5(t_stack *st, t_avlt *tr, int sb);

#endif
