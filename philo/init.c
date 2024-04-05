/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:33:29 by nprudenc          #+#    #+#             */
/*   Updated: 2024/04/05 20:49:12 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	set_forks(t_philos *philo)
{
	int i;

	i = -1;
	while (++i < philo->info->n_philos)
	{
		if (i == philo->info->n_philos - 1)
			philo[i].fork_rt = &philo[0].fork_lf;
		else
			philo[i].fork_rt = &philo[i + 1].fork_lf;
	}
}

int	init_threads(t_data *data, t_philos *philo)
{
	int i;

	i = -1;
	while (++i < data->n_philos)
	{
		if (pthread_create(&philo[i].th, NULL, &life_cycle, &philo[i]) != 0)
			return (FALSE);
	}
	if (pthread_create(&data->monitor, NULL, &monitoring, data) != 0)
		return (FALSE);
	return (TRUE);
}

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
		philo[i].info = data;
		pthread_mutex_init(&philo[i].fork_lf, NULL);
	}
	set_forks(philo);
	if (!init_threads(data, philo))
		return (FALSE);
	i = -1;
	pthread_detach(data->monitor);
	while (++i < data->n_philos)
	{
		if (pthread_join(philo[i].th, NULL) != 0)
			return (FALSE);
	}
	// pthread_join(data->monitor, NULL);
	return (TRUE);
}

void	init_variables(t_data *data, char **argv)
{
	pthread_mutex_init(&data->m_dead, NULL);
	pthread_mutex_init(&data->m_print, NULL);
	pthread_mutex_init(&data->m_stop, NULL);
	pthread_mutex_init(&data->m_principal, NULL);
	pthread_mutex_init(&data->m_eat, NULL);
	data->n_philos = ft_atoi(argv[1]);
	data->t_to_die = ft_atoi(argv[2]);
	data->t_to_eat = ft_atoi(argv[3]);
	data->t_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->n_of_meals = ft_atoi(argv[5]);
	else
		data->n_of_meals = -1;
	data->philos = malloc(sizeof(t_philos) * data->n_philos);
	data->start_time = get_time();
	if (!init_philos(data->philos, data))
		ft_putstr("Thread error!", 2);
}
