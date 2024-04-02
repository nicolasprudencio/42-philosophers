/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:20:42 by nprudenc          #+#    #+#             */
/*   Updated: 2024/04/02 16:34:24 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philos.h"

int	ft_atoi(const char *nptr)
{	
	int	i;
	int	is_neg;
	int	result;

	i = 0;
	is_neg = 0;
	result = 0;
	if (!nptr)
		return (0);
	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			is_neg++;
		i++;
	}
	while (nptr[i] && ft_isdigit(nptr[i]) == 1)
	{
		result = result * 10 + nptr[i] - 48;
		i++;
	}
	if (is_neg == 1)
		return (result * -1);
	return (result);
}
