//https://www.acmicpc.net/problem/1524
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t comp(const void *p, const void *q)
{
	int x = *(const int *)p;
	int y = *(const int *)q;
	if(x < y) return -1;
	else if(x < y) return 1;
	else return 0;
}

int64_t main(void)
{
	int64_t t, n, m, i, j; //same name in the question, and i, j are temp variables.
	int64_t *nl, *ml;

	scanf("%ld", &t);
	while(t--)
	{
		scanf("%ld %ld", &n, &m);
		nl = (int64_t *)malloc(n*sizeof(int64_t));
		ml = (int64_t *)malloc(m*sizeof(int64_t));
		i = 0;
		while(i < n)
		{
			scanf("%ld", nl+i);
			i++;
		}
		i = 0;
		while(i < m)
		{
			scanf("%ld", ml+i);
			i++;
		}
		qsort(nl, n, sizeof(int64_t), &comp);
		qsort(ml, m, sizeof(int64_t), &comp);
		i = 0;
		j = 0;
		while(i<n && j<m)
		{
			if(nl[i] < ml[j]) i++;
			else j++;
		}
		if(i == n)puts("B");
		else puts("S");
		free(nl);
		free(ml);
	}
	return 0;
}
