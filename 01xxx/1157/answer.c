#include <stdio.h>

int main(void)
{
	char str[1000000 + 1];
	int charcount[26] = {0};
	scanf("%s", str);
	for(int i = 0; i < 1000000; i++)
	{
		if(str[i] == '\0')
			break;
		else if(str[i] < 'a')
			charcount[str[i] - 'A'] += 1;
		else
			charcount[str[i] - 'a'] += 1;
	}

	int max_count = 0;
	for(int i = 0; i < 26; i++)
	{
		if(max_count < charcount[i])
			max_count = charcount[i];
	}

	char max_char = '?';
	for(int i = 0; i < 26; i++)
	{
		if(charcount[i] == max_count)
		{
			if(max_char == '?')
				max_char = i + 'A';
			else
			{
				max_char = '?';
				break;
			}
		}
	}

	printf("%c\n", max_char);
	return 0;
}