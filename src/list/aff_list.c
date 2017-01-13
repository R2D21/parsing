#include "../includes/my.h"

void		aff_list_term(t_list1 *list)
{
  t_datas	*datas;
  
  if ((datas = malloc(1 * sizeof (*datas))) == NULL)
    {
      my_putstr_error("[GETS_LIST:9] Error malloc() is fail.\n");
      my_putstr_error("The struct datas is NULL.\n");
      exit(1);
    }
  else if (list == NULL)
    {
      my_putstr_error("[GETS_LIST:38] Error: aff_list1() is fail.\n");
      my_putstr_error("The struct list is NULL.\n");
      exit(1);
    }
  else
    {
      datas = list->first;
      while (datas->terminaison != NULL)
	{
	  my_putstr(datas->terminaison);
	  datas = datas->next;
	  my_putchar('\n');
	}
    }
}

void		aff_list_complements(t_list1 *list)
{
  t_datas	*datas;
  
  if ((datas = malloc(1 * sizeof (*datas))) == NULL)
    {
      my_putstr_error("[GETS_LIST:9] Error malloc() is fail.\n");
      my_putstr_error("The struct datas is NULL.\n");
      exit(1);
    }
  else if (list == NULL)
    {
      my_putstr_error("[GETS_LIST:38] Error: aff_list1() is fail.\n");
      my_putstr_error("The struct list is NULL.\n");
      exit(1);
    }
  else
    {
      datas = list->first;
      while (datas->complements != NULL)
	{
	  my_putstr(datas->complements);
	  datas = datas->next;
	  my_putchar('\n');
	}
    }
}

void		aff_list_pronom(t_list1 *list)
{
  t_datas	*datas;
  
  if ((datas = malloc(1 * sizeof (*datas))) == NULL)
    {
      my_putstr_error("[GETS_LIST:9] Error malloc() is fail.\n");
      my_putstr_error("The struct datas is NULL.\n");
      exit(1);
    }
  else if (list == NULL)
    {
      my_putstr_error("[GETS_LIST:38] Error: aff_list1() is fail.\n");
      my_putstr_error("The struct list is NULL.\n");
      exit(1);
    }
  else
    {
      datas = list->first;
      while (datas->pronom != NULL)
	{
	  my_putstr(datas->pronom);
	  datas = datas->next;
	  /* my_putchar('\n'); */
	}
    }
}

void		aff_verbe(t_list1 *list)
{
  t_datas	*datas;

  if ((datas = malloc(1 * sizeof (*datas))) == NULL)
    {
      my_putstr_error("[GETS_LIST:9] Error malloc() is fail.\n");
      my_putstr_error("The struct datas is NULL.\n");
      exit(1);
    }
  else if (list == NULL)
    {
      my_putstr_error("[GETS_LIST:38] Error: aff_list1() is fail.\n");
      my_putstr_error("The struct list is NULL.\n");
      exit(1);
    }
  else
    {
      datas = list->first;
      while (datas != NULL)
	{
	  my_putstr(datas->verbes);
	  datas = datas->next;
	  my_putchar('\n');
	}
    }
}

void		aff_list(t_list1 *list, char *str)
{
  int		i;
  t_aff       flags1[]= {
    {"verbe", aff_verbe},
    {"pronom", aff_list_pronom},
    {"com", aff_list_complements},
  };
  i = 0;
  while (i < 3)
    {
      if (strcmp(str, flags1[i].flags) == 0)
        flags1[i].aff(list);
      i++;
    }
}
