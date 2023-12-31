/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:18:03 by thibnguy          #+#    #+#             */
/*   Updated: 2023/08/17 16:29:30 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdint.h>

# define BLACK		"\033[1;30m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define CYAN		"\033[1;35m"
# define BLUE		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define GRAY		"\033[1;90m"
# define YELLOW		"\033[1;33m"
# define WHITERED	"\033[1;37;41m"
# define EOC		"\033[0;0m"

typedef struct s_data
{
	int				nb_philo;
	unsigned int	t_die;
	unsigned int	t_eat;
	int				t_sleep;
	int				max_eat;
	int				is_dead;
	int				enough_eaten;
	struct s_philo	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	is_dead_mut;
	pthread_mutex_t	enough_eaten_mut;
	pthread_t		*thread_id;
	long long int	start;
}	t_data;

typedef struct s_philo
{
	pthread_mutex_t	after_food;
	long long int	time_after_food;
	int				times_eaten;
	int				id;
	struct s_data	*data;
}	t_philo;

/* LIBFT */
long int	ft_atoi(char *str);
int			ft_isdigit(char c);
char		*ft_strdup(char *s);
int			ft_strlen(char *s);
char		*ft_strstr(char *str, char *to_find);

/* PARSING */
int			ft_parsing(int argc, char *argv[]);
void		ft_printf(t_data *data, char *msg, long long int arg1, int arg2);

/* GET_TIME */
uint64_t	get_time(void);
int			ft_usleep(suseconds_t time);

/* PHILO_FUNCTIONS */
t_data		*ft_init_philo(int argc, char *argv[]);
void		*ft_thread(void *args);
int			philo_death(t_philo *philo);
void		ft_philo_maker(t_data *data);

/* PHILO UTILS */
void		ft_check_eat_enough(t_data *data, t_philo *philo, int sec_fork, \
	int id);
void		ft_check_death_status(t_data *data, t_philo *philo);
void		ft_end_mutex(t_data *data);

#endif
