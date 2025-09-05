/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:26:10 by jtoumani          #+#    #+#             */
/*   Updated: 2025/06/23 17:23:32 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_arguments(char **arguments)
{
	int	i;

	i = 0;
	if (!arguments)
		return ;
	while (arguments[i])
		free(arguments[i++]);
	free(arguments);
}

void	free_stack(t_stack *a)
{
	t_node	*temp;

	if (!a)
		return ;
	while (a->top)
	{
		temp = a->top;
		a->top = temp->next;
		free(temp);
	}
	free(a);
}

void	exit_error(t_stack *a, t_stack *b, char **arguments)
{
	if (arguments)
		free_arguments(arguments);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
