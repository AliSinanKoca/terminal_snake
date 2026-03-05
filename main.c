#include "includes.h"

int	main(void)
{
	char	grid[20][60];
	snk	*snake;
	frt	fruit;

	//start the game terminal window.
	enable_raw_mode();

	snake = init_snake(29, 9);
	spawn_fruit(&fruit, snake);
	DIRECTION = UP;
	score = 0;

	while (1)
	{
		move_grow_snake(&snake, &fruit);
		create_grid(grid);
		put_snk_frt_grid(grid, snake, fruit);
		print_grid(grid);
		if (snake_size(snake) - 3 == 15)
			break;
		printf("\n   SCORE: %d   \n", score);
		usleep(150000 - (snake_size(snake) * 1500));
	}

	//get back to original terminal window..
	disable_raw_mode();
	printf("\e[1;1H\e[2J");	
	printf("\n\n   YOU WON!   \n\n");
	exit_protocol(snake);
	return (0);
}
