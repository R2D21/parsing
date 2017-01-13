#include "../includes/my.h"

t_AI	*init_AI(t_AI *AI)
{
  if ((AI = malloc(1 * sizeof(*AI))) == NULL)
    my_putstr_error("[INIT:6] Error: malloc() is fail.\nThe struct AI is NULL.\n");
  else
    {
      if ((AI->sujets = malloc(4096 * sizeof (*AI->sujets))) == NULL)
	my_putstr_error("[INIT:10] Error: malloc() is fail.\nAI->sujets is NULL.\n");
      else if ((AI->verbes = malloc(4096 * sizeof (*AI->verbes))) == NULL)
	my_putstr_error("[INIT:13] Error: malloc() is fail.\nAI->verbes is NULL.\n");
      else if ((AI->complements = malloc(4096 * sizeof(*AI->complements))) == NULL)
	my_putstr_error("[INIT:16] Error: malloc_tab() is fail.\nAI->complements is NULL.\n");
      else
	return (AI);
    }
  return (NULL);
}

