#include "../includes/my.h"

t_AI	*init_AI(t_AI *AI)
{
  if ((AI = malloc(1 * sizeof(*AI))) == NULL)
    my_putstr_error("[INIT:6] Error: malloc() is fail.\nThe struct AI is NULL.\n");
  else
    {
      if ((AI->sujet = malloc(4096 * sizeof(*AI->sujet))) == NULL)
	my_putstr_error("[INIT:10] Error: malloc() is fail.\nAI->sujets is NULL.\n");
      else if ((AI->verbe = malloc(4096 * sizeof(*AI->verbe))) == NULL)
	my_putstr_error("[INIT:12] Error: malloc() is fail.\nAI->verbes is NULL.\n");
      else if ((AI->complement = malloc(4096 * sizeof (*AI->complement))) == NULL)
	my_putstr_error("[INIT:14] Error: malloc() is fail.\nAI->complements is NULL.\n");
      else if ((AI->key = malloc(4096 * sizeof (*AI->key))) == NULL)
	my_putstr_error("[INIT:14] Error: malloc() is fail.\nAI->complements is NULL.\n");
      else
	return (AI);
    }
  return (NULL);  /* exit (1); */
}

t_gere		*init_gere(t_gere *gere)
{
  if ((gere = malloc(1 * sizeof(*gere))) == NULL)
    my_putstr_error("[INIT:26] Error: malloc() is fail.\n");
  else
    if ((gere->list = malloc(1 * sizeof(*gere->list))) == NULL)
      my_putstr_error("[INIT:30] Error: malloc() is fail.\n");
    else if ((gere->tab = malloc_tab(gere->tab)) == NULL)
      my_putstr_error("[INIT:32] Error: malloc() is fail.\n");
    else
      return(gere);
  return (NULL);
}

