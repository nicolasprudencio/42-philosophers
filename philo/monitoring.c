/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:18:22 by nprudenc          #+#    #+#             */
/*   Updated: 2024/04/04 20:38:51 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int		check_death(t_data *data, t_philos *philo)
{
	long int	time;

	pthread_mutex_lock(&data->m_stop);
	time = get_time() - data->start_time;
	if (time - philo->last_meal < data->t_to_die)
	{	
		is_dead(philo, TRUE);
		pthread_mutex_unlock(&data->m_stop);
		return (TRUE);
	}
	pthread_mutex_unlock(&data->m_stop);
	return (FALSE);
}

void	*monitoring(void *data_set)
{
	t_data 		*data;
	t_philos	*philo;
	int			is_dead;
	int			i;

	data = data_set;
	philo = data->philos;
	while(1)
	{
		i = -1;
		while (++i < data->n_philos)
		{
			if (check_death(data, &philo[i]) == TRUE)
				print(&philo[i], "is dead");
		}
		// if (check_meals(data) == TRUE)
		// 	break ;	
	}
	return (NULL);
}