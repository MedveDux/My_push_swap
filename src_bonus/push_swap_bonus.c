/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:35:49 by cyelena           #+#    #+#             */
/*   Updated: 2022/04/01 18:10:40 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap_bonus.h"

void	ft_error(t_stacks *ps)
{
	free(ps->array);
	ps->array = NULL;
	ft_lstclear(&ps->a);
	ft_lstclear(&ps->b);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	executer(char *line, t_stacks *ps)
{
	if (!ft_strncmp(line, "sa\n", 4))
		sa(ps, 0);
	else if (!ft_strncmp(line, "sb\n", 4))
		sb(ps, 0);
	else if (!ft_strncmp(line, "ss\n", 4))
		ss(ps, 0);
	else if (!ft_strncmp(line, "ra\n", 4))
		ra(ps, 0);
	else if (!ft_strncmp(line, "rb\n", 4))
		rb(ps, 0);
	else if (!ft_strncmp(line, "rr\n", 4))
		rr(ps, 0);
	else if (!ft_strncmp(line, "rra\n", 5))
		rra(ps, 0);
	else if (!ft_strncmp(line, "rrb\n", 5))
		rrb(ps, 0);
	else if (!ft_strncmp(line, "rrr\n", 5))
		rrr(ps, 0);
	else if (!ft_strncmp(line, "pa\n", 4))
		pa(ps, 0);
	else if (!ft_strncmp(line, "pb\n", 4))
		pb(ps, 0);
	else
		ft_error(ps);
}

void	cmd_parser(t_stacks *ps)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		executer(line, ps);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
}

int	ft_lst_is_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (*(int *)(lst->content) > *(int *)(lst->next->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks	ps;

	if (argc == 1)
		return (0);
	ft_memset(&ps, 0, sizeof(ps));
	ps.size = ft_count(argv);
	ps.array = ft_full_array(ps.size, argv);
	ft_not_repeat(ps.size, ps.array);
	ft_stacks(&ps, ps.array);
	cmd_parser(&ps);
	if (ft_lst_is_sorted(ps.a) && ps.b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free(ps.array);
	ps.array = NULL;
	ft_lstclear(&ps.a);
	ft_lstclear(&ps.b);
	return (0);
}
