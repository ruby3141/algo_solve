//https://www.acmicpc.net/problem/1004

#include <stdio.h>
#include <inttypes.h>
#include <math.h>

int main(void)
{
	int32_t t;
	int16_t x1, y1, x2, y2, n, cx, cy, r, answer;

	scanf("%"SCNd32, &t);
	while(t--)
	{
		answer = 0;
		scanf("%"SCNd16"%"SCNd16"%"SCNd16"%"SCNd16, &x1, &y1, &x2, &y2);
		scanf("%"SCNd16, &n);
		while(n--)
		{
			scanf("%"SCNd16"%"SCNd16"%"SCNd16, &cx, &cy, &r);
			if(sqrt(pow(x1 - cx, 2) + pow(y1 - cy, 2)) < r){
				if(sqrt(pow(x2 - cx, 2) + pow(y2 - cy, 2)) >= r) answer++;}
			else if(sqrt(pow(x2 - cx, 2) + pow(y2 - cy, 2)) < r) answer++;
		}
		printf("%"PRId16"\n", answer);
	}
}
