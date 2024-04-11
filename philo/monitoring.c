/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:18:22 by nprudenc          #+#    #+#             */
/*   Updated: 2024/04/11 19:52:44 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int		check_death(t_data *data, t_philos *philo)
{
	long int	time;

	pthread_mutex_lock(&data->m_stop);
	time = get_time() - data->start_time;
	if (time - philo->last_meal > data->t_to_die)
	{
		is_dead(philo, TRUE);
		pthread_mutex_unlock(&data->m_stop);
		return (TRUE);
	}
	pthread_mutex_unlock(&data->m_stop);
	return (FALSE);
}

int	check_meals(t_data *data, t_philos *philos)
{
	int	i;
	int	philos_counter;

	pthread_mutex_lock(&data->m_stop);
	i = -1;
	philos_counter = 0;
	while (++i < data->n_philos)
	{
		if (philos[i].m_counter == data->n_of_meals)
			philos_counter++;
		if (philos_counter == data->n_philos)
		{	
			pthread_mutex_unlock(&data->m_stop);
			return (TRUE);
		}
	}
	pthread_mutex_unlock(&data->m_stop);
	return (FALSE);
}

void	*monitoring(void *data_set)
{
	t_data 		*data;
	t_philos	*philo;
	int			i;

	data = data_set;
	philo = data->philos;
	while(1)
	{
		i = -1;
		pthread_mutex_lock(&data->m_principal);
		while (++i < data->n_philos)
		{	
			if (check_death(data, &philo[i]) == TRUE)
			{
				pthread_mutex_lock(&philo[i].info->m_print);
				printf("%li %d died\n", get_time() - philo->info->start_time, philo[i].id);
				pthread_mutex_unlock(&philo[i].info->m_print);
				pthread_mutex_unlock(&data->m_principal);
				return (NULL);
			}
		}
		pthread_mutex_unlock(&data->m_principal);
		if (check_meals(data, philo) == TRUE)
		{
			is_dead(philo, 1);
			return (NULL);
		}
	}
	return (NULL);
}