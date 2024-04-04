/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:57:47 by nprudenc          #+#    #+#             */
/*   Updated: 2024/04/04 20:30:46 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void take_forks(t_philos *philo)
{
	pthread_mutex_t *first_fork;
	pthread_mutex_t *second_fork;
	
	pthread_mutex_lock(&philo->info->m_principal);
	if (philo->id % 2 != 0)
	{
		first_fork = &philo->fork_lf;
		second_fork = philo->fork_rt;
	}
	else
	{
		first_fork = philo->fork_rt;
		second_fork = &philo->fork_lf;
	}
	pthread_mutex_unlock(&philo->info->m_principal);
	pthread_mutex_lock(first_fork);
	print(philo, "has taken first fork\n");
	pthread_mutex_lock(second_fork);
	print(philo, "has taken second fork\n");
}

void	ph_eat(t_philos *philo)
{
	print(philo, "is eating\n");
	ft_usleep(philo->info->t_to_eat);
	philo->m_counter++;
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->fork_lf);
	print(philo, "has dropped the left fork\n");
	pthread_mutex_unlock(philo->fork_rt);
	print(philo, "has dropped the right fork\n");
}

void	ph_sleep(t_philos *philo)
{
	if (is_dead(philo, 0))
		return ;
	print(philo, "is sleeping\n");	
	ft_usleep(philo->info->t_to_sleep);
}

void	ph_think(t_philos *philo)
{
	if (is_dead(philo, 0))
		return ;
	print(philo, "is thinking\n");
}

void	*life_cycle(void *philos)
{
	t_philos *philo;
	int	i = 10;

	philo = philos;
	// if (philo->id % 2 == 0)
	// 	ft_usleep(philo->info->t_to_eat / 10);
	while (!is_dead(philo, 0))
	{
		take_forks(philo);
		ph_eat(philo);
		ph_sleep(philo);
		ph_think(philo);
	}
	return (NULL);
}