#include "bsq.h"

int	**mat_crt(char	**arr, char	*map, t_prm	*p)
{
	int	i;
	int	**mat;

	i = 0;
	mat = (int **)malloc((p->nmb + 1) * sizeof(int *));
	if (mat == NULL)
	{
		arr_del(arr, p);
		free(p);
		free(map);
		return (NULL);
	}
	while (i < p->nmb)
	{
		mat[i] = malloc (p->len * sizeof(int *));
		if (mat[i] == NULL)
		{
			mat_del_ind (mat, i);
			arr_del(arr, p);
			free(p);
			free(map);
			return (NULL);
		}
		i++;
	}
	return (mat);
}

void	mat_fill(int	**mat, char	*map, t_prm	*p)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = p->bgn;
	while (i < p->nmb)
	{
		j = 0;
		while (map[k] != '\n')
		{
			if (map[k] == p->empt)
				mat[i][j] = 1;
			else if (map[k] == p->obst)
				mat[i][j] = 0;
			j++;
			k++;
		}
		k = k + 1;
		i++;
	}
	free(map);
}

void	ft_counter(int	**mat, t_prm	*p)
{
	int	i;
	int	j;

	i = 0;
	while (i < p->nmb)
	{
		j = 0;
		while (j < p->len)
		{
			if (mat[i][j] != 0)
			{
				if (i == 0 || j == 0)
					mat[i][j] = mat[i][j] + 0;
				else
				{
					mat[i][j] = mat[i][j] + find_min(mat[i - 1][j],
							mat[i - 1][j - 1], mat[i][j - 1]);
				}
			}
			j++;
		}
		i++;
	}
}

t_crd	*get_max_crd(int	**mat, char	**arr, t_prm	*p)
{
	int		i;
	int		j;
	t_crd	*k;

	i = 0;
	k = create_crd(mat, arr, p);
	k->max = 0;
	while (i < p->nmb)
	{
		j = 0;
		while (j < p->len)
		{
			if (mat[i][j] > k->max)
			{
				k->max = mat[i][j];
				k->crd_i = i;
				k->crd_j = j;
			}
			j++;
		}
		i++;
	}
	mat_del(mat, p);
	return (k);
}

void	print_sqr(char	**arr, t_prm	*p, t_crd	*k)
{
	int	i;
	int	j;

	i = (k->crd_i - (k->max) + 1);
	while (i <= k->crd_i)
	{
		j = (k->crd_j - (k->max) + 1);
		while (j <= k->crd_j)
		{
			arr[i][j] = p->full;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < p->nmb)
	{
		ft_putstr(arr[i]);
		i++;
	}
	free(k);
	arr_del(arr, p);
	free(p);
}
