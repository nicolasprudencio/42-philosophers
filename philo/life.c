/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:57:47 by nprudenc          #+#    #+#             */
/*   Updated: 2024/03/29 19:35:14 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	*life_cycle(void *philos)
{
	t_philos *philo;

	pthread_mutex_lock(&philo->fork_lf);
	philo = philos;
	printf("philo: %d\n", philo->id);
	pthread_mutex_unlock(&philo->fork_lf);
	return (NULL);
}