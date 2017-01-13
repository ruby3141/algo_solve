//https://www.nnacmicpc.net/problem/1579
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct map_t
{
	int16_t **map;
	int16_t **path;
	int8_t n, m; //same name in the question for height and width.
	int16_t result;
} map_t;

typedef struct maplist_t
{
	map_t **maplist;
	int16_t size;
	int16_t b;
} maplist_t

//function prototypes
void flip_map(map_t *map);
void calcpathv(map_t *map);
map_t *map_init(int8_t n, int8_t m);
map_t *map_copy(map_t *map);
void collectpath(maplist_t maplist, int32_t startpoint, int8_t n, int8_t m);

int main(void)
{
	int8_t i, j;
	int32_t q;;

	q = 1;
	maplist = (map_t **)malloc(sizeof(map_t *));
	scanf("%d %d", &i, &j);
	maplist[0] = map_init(i, j);
	i = 0;
	while(i < *(maplist)->n)
	{
		j = 0;
		while(j < *(maplist)->m)
		{
			scanf("%d", *(maplist)->map[i][j]);
			j++;
		}
		i++;
	}
}

map_t *map_init(int8_t n, int8_t m)
{
	map_t *temp;
	int8_t i;

	temp = (map_t *)malloc(sizeof(map_t));
	temp->map = (int16_t **)malloc(sizeof(int16_t *) * n);
	temp->path = (int16_t **)malloc(sizeof(int16_t *) * n);
	i = 0;
	while(i < n)
	{
		*(temp->map+i) = (int16_t *)malloc(m*sizeof(int16_t));
		*(temp->path+i) = (int16_t *)malloc(m*sizeof(int16_t));
		i++;
	}
	temp->n = n;
	temp->m = m;
	temp->result = 0;
	return temp;
}

map_t *map_copy(map_t *map)
{
	map_t *temp;
	int8_t i;

	temp = map_init(map->n, map->m);
	i = 0;
	while(i < map->n)
	{
		memcpy(*(map->map + i), *(temp->map + i), map->m);
		memcpy(*(map->path + i), *(temp->path +i), map->m);
	}
	return temp;
}

void flip_map(map_t *map)
{
	int8_t i,j
	int16_t buf;

	i = 0;
	while(i < map->n)
	{
		j=0;
		while(j < ((map->m + 1) / 2))
		{
			buf = map->map[i][j];
			map->map[i][j] = map->map[map->n - i - 1][map->m - j - 1];
			map->map[map->n - i - 1][map->m - j - 1] = buf;
			j++;
		}
		i++;
	}
}

void calcpathv(map_t *map)
{
	int8_t i, j;
	i = 0;
	while(i < map->n)
	{
		j = 0;
		while(j < map->m)
		{
			map->path[i][j] = map->map[i][j];
			if(i == 0 && j == 0); //structural mistake, but not serious.
			else if(i == 0) map->path[i][j] += map->path[i][j-1];
			else if(j == 0) map->path[i][j] += map->path[i-1][j];
			else if(map->path[i][j-1] > map->path[i-1][j])
			{
				map->path[i][j] += map->path[i][j-1];
			}
			else
			{
				map->path[i][j] += map->path[i-1][j];
			}
			j++;
		}
		i++;
	}
	map->result += map->path[map->n-1][map->m-1];
}

void collectpath(maplist_t maplist, int32_t startpoint, int8_t n, int8_t m)
{
	
}
