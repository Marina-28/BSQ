#include "bsq.h"

void	bsq(char *map, int numb, int len)
{
	char	**arr;
	int		**mat;
	t_prm	*p;

	p = get_prm(map, len, numb);
	if (p == NULL)
		return ;
	arr = arr_crt(map, p);
	if (arr == NULL)
		return ;
	arr_fill(arr, map, p);
	mat = mat_crt(arr, map, p);
	if (mat == NULL)
		return ;
	mat_fill(mat, map, p);
	ft_counter(mat, p);
	print_sqr(arr, p, get_max_crd(mat, arr, p));
}

void	bsq_run(char	*map)
{
	int		len;
	int		numb;

	len = ft_strlen(map, '\n', 0);
	if (valid_1(map, len) == 0)
	{
		numb = ft_atoi(map, len);
		if ((valid_2(map, len, numb) == 0))
			bsq(map, numb, len);
		else
			ft_error(map);
	}
	else
		ft_error(map);
}

int	main(int argc, char **argv)
{
	char	*map;
	char	*filenew;
	int		i;

	i = 1;
	if (argc == 1)
	{
		filenew = get_file();
		if (filenew == NULL)
			return (0);
		map = reader(filenew);
		if (map != NULL)
			bsq_run(map);
	}
	while (i < argc)
	{
		map = reader(argv[i]);
		if (map != NULL)
			bsq_run(map);
		i++;
	}
	return (0);
}
