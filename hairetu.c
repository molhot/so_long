#include <stdio.h>

int map[5][5] = {
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1}
	};

int main ()
{
	int i = 0;
	int j = 0;

	while (i != 5)
	{
		while (j != 5)
		{
			printf("%d", map[i][j]);
			j = j + 1;
		}
		i++;
		j = 0;
	}
}