//https://www.acmicpc.net/problem/1001

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	int8_t a, b;
	scanf("%"SCNd8"%"SCNd8, &a, &b);
	printf("%"PRId8, a-b);
	return 0;
}
