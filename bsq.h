#ifndef BSQ_H
# define BSQ_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
typedef struct s_parameters
{
	char	empt;
	char	obst;
	char	full;
	int		bgn;
	int		nmb;
	int		len;
}	t_prm;
typedef struct s_coordinates
{
	int	max;
	int	crd_i;
	int	crd_j;
}	t_crd;
char	*reader(char	*file);
char	*get_file(void);

void	ft_putstr(char	*str);
int		ft_strlen(char	*str, char	c, int	i);
int		ft_atoi(char	*map, int	len);
char	*ft_error(char	*map);

int		valid_1(char	*map, int	len);
int		valid_2(char	*map, int	len, int	numb);
int		valid_3(char	*map, int	len);

t_prm	*get_prm(char	*map, int	len, int	numb);
t_crd	*create_crd(int	**mat, char	**arr, t_prm	*p);

char	**arr_crt(char	*map, t_prm	*p);
void	arr_fill(char	**arr, char	*map, t_prm	*p);
void	arr_del_ind(char	**arr, int	i);
void	arr_del(char	**arr, t_prm	*p);

int		**mat_crt(char	**arr, char	*map, t_prm	*p);
void	mat_fill(int	**mat, char	*map, t_prm	*p);
void	mat_del_ind(int	**mat, int	i);
void	mat_del(int	**mat, t_prm	*p);

int		find_min(int	a, int	b, int	c);
void	ft_counter(int	**mat, t_prm	*p);
t_crd	*get_max_crd(int	**mat, char	**arr, t_prm	*p);
void	print_sqr(char	**arr, t_prm	*p, t_crd	*k);
#endif
