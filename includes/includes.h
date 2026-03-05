#ifndef INCLUDES_H
# define INCLUDES_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <termios.h>
# include <time.h>
# include <unistd.h>

//DIRECTIONS
# define UP 1
# define DOWN 2
# define RIGHT 3
# define LEFT 4
extern int DIRECTION;

extern int score;

typedef struct fruit
{
	int	x;
	int	y;
} frt;

typedef struct head
{
	int	x;
	int	y;
	struct head *next;
} snk;

//TERMINAL CONTROL
void	enable_raw_mode(void);
void	disable_raw_mode(void);

//SNAKE FUNCTIONS
snk	*init_snake(int x, int y);
snk	*add_seg(int x, int y);
void	move_grow_snake(snk **s, frt *fruit);
void	remove_tail(snk *s);
void	put_snk_frt_grid(char grid[20][60], snk *s, frt f);
int	snake_size(snk *s);

//FRUIT FUNCTIONS
void    spawn_fruit(frt *fruit, snk *s);

//GRID FUNCTIONS
void	create_grid(char grid[20][60]);
void	print_grid(char grid[20][60]);

//INPUT HANDLING AND COLLISIONS
void	check_input(char input);
void	check_direction(int *new_x, int *new_y);
void	check_collision(snk *s, int x, int y);
void	print_commands(void);

//MEMORY FREEING
void	exit_protocol(snk *s);

#endif
