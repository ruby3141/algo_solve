//https://www.acmicpc.net/problem/1009

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	int8_t a, k;
	int32_t b, t;

	scanf("%"SCNd32, &t);
	while(t--)
	{
		scanf("%"SCNd8" %"SCNd32, &a, &b);
		a = a % 10;
		k = a % 10;
		while(--b)
		{
			k = (k * a) % 10;
		}
		printf("%"PRId8"\n", k!=0?k:10);
	}
}
