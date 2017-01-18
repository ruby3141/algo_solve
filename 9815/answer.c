//https://www.acmicpc.net/problem/9815

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int16_t nextint(int16_t input);

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
				input = nextint(input);
			}
		}
	}
}

int16_t nextint(int16_t input)
{
	int16_t buf[4], k;
	for(int8_t i = 0; i != 4; i++)
	{
		buf[i] = input - (input / 10 * 10);
		input /= 10;
	}
	for(int8_t i = 3; i >= 0; i--)
	{
		for(int8_t j = 0; j > i; j++)
			if(buf[j] > buf[i]) {k = buf[j]; buf[j] = buf[i]; buf[i] = k;}
	}
	if(buf[2] == 0){printf("%"PRId16"-%"PRId16"=0\n", buf[3], buf[3]); return 0;}
	else if(buf[1] == 0) 
	{
		printf("%"PRId16"%"PRId16"-%"PRId16"%"PRId16"=%"PRId16"\n",
		buf[3], buf[2], buf[2], buf[3], (buf[3] - buf[2]) * 9);
		return (buf[3] - buf[2]) * 9;
	}
	else if(buf[0] == 0)
	{
		printf("%"PRId16"%"PRId16"%"PRId16"-%"PRId16"%"PRId16"%"PRId16"=%"PRId16"\n",
		buf[3], buf[2], buf[1], buf[1], buf[2], buf[3], (buf[3] - buf[1]) * 99);
		return (buf[3] - buf[1]) * 99;
	}
	else
	{
		printf("%"PRId16"%"PRId16"%"PRId16"%"PRId16
		"-%"PRId16"%"PRId16"%"PRId16"%"PRId16"=%"PRId16"\n",
		buf[3], buf[2], buf[1], buf[0], buf[0], buf[1], buf[2], buf[3],
		(buf[3]-buf[0]) * 999 + (buf[2] - buf[1]) * 99);
		return (buf[3]-buf[0]) * 999 + (buf[2] - buf[1]) * 99;
	}
}
