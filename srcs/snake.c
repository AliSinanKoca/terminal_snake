#include "includes.h"

int	score;

//Create the segments of the snake. MALLOC HERE.
snk	*add_seg(int x, int y)
{
	snk	*head;

	head = malloc(sizeof(snk));
	if (!head)
		return (NULL);
	head->x = x;
	head->y = y;
	head->next = NULL;
	return (head);
}

//Creates snake.
snk	*init_snake(int x, int y)
{
	snk	*head;
	snk	*body;
	snk	*tail;

	head = add_seg(x, y);
	if (!head)
		return (NULL);
	body = add_seg(x + 1, y);
	if (!body)
		return (NULL);
	head->next = body;
	tail = add_seg(x + 2, y);
	if (!tail)
		return (NULL);
	body->next = tail;
	return (head);
}

//Removes tail. free() here.
void	remove_tail(snk *s)
{
	snk	*temp;

	temp = s;
	if (!temp || !temp->next)
		return ;
	while (temp->next->next)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
}

//Moves and grows snake. exit() may be called here in check_collision().
void	move_grow_snake(snk **s, frt *fruit)
{
	char	input;
	snk		*new_head;
	int		new_x;
	int		new_y;

	new_x = (*s)->x;
	new_y = (*s)->y;
	//if theres input check it, else move as usual.
	if (read(STDIN_FILENO, &input, 1) > 0)
		check_input(input);
	check_direction(&new_x, &new_y);
	check_collision(*s, new_x, new_y);
	new_head = add_seg(new_x, new_y);
	if (!new_head)
		return ;
	new_head->next = *s;
	*s = new_head;
	if (fruit->x == new_head->x && fruit->y == new_head->y)
	{
		spawn_fruit(fruit, *s);
		score++;
	}
	else
		remove_tail(*s);
}

void	put_snk_frt_grid(char grid[20][60], snk *s, frt f)
{
	snk	*temp;

	temp = s;
	while (temp)
	{
		grid[temp->y][temp->x] = '*';
		temp = temp->next;
	}
	grid[f.y][f.x] = 'o';
}

int	snake_size(snk *s)
{
	snk	*temp;
	int	size;

	size = 0;
	temp = s;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}
