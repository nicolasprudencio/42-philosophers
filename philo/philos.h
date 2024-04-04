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
# define INT_MAX 2147483647

typedef struct s_philos {
	int				id;
	int				n;
	int				last_meal;
	int				m_counter;
	pthread_t		th;
	struct s_data	*info;
	pthread_mutex_t *fork_rt;
	pthread_mutex_t fork_lf;
}				t_philos;

typedef struct s_data {
	pthread_mutex_t m_principal;
	pthread_mutex_t m_stop;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_dead;
	pthread_t		monitor;
	int				n_philos;
	int				is_dead;
	int				t_to_eat;
	int				t_to_sleep;
	int				t_to_die;
	int				n_of_meals;
	long int		start_time;
	t_philos		*philos;
}					t_data;


// SRCS

void	init_variables(t_data *data, char **argv);
int		init_philos(t_philos *philo, t_data *data);
int		init_threads(t_data *data, t_philos *philo);
void	set_forks(t_philos *philo);
void	*life_cycle(void *philos);
void	take_forks(t_philos *philo);
void	ph_eat(t_philos *philo);
void	ph_sleep(t_philos *philo);
void	ph_think(t_philos *philo);
void	*monitoring(void *data_set);

// UTILS

void		ft_putstr(char *s, int fd);
int			ft_isnbr(char	*nptr);
int			ft_atoi(const char *nptr);
long int	ft_atol(char *nptr);
int			ft_isdigit(int c);
long int	get_time(void);
void		ft_usleep(int ms);
int			is_dead(t_philos *philo, int	flag);
void		print(t_philos *philo, char *s);

#endif