/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchi <pchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:52:50 by pchi              #+#    #+#             */
/*   Updated: 2024/03/29 12:31:05 by pchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->nbr = 0;
		free(*lst);
	}
}

void	ft_freestr(char **lst)
{
	char	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		lst++;
		free(tmp);
	}
	*lst = NULL;
}

void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

// Check if stack include duplicate numbers
int	ft_checkdup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (tmp->nbr == a->nbr)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

// Check if stack is sorted
int	ft_checksorted(t_stack *a)
{
	int	n;

	n = a->nbr;
	while (a)
	{
		if (n > a->nbr)
			return (0);
		n = a->nbr;
		a = a->next;
	}
	return (1);
}
