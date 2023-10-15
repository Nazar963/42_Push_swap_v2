/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:43:15 by naal-jen          #+#    #+#             */
/*   Updated: 2023/03/02 23:26:45 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	helper(char **str, int i, int j)
{
	while (str[i] && str[i][j] != '\0')
	{
		if (str[i][j] == '-')
			j++;
		if (str[i][j] == '\0')
			return (0);
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static int	ft_check_one(char **av)
{
	char	**str;
	int		i;
	int		j;
	int		res;

	i = 0;
	j = 0;
	res = 1;
	str = ft_split(av[1], ' ');
	if (ft_strlen(str[i]) == 0 || (str[i][j] == '-' && str[i][j + 1] == 0))
	{
		ft_free(str);
		return (0);
	}
	res = helper(str, i, j);
	if (res == 0)
	{
		ft_free(str);
		return (0);
	}
	ft_free(str);
	return (1);
}

static int	ft_check_two(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ft_strlen(av[i]) == 0 || (av[i][j] == '-' && av[i][j + 1] == 0))
		return (0);
	while (av[i])
	{
		if (av[i][j] == '-')
			j++;
		if (av[i][j] == '\0')
			return (0);
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_check_if_num(int ac, char **av)
{
	int	res;

	res = 1;
	if (ac == 2)
		res = ft_check_one(av);
	else if (ac > 2)
		res = ft_check_two(av);
	return (res);
}
