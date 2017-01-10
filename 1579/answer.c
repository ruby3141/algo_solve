#include <stdio.h>
#include <stdint.h>

int32_t **flip(int32_t **map, int32_t n, int32_t m)
{
	//not implemented yet
}

int32_t main(void)
{
	int32_t n, m, i, j, k //same name in the question. i, j are temp variables.
	int32_t **map, **path;

	scanf("%d %d", n, m);
	map = malloc(n*sizeof(int32_t *));
	path = malloc(n*sizeof(int32_t *));
	i = 0;
	while(i < n)
	{
		*(map+i) = malloc(m*sizeof(int32_t));
		*(path+i) = malloc(m*sizeof(int32_t));
		i++;
	}
	i = 0;
	while(i < n)
	{
		j = 0;
		while(j < m)
		{
			scanf("%d", &map[i][j]);
			j++;
		}
		i++;
	}
	k = 3;
}
