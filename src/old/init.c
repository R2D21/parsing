#include "../includes/my.h"

t_AI	*init(t_AI *AI)
{
  if ((AI = malloc(1 * sizeof(*AI))) == NULL)
    my_putstr_error("[INIT:6] Error: malloc() is fail.\nThe struct AI is NULL.\n");
  else
    {
      if ((AI->sujets = malloc_tab(AI->sujets)) == NULL)
	my_putstr_error("[INIT:10] Error: malloc_tab() is fail.\nAI->sujets is NULL.\n");
      else if ((AI->verbes = malloc_tab(AI->verbes)) == NULL)
	my_putstr_error("[INIT:13] Error: malloc_tab() is fail.\nAI->verbes is NULL.\n");
      else if ((AI->complements = malloc_tab(AI->complements)) == NULL)
	my_putstr_error("[INIT:16] Error: malloc_tab() is fail.\nAI->complements is NULL.\n");
      else
	if ((AI->sujet_phrase = malloc(4096 * sizeof(*AI->sujet_phrase))) == NULL)
	  my_putstr_error("[INIT:8] Error: malloc_tab() is fail.\nAI->sujets is NULL.\n");
	else if ((AI->verbe_phrase = malloc(4096 * sizeof (*AI->verbe_phrase))) == NULL)
	  my_putstr_error("[INIT:8] Error: malloc_tab() is fail.\nAI->sujets is NULL.\n");
      	else if ((AI->complement_phrase = malloc(4096 * sizeof(*AI->complement_phrase))) == NULL)
	  my_putstr_error("[INIT:8] Error: malloc_tab() is fail.\nAI->sujets is NULL.\n");
	else
	  return (AI);
    }
  return (NULL);  /* exit (1); */
}

