#include "bsq.h"

void	bsq_run(char	*map)
{
	char	**arr;
	int		**mat;
	t_prm	*p;
	int		len;
	int		numb;

	len = ft_strlen(map, '\n', 0);
	if (valid_1(map, len) == 0)
	{
		numb = ft_atoi(map, len);
		if ((valid_2(map, len, numb) == 0) && (valid_3(map, len) == 0))
		{	
			p = get_prm(map, len, numb);
			arr = arr_crt(map, p);
			arr_fill(arr, map, p);
			mat = mat_crt(arr, map, p);
			mat_fill(mat, map, p);
			ft_counter(mat, p);
			print_sqr(arr, p, get_max_crd(mat, arr, p));
		}
		else
			ft_error(map);
	}
	else
		ft_error(map);
}

int	main(int	argc, char	**argv)
{
	char	*map;
	char	*filenew;
	int		i;

	i = 1;
	if (argc == 1)
	{
		filenew = get_file();
		map = reader(filenew);
		bsq_run(map);
	}
	while (i < argc)
	{
		map = reader(argv[i]);
		bsq_run(map);
		i++;
	}
	return (0);
}
