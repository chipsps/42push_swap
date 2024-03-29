/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchi <pchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:44:35 by pchi              #+#    #+#             */
/*   Updated: 2024/03/29 12:07:01 by pchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	ft_stack_new(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_error();
	new->nbr = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
		(ft_lstlast(*lst))->next = new;
}
