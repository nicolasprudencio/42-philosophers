/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:57:47 by nprudenc          #+#    #+#             */
/*   Updated: 2024/04/02 21:33:59 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	*monitor(void *philos)
{
	t_philos *philo;

	philo = philos;
	pthread_mutex_lock(&philo->info->m_print);
	printf("montiring");
	pthread_mutex_unlock(&philo->info->m_print);
	return (NULL);
}

void	take_forks(t_philos	*philo)
{
	//possible data racing happening
	pthread_mutex_lock(&philo->fork_lf);
	print(philo, "has taken left fork\n");
	if (philo->info->n_philos == 1)
	{
		ft_usleep(philo->info->t_to_die * 2);
		return ;
	}
	pthread_mutex_lock(philo->fork_rt);
	print(philo, "has taken right fork\n");
}

void	eat(t_philos *philo)
{
	print(philo, "is eating\n");
	pthread_mutex_unlock(&philo->fork_lf);
	print(philo, "has dropped the left fork\n");
	pthread_mutex_unlock(philo->fork_rt);
	print(philo, "has dropped the right fork\n");
	ft_usleep(philo->info->t_to_eat);
}

void	*life_cycle(void *philos)
{
	t_philos *philo;
	// pthread_t	m;

	philo = philos;
	if (philo->id % 2 == 0)
	{
		// printf("entering\n");
		ft_usleep(philo->info->t_to_eat / 10);
		// printf("exiting\n");
	}
	// if (pthread_create(&m, NULL, &monitor, philos) != 0)
	// 	return (NULL);
	// pthread_detach(m);
	while (!is_dead(philo, 0))
	{
		take_forks(philo);
		eat(philo);
	}
	return (NULL);
}