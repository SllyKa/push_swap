/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 22:55:35 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 19:37:03 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PS_CHECKER_H
# define FT_PS_CHECKER_H
# include "avlt.h"
# include "libftprintf.h"
# include "ft_ps_general.h"

void			free_ft_list(t_list *lst);
int				echk_atoi(int er_code, t_stack *stack);
int				echk_duplicate(t_stack *stack, int size);
int				ft_ps_instruct_check(t_list **lst, t_avlt **tr);
int				ft_ps_exec_ops(t_stack *s, t_list *lst);

#endif
