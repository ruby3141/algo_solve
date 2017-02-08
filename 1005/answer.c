//https://www.acmicpc.net/problem/1005

#include <stdio.h>
#include <inttypes.h>

int32_t loop(int16_t n, int32_t k);

int main(void)
{
	int16_t n;
	int32_t t, k;
	scanf("%"SCNd32, &t);
	while(t--)
	{
		scanf("%"SCNd16" %"SCNd32, &n, &k);
		printf("%"PRId32"\n", loop(n, k));
	}
}

int32_t loop(int16_t n, int32_t k)
{
	int16_t time[n], x, y;
	int32_t calc[n];
	for(int16_t i = 0; i < n; i++)
	{
		scanf("%"SCNd16, time + i);
		calc[i] = 0;
	}
	calc[0] = time[0];
	for(int32_t i = 0; i < k; i++)
	{
		scanf("%"SCNd16" %"SCNd16, &x, &y);
		if(calc[y-1] < calc[x-1] + time[y-1]) calc[y-1] = calc[x-1] + time[y-1];
	}
	scanf("%"SCNd16, &x);
	return calc[x-1];
}
