//https://www.acmicpc.net/problem/1531
#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	int8_t pic[100][100];
	int8_t n, m;
	int8_t lux, luy, rdx, rdy, xb, yb;
	int32_t result;

	n = 0; m = 0;
	while(n < 100)
	{
		while(m < 100)
		{
			pic[n][m] = 0;
			m++;
		}
		m = 0;
		n++;
	}
	scanf("%"SCNd8" %"SCNd8, &n, &m);
	while(n--)
	{
		scanf("%"SCNd8 " %"SCNd8 " %"SCNd8 " %"SCNd8, &lux, &luy, &rdx, &rdy);
		lux--;luy--;rdx--;rdy--;
		xb = lux;
		yb = luy;
		while(xb <= rdx)
		{
			while(yb <= rdy)
			{
				pic[xb][yb]++;
				yb++;
			}
			yb = luy;
			xb++;
		}
	}
	xb = 0; yb = 0;
	result = 0;
	while(xb < 100)
	{
		while(yb < 100)
		{
			if(pic[xb][yb] > m) result++;
			yb++;
		}
		yb = 0;
		xb++;
	}
	printf("%"PRId32, result);
}
