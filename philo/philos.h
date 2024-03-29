#ifndef PHILOS_H
# define PHILOS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

# define TRUE 1
# define FALSE 0

typedef struct s_philos {
	int				id;
	pthread_t 		tr;
	pthread_mutex_t *fork_rt;
	pthread_mutex_t fork_lf;
	pthread_t		th;
	int				n;
	int				last_meal;
	int				m_counter;
}				t_philos;

typedef struct s_data {
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_dead;
	int				n_philos;
	int				is_dead;
	int				t_to_eat;
	int				t_to_sleep;
	int				t_to_die;
	int				n_of_meals;
	t_philos		*philos;
}					t_data;


// SRCS

void	init_variables(t_data *data, char **argv);
int		init_philos(t_philos *philo, t_data *data);
void	*life_cycle(void *philos);

// UTILS

void		ft_putstr(char *s, int fd);
int			ft_isnbr(char	*nptr);
int			ft_atoi(const char *nptr);
long int	ft_atol(char *nptr);
int			ft_isdigit(int c);

#endif