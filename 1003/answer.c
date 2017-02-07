//https://www.acmicpc.net/problem/1003

#include <stdio.h>
#include <inttypes.h>

int32_t _0;
int32_t _1;

int32_t fiv(int32_t input);

int main(void)
{
	int32_t t, input;
	scanf("%"SCNd32, &t);
	while(t--)
	{
		_0 = 0;
		_1 = 0;
		scanf("%"SCNd32, &input);
		fiv(input);
		printf("%"PRId32" %"PRId32"\n", _0, _1);
	}
}

int32_t fiv(int32_t input)
{
	if(input == 0) {_0++; return 0;}
	if(input == 1) {_1++; return 1;}
	return fiv(input - 1) + fiv(input - 2);
}
