/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:52:59 by nprudenc          #+#    #+#             */
/*   Updated: 2024/04/02 20:36:17 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philos.h"

long int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(int ms)
{
	long int time;

	time = get_time();
	while (get_time() - time < ms)
		usleep(ms / 10);
}

void	print(t_philos *philo, char *s)
{
	long int	time;
	long int	curr_time;

	pthread_mutex_lock(&philo->info->m_print);
	time = get_time() - philo->info->start;
	if (time >= 0 && time <= INT_MAX && !is_dead(philo, 0))
	{
		curr_time = get_time() - philo->info->start;
		printf("%ld %d %s", curr_time, philo->id, s);
	}
	pthread_mutex_unlock(&philo->info->m_print);
}

int	is_dead(t_philos *philo, int	flag)
{
	static int	dead = 0;

	pthread_mutex_lock(&philo->info->m_dead);
	if (flag != 0)
		dead = flag;
	pthread_mutex_unlock(&philo->info->m_dead);
	return (dead);
}