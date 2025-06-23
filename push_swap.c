/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:26:43 by jtoumani          #+#    #+#             */
/*   Updated: 2025/06/23 12:21:00 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// void	print_stack(t_stack *stack, const char *name)
// {
// 	t_node *current = stack->top;
// 	printf("Stack %s (size: %d):\n", name, stack->size);
// 	while (current)
// 	{
// 		printf("Value: %d\n", current->value);
// 		current = current->next;
// 	}
// 	printf("--------\n");
// }

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a = init_stack();
	b = init_stack();
	if (!a || !b)
		exit_error(a, b, NULL);
	parse_args(argc, argv, a, b);
	if (!is_sorted(a))
		sort(a, b);
	return (free_stack(a), free_stack(b), 0);
}

	// print_stack(a, "A");
	// print_stack(b, "B");