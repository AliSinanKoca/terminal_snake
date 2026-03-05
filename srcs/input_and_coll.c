#include "includes.h"

int	DIRECTION;

//Gets direction given by input. !!! exit() here !!!
void	check_input(char input)
{
	if ((input == 'w' || input == 'W') && DIRECTION != DOWN)
		DIRECTION = UP;
	else if ((input == 's' || input == 'S') && DIRECTION != UP)
		DIRECTION = DOWN;
	else if ((input == 'a' || input == 'A') && DIRECTION != RIGHT)
		DIRECTION = LEFT;
	else if ((input == 'd' || input == 'D') && DIRECTION != LEFT)
		DIRECTION = RIGHT;
	else if (input == 'q' || input == 'Q')
	{
		disable_raw_mode();
		exit(0);
	}
}

//Move towards direction.
void	check_direction(int *new_x, int *new_y)
{
	if (DIRECTION == UP)
		*new_y -= 1;
	else if (DIRECTION == DOWN)
		*new_y += 1;
	else if (DIRECTION == LEFT)
		*new_x -= 1;
	else if (DIRECTION == RIGHT)
		*new_x += 1;
}

// Checks for GAME OVERs. !!! "exit()" HERE !!!
void	check_collision(snk *s, int x, int y)
{
	snk	*temp;

	temp = s;
	if ((x == 0 || x == 59) || (y == 0 || y == 19))
	{
		disable_raw_mode();
		exit_protocol(s);
		printf("\n\nGAME OVER\n\n");
		exit(0);
	}
	while (temp)
	{
		if (x == temp->x && y == temp->y)
		{
			disable_raw_mode();
			exit_protocol(s);
			printf("\n\nGAME OVER\n\n");
			exit(0);
		}
		temp = temp->next;
	}
}
/*
int	choose_speed(char spd[10])
{
	int	i;
	int	speed;

	scanf("%s", spd)
	i = 0;
	while (spd[i])
	{
		if (spd[i] < '0' || spd[i] > '9')
		{
			printf("Input must be 1-9");
			return (-1);
		}
		i++;
	}
	speed = atoi(spd);
	if (speed > 9 || speed < 1)
	{
		printf("Input must be 1-9");
		return (-1);
	}
	return (speed);
}
*/

