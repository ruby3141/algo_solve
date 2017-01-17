//https://www.acmicpc.net/problem/4880

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	int16_t a1, a2, a3;
	while(1)
	{
	scanf("%"SCNd16"%"SCNd16"%"SCNd16, &a1, &a2, &a3);
	if(a1 == a2 && a2 == a3) return 0;
	else if(a2 * 2  == a3 + a1) printf("AP %"PRId16"\n", a3 + a2 - a1);
	else printf("GP %"PRId16"\n", a3*a2/a1);
	}
}
