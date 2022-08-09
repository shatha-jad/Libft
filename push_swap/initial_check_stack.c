/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_check_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjadalla <sjadalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:18:32 by sjadalla          #+#    #+#             */
/*   Updated: 2022/06/20 18:22:10 by sjadalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void initial_check_stack (t_stack *top_a, t_stack *top_b, char **split, char *args)
{
	check_dup(top_a, split, args);
	if (check_sort(top_a) == 0)
		free_error_stack(top_a, split, args, 0);
	if (check_size(top_a) <= 5)
		sort_lessthan_5(&top_a, &top_b, 'a');
}

int	check_sort(t_stack *top_a)
{
	// t_stack	*tmp;

	// tmp = top_a;
	if (top_a == NULL || top_a->next == NULL)
		return (0);
	while (top_a->next != NULL)
	{
		if (top_a->data > top_a->next->data)
				return (1);
		top_a = top_a->next;
	}
	return (0);
}

int	check_size(t_stack *top_a)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = top_a;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	// printf("%d\n", i);
	return (i);
}

void	check_dup(t_stack *str, char **split, char *args)
{
	t_stack	*original;
	t_stack	*nextt;
	// t_stack	*current;

	original = str;
	nextt = NULL;
	// current = NULL;
	if (str == NULL)
		return ;
	else
	{
		while (original)
		{
			// current = original;
			nextt = original -> next;
			while (nextt)
			{
				if (nextt->data == original->data)
					// original->next = nextt->next;
					// current->next = nextt->next;
					{
						free_error_stack(str, split, args, 1);
						// error_msg(1);
					}
				else
					// original = nextt;
					// current = nextt;
				nextt = nextt->next;
			}
			original = original->next;
		}
	}
}
