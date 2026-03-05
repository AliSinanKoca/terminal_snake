#include "includes.h"

//Spawn fruit, not on snake.
void	spawn_fruit(frt *fruit, snk *s)
{
	snk	*temp;
	int	valid;

	if (!s)
		return ;
	valid = 0;
	while (valid == 0)
	{
		valid = 1;
		fruit->x = rand() % 58 + 1;
		fruit->y = rand() % 18 + 1;
		temp = s;
		while (temp)
		{
			if((temp->x == fruit->x) && (temp->y == fruit->y))
			{
				valid = 0;
				break;
			}
			temp = temp->next;
		}
	}
}
