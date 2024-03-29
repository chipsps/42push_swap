/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchi <pchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:54:01 by pchi              #+#    #+#             */
/*   Updated: 2024/03/29 01:52:12 by pchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi2(const char *nptr)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (*nptr == '\t' || *nptr == '\n' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r' || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (*nptr)
	{
		if (!ft_isdigit(*nptr))
			ft_error();
		res = res * 10 + sign * (*(nptr++) - '0');
	}
	if (res < INT_MIN || res > INT_MAX)
		ft_error();
	return (res);
}

t_stack	*ft_subprocess(char **av)
{
	t_stack	*a;
	char	**temp;
	int		i;
	int		j;

	i = -1;
	a = NULL;
	temp = ft_split(av[1], 32);
	while (temp[++i])
	{
		j = ft_atoi2(temp[i]);
		ft_add_back(&a, ft_stack_new(j));
	}
	ft_freestr(temp);
	free(temp);
	return (a);
}

t_stack	*ft_process(int ac, char **av)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 0;
	a = NULL;
	if (ac < 2)
		ft_error();
	if (ac == 2)
		a = ft_subprocess(av);
	else
	{
		while (++i < ac)
		{
			j = ft_atoi2(av[i]);
			ft_add_back(&a, ft_stack_new(j));
		}
	}
	return (a);
}

int	main(int ac, char **av)
{
	t_stack	*a;

	a = ft_process(ac, av);
	if (!a || ft_checkdup(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_checksorted(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}
