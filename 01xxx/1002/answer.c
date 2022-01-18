//https://www.acmicpc.net/problem/1002

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>

int main(void)
{
	int8_t t;
	int16_t x1, x2, rx, y1, y2, ry;
	double d;
	scanf("%"SCNd8, &t);
	while(t--)
	{
		scanf("%"SCNd16"%"SCNd16"%"SCNd16"%"SCNd16"%"SCNd16"%"SCNd16,&x1,&x2,&rx,&y1,&y2,&ry);
		d = sqrt(pow(x1 - y1, 2) + pow(x2 - y2, 2));
		if(d == 0 && rx == ry) puts("-1");
		else if(d > abs(rx-ry) && d < rx + ry) puts("2");
		else if(d == rx + ry || d == abs(rx - ry)) puts("1");
		else puts("0");
	}
}
