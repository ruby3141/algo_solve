#include <stdio.h>

int main(void)
{
	int fib[2][41];
	int i,j;

	fib[0][0] = fib[1][1] = 1;
	fib[1][0] = fib[0][1] = 0;
	for(i = 2; i < 41; i++)
	{
		fib[0][i] = fib[0][i-1] + fib[0][i-2];
		fib[1][i] = fib[1][i-1] + fib[1][i-2];
	}
	for(scanf("%d", &i);i--;)
	{
		scanf("%d", &j);
		printf("%d %d\n", fib[0][j], fib[1][j]);
	}
}
