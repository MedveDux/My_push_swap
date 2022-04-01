/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:26:14 by cyelena           #+#    #+#             */
/*   Updated: 2022/04/01 18:14:32 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "./push_swap.h"
# include "../get_next_line/get_next_line.h"

void	ft_error(t_stacks *ps);
void	executer(char *line, t_stacks *ps);
void	cmd_parser(t_stacks *ps);
int		ft_lst_is_sorted(t_list *lst);
#endif