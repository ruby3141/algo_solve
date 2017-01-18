//https://www.acmicpc.net/problem/9815

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int16_t nextint(int16_t input, int8_t digit);

int64_t main(void)
{
	int16_t input;
	while(1)
	{
		scanf("%"SCNd16, &input);
		if(input == -1) return 0;
		else if(1000 > input || input > 9999 || input/1111*1111 == input) printf("No!!\n");
		else
		{
			printf("N=%"PRId16":\n", input);
			for(int16_t i = 0;; i++)
			{
				if(input == 6174 || input == 0)
				{
					printf("Ok!! %"PRId16" times\n", i);
					break;
				}
				input = nextint(input, input>999?4:input>99?3:input>9?2:1);
			}
		}
	}
}

int16_t nextint(int16_t input, int8_t digit)
{
	int8_t buf[digit+1], k;
	int16_t p, q;
	for(int8_t i = 0; i < digit+1; i++)
	{
		buf[i] = input - (input / 10 * 10) + '0';
		input /= 10;
	}
	buf[digit] = '\0';
	for(int8_t i = digit-1; i >= 0; i--)
	{
		for(int8_t j = 0; j < i; j++)
			if(buf[j] > buf[i]) {k = buf[j]; buf[j] = buf[i]; buf[i] = k;}
	}
	p = (int16_t)atoi(buf);
	for(int8_t i = digit-1; i > (digit-1)/2; i--)
		{k = buf[i]; buf[i] = buf[digit-i-1]; buf[digit-i-1] = k;}
	q = (int16_t)atoi(buf);
	printf("%"PRId16"-%"PRId16"=%"PRId16"\n", q,p,q-p);
	return q-p;
}
