#include "includes.h"

void	print_commands(void)
{
	printf(" W : UP \n A : LEFT \n S : DOWN \n D : RIGHT \n Q : QUIT \n");
}

void	create_grid(char grid[20][60])
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < 60)
		grid[0][i++] = '#';
	while (j < 19)
	{
		i = 0;
		while (i < 60)
		{
			if (i > 0 && i < 59)
				grid[j][i] = ' ';
			else
				grid[j][i] = '#';
			i++;
		}
		j++;
	}
	i = 0;
	while (i < 60)
		grid[j][i++] = '#';
}

void	print_grid(char grid[20][60])
{
	int     i;
	int     j;

	//clears screen
	printf("\e[1;1H\e[2J");
	print_commands();
	j = 0;
	while (j < 20)
	{
		i = 0;
		while (i < 60)
		{
			printf("%c", grid[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}
