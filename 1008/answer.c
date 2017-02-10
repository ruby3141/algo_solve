//https://www.acmicpc.net/problem/1008

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	int8_t a, b;
	scanf("%"SCNd8"%"SCNd8, &a, &b);
	printf("%llf", (long double)a/(long double)b);
	return 0;
}
