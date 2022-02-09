#include "bsq.h"

void	arr_del(char **arr, t_prm *p)
{
	int	i;

	i = 0;
	while (i < p->nmb)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	arr_del_ind(char **arr, int	i)
{
	while (i >= 1)
	{
		free(arr[i]);
		i = i - 1;
	}
	free(arr);
}

void	mat_del(int	**mat, t_prm	*p)
{
	int	i;

	i = 0;
	while (i < p->nmb)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

void	mat_del_ind(int	**mat, int	i)
{
	while (i >= 1)
	{
		free(mat[i]);
		i = i - 1;
	}
	free(mat);
}
