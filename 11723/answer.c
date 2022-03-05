#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
	int M, x;
	uint32_t set = 0;
	char buf[10];
	scanf("%d\n", &M);

	while(M--)
	{
		gets(buf);
		switch(buf[0])
		{
			case 'a':
				if (buf[1] == 'd') // add
				{
					x = atoi(buf + 4);
					set |= (1 << x);
				}
				else // all
					set = 0xFFFFFFFF;
				break;
			case 'c': // check
				x = atoi(buf + 6);
				printf("%d\n", (set & (1 << x)) ? 1 : 0);
				break;
			case 'e': // empty
				set = 0x00000000;
				break;
			case 'r': // remove
				x = atoi(buf + 7);
				set &= ~(1 << x);
				break;
			case 't': // toggle
				x = atoi(buf + 7);
				set ^= (1 << x);
				break;
		}
	}

}