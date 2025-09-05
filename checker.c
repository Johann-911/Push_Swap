/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:25:54 by jtoumani          #+#    #+#             */
/*   Updated: 2025/06/30 17:54:17 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

bool	is_valid_nbr(char *str)
{
	long	nbr;
	char	*start;

	start = str;
	if (!str || !*str)
		return (false);
	if (*str == '-' || *str == '+')
		str++;
	if (!*str || !(*str >= '0' && *str <= '9'))
		return (false);
	while (*str)
	{
		if (!(*str <= '9' && *str >= '0'))
			return (false);
		str++;
	}
	nbr = ft_atol(start);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (false);
	return (true);
}

long	ft_atol(const char *str)
{
	size_t	i;
	long	integer;
	int		sign;

	i = 0;
	integer = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		integer = (integer * 10) + (str[i] - '0');
		i++;
	}
	return (sign * integer);
}

bool	is_duplicate(int value, t_stack *a)
{
	t_node	*current;

	current = a->top;
	while (current)
	{
		if (current->value == value)
			return (true);
		current = current->next;
	}
	return (false);
}

void	parse_args(int argc, char **argv, t_stack *a, t_stack *b)
{
	int			i;
	int			j;
	long int	nbr;
	char		**arguments;

	i = 1;
	while (i < argc)
	{
		arguments = ft_split(argv[i], ' ');
		if (!arguments)
			exit_error(a, b, arguments);
		j = 0;
		while (arguments[j])
		{
			nbr = ft_atol(arguments[j]);
			if (!is_valid_nbr(arguments[j]))
				exit_error(a, b, arguments);
			if (is_duplicate((int)nbr, a))
				exit_error(a, b, arguments);
			add_node(a, (int)nbr);
			j++;
		}
		free_arguments(arguments);
		i++;
	}
}
