#include "includes.h"

//BIG RED BUTTON.
void	exit_protocol(snk *s)
{
	snk	*temp;

	while (s)
	{
		temp = s;
		s = s->next;
		free(temp);
	}
}
