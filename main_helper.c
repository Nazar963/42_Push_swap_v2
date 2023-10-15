/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:50:40 by naal-jen          #+#    #+#             */
/*   Updated: 2023/03/03 17:59:55 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_helper(int ac, char **av, t_list **stack_a, t_loco *loco)
{
	if (!ft_check_if_num(ac, av) || !ft_check_duplicates(ac, av))
	{
		ft_putstr_fd("Error\n", 2);
		ft_lstclear(stack_a, &free);
		if (ac > 2)
			free(loco);
		exit(EXIT_FAILURE);
	}
	if (!ft_check_if_sorted(ac, av))
	{
		ft_lstclear(stack_a, &free);
		free(loco);
		exit(EXIT_FAILURE);
	}
}
