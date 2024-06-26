/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:46:24 by nprudenc          #+#    #+#             */
/*   Updated: 2024/04/11 19:51:33 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	validate_args(char **argv);

int main(int argc, char *argv[])
{
	t_data data;

	if (argc != 5 && argc != 6)
	{
		ft_putstr("Error: wrong number of arguments!\n", 2);
		printf("./philo <num_of_philos> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_to_eat]");
		return (1);
	}
	if (!validate_args(argv))
		return (1);
	init_cycle(&data, argv);
	free(data.philos);
	return (0);
}

int	validate_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (!ft_isnbr(argv[i]) || argv[i][0] == '-' || ft_atoi(argv[i]) == 0)
		{
			ft_putstr("Error: one of the parameters is out of the range!\n", 2);
			printf("The parameters must have a int type");
			return (FALSE);
		}
	}
	if (argv[1] <= 0 || argv[2] <= 0 || argv[3] < 0 || argv[4] < 0)
	{
		ft_putstr("Wrong arguments!", 2);
		return (FALSE);
	}
	if (argv[5] && argv[5] < 0)
	{
		ft_putstr("Invalid number of meals, must to be bigger or equal to zero!", 2);
		return (FALSE);
	}
	return (TRUE);
}
