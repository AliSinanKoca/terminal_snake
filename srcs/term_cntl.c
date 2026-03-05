#include "includes.h"

static struct termios original_term;

//Function to disable canonical mode of the terminal, to read input immediately.
void	enable_raw_mode(void)
{
	struct termios  term;

	tcgetattr(STDIN_FILENO, &original_term);	//get current settings of terminal.
	term = original_term;				//copy it into 'term'.
	term.c_lflag &= ~(ICANON | ECHO);		//disable canonical mode (no 'ENTER') & echo (no rewrite).
	tcsetattr(STDIN_FILENO, TCSANOW, &term);	//now set the terminal with those settings, right now.

	fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);	//makes 'read()' run even if no input. Otherwise would have to constantly press key to move.
}

//reset terminal window, with 'original_term'.
void	disable_raw_mode(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &original_term);//get back the original terminal window.
}
