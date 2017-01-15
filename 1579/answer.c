//https://www.nnacmicpc.net/problem/1579
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
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
	int8_t n, m;
	map_t **maplist;
	int16_t size;
} maplist_t;

//function prototypes
void flip_map(map_t *map);
void calcpathv(map_t *map);
map_t *map_init(int8_t n, int8_t m);
map_t *map_copy(map_t *map);
void collectpath(maplist_t *maplist, int32_t point, int8_t n, int8_t m);

int main(void)
{
	int16_t i, j;
	maplist_t *maplist;

	maplist = (maplist_t *)malloc(sizeof(maplist_t));
	maplist->maplist = (map_t **)malloc(sizeof(map_t *));
	maplist->size = 1;
	scanf("%"SCNd8" %"SCNd8, (int8_t *)&i, (int8_t *)&j);
	maplist->n = i; maplist->m = j;
	maplist->maplist[0] = map_init(i, j);
	i = 0;
	while(i < maplist->n)
	{
		j = 0;
		while(j < maplist->m)
			{
			scanf("%"SCNd8, maplist->maplist[0]->map[i][j]);
			j++;
		}
		i++;
	}
	for(int a = 3; a ; a--)
	{
		i = 0;
		j = maplist->size;
		while(i < j)
		{
			calcpathv(maplist->maplist[i]);
			collectpath(maplist, i, maplist->n, maplist->m);
			i++;
		}
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
	int8_t i,j;
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

void collectpath(maplist_t *maplist, int32_t point, int8_t n, int8_t m)
{
	map_t *map = maplist->maplist[point];
	while(n < 0 && m < 0)
	{
		if(map->path[n][m] == map->map[n][m] + map->path[n][m - 1])
		{
			if(map->path[n][m] == map->map[n][m] + map->path[n - 1][m])
			{
				realloc(maplist->maplist, sizeof(map_t *) * (maplist->size + 1));
				maplist->maplist[maplist->size] = map_copy(map);
				maplist->size++;
				map->map[n][m] == 0;
				collectpath(maplist, maplist->size - 1, n - 1, m);
				m--;
			}
			else {map->map[n][m] == 0; m--;}
		}
		else {map->map[n][m] == 0; n--;}
	}
	if(n == 0) while(m <= 0)
	{
		map->map[n][m] = 0;
		m--;
	}
	else while(n <= 0)
	{
		map->map[n][m] = 0;
		n--;
	}
	filp_map(map);
}
