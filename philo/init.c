/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:33:29 by nprudenc          #+#    #+#             */
/*   Updated: 2024/03/29 19:40:13 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	init_philos(t_philos *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		philo[i].id = i + 1;
		philo[i].m_counter = 0;
		philo[i].last_meal = 0;
		philo[i].fork_rt = NULL;
		pthread_mutex_init((&philo[i].fork_lf), NULL);
		if (i == data->n_philos -1)
			philo[i].fork_rt = &philo[0].fork_lf;
		else
			philo[i].fork_rt = &philo[i + 1].fork_lf;
		if (pthread_create(&philo[i].th, NULL, &life_cycle, &philo[i]) != 0)
			return (FALSE);
	}
	i = -1;
	while (++i < data->n_philos)
	{
		if (pthread_join(philo[i].th, NULL) != 0)
			return (FALSE);
	}
	return (TRUE);
}

void	init_variables(t_data *data, char **argv)
{
	pthread_mutex_init(&data->m_dead, NULL);
	pthread_mutex_init(&data->m_print, NULL);
	data->n_philos = ft_atoi(argv[1]);
	data->t_to_die = ft_atoi(argv[2]);
	data->t_to_eat = ft_atoi(argv[3]);
	data->t_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->n_of_meals = ft_atoi(argv[5]);
	else
		data->n_of_meals = -1;
	data->philos = malloc(sizeof(t_philos) * data->n_philos);
	if (!init_philos(data->philos, data))
		ft_putstr("Thread error!", 2);
}