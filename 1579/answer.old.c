//https://www.acmicpc.net/problem/1579
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void flip(int32_t **map, int32_t n, int32_t m)
{
	int32_t i,j,buf;
	i = 0;
	while(i<n)
	{
		j=0;
		while(j<(m/2))
		{
			buf = map[i][j];
			map[i][j] = map[j][i];
			map[j][i] = buf;
			j++;
		}
		i++;
	}
}

void calcpathv(int32_t **map, int32_t **path, int32_t n, int32_t m)
{
	int32_t i, j;
	i = 0;
	while(i < n)
	{
		j = 0;
		while(j < m)
		{
			path[i][j] = map[i][j];
			if(i == 0 && j == 0); //structural mistake, but not serious.
			else if(i == 0) path[i][j] += path[i][j-1];
			else if(j == 0) path[i][j] += path[i-1][j];
			else if(path[i][j-1] > path[i-1][j])
			{
				path[i][j] += path[i][j-1];
			}
			else
			{
				path[i][j] += path[i-1][j];
			}
			j++;
		}
		i++;
	}
}

void 

int32_t main(void)
{
	int32_t n, m, i, j, k, result;//same name in the question. i, j, k are temp variables.
	int32_t **map, **path, ***maplist, listsize;

	scanf("%d %d", &n, &m);
	maplist = (int32_t ***) malloc(1*sizeof(int32_t **));
	listsize = 1;
	map = (int32_t **)malloc(n*sizeof(int32_t *));
	path = (int32_t **)malloc(n*sizeof(int32_t *));
	i = 0;
	while(i < n)
	{
		*(map+i) = (int32_t *)malloc(m*sizeof(int32_t));
		*(path+i) = (int32_t *)malloc(m*sizeof(int32_t));
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
	result = 0;
	k = 3;
	while(k--)
	{
		calcpathv(map, path, n, m);
		i = n-1;
		j = m-1;
		result += path[i][j];
		map[i][j] = 0;
		while(i > 0 && j > 0)
		{
			if(path[i][j] - map[i][j] == path[i][j-1])
			{
				map[i][j-1] = 0;
				j--;
			}
			else
			{
				map[i-1][j] =0;
				i--;
			}
		}
		if(i == 0)
		{
			while(j >= 0)
			{
				map[i][j] = 0;
				j--;
			}
		}
		else
		{
			while(i >= 0)
			{
				map[i][j] = 0;
				i--;
			}
		}
		flip(map, n, m);
	}
	printf("%d\n", result);
}
