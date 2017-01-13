#include "../includes/my.h"

void		add_list(t_gere *gere, char *str, char *s1)
{
  int		i;
  t_params       flags[]= {
    {"term", add_list_tem},
    {"pronom", add_list_pronom},
  };
  t_params1       flags1[]= {
    {"verbe", add_verbe},
    {"com", add_list_complements},
  };
 
  i = 0;
  while (i < 2)
    {
      if (strcmp(str, flags[i].flag) == 0)
  	flags[i].p(gere);
      i++;
    }
 i = 0;
  while (i < 2)
    {
      if (strcmp(str, flags1[i].flags) == 0)
        flags1[i].p1(gere->list, s1);
      i++;
    }
}

void		add_verbe(t_list1 *list, char *str)
{
  t_datas	*datas;

  if ((datas = malloc(1 * sizeof (*datas))) == NULL)
    {
      my_putstr_error("[GETS_LIST:9] Error: malloc() is fail.\n");
      my_putstr_error("The struct datas is NULL.\n");
      exit(1);
    }
  else if (list == NULL)
    {
      my_putstr_error("[GETS_LIST:9] Error: the struct list is NULL.\n");
      exit(1);
    }
  else
    {
      datas->verbes = str;
      datas->next = list->first;
      list->first = datas;
    }
}


void		add_list_complements(t_list1 *list, char *str)
{
  t_datas	*datas;

  if ((datas = malloc(1 * sizeof (*datas))) == NULL)
    {
      my_putstr_error("[GETS_LIST:9] Error: malloc() is fail.\n");
      my_putstr_error("The struct datas is NULL.\n");
      exit(1);
    }
  else if (list == NULL)
    {
      my_putstr_error("[GETS_LIST:9] Error: the struct list is NULL.\n");
      exit(1);
    }
  else 
    {
      datas->complements = str;
      datas->next = list->first;
      list->first = datas;
    }
}

/* Ajoute dans la liste chainée list la teminaison des verbes */

void		add_list_tem(/* t_list1 *list, char **tab */t_gere *gere)
{
  t_datas	*datas;
  int		i;

  i = 1;
  if ((datas = malloc(4096 * sizeof (char))) == NULL)
    my_putstr_error("[MY_LIST:33] Error: malloc() is fail.\n");
  else if (gere->list == NULL)
    my_putstr_error("[MY_LIST:35] Error: The list is NULL\n");
  else
    if (gere->tab == NULL || **gere->tab == '\0')
      my_putstr_error("[MY_LIST:39] Error: str is NULL or empty.\n");
    else
      {
  	datas = gere->list->first;
  	while (*gere->tab[i] != '\0' && datas->next != NULL)
  	  {
  	    datas->terminaison = gere->tab[i];
  	    datas = datas->next;
  	    i = i + 2;
  	  }
      }
}

/* Ajoute dans la liste chainée list le pronom des verbes */

void		add_list_pronom(t_gere *gere/* t_list1 *list, char **tab */)
{
  t_datas	*datas;
  int		i;

  i = 0;
  if ((datas = malloc(4096 * sizeof (char))) == NULL)
    my_putstr_error("[MY_LIST:33] Error: malloc() is fail.\n");
  else if (gere->list == NULL)
    my_putstr_error("[MY_LIST:35] Error: The list is NULL\n");
  else
    if (gere->tab == NULL || **gere->tab == '\0')
      my_putstr_error("[MY_LIST:39] Error: str is NULL or empty.\n");
    else
      {
	datas = gere->list->first;
	while (*gere->tab[i] != '\0' && datas->next != NULL)
	  {
	    datas->pronom = gere->tab[i];
	    i = i + 2;
	    datas = datas->next;
	  }
      }
}
