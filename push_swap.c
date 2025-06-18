/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:26:43 by jtoumani          #+#    #+#             */
/*   Updated: 2025/06/18 12:38:10 by jtoumani         ###   ########.fr       */
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

	a = init_stack();
	b = init_stack();
	if (!a || !b)
		return (1);
	if (argv[1] == NULL || (argc < 2 || (argc == 2 && argv[1][0] == '\0')))
		exit_error(a, b, NULL);
	parse_args(argc, argv, a, b);
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a, 1);
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
		raddix_sort(a, b);
	return (free_stack(a), free_stack(b), 0);
}
