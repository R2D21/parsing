#include "../includes/my.h"

int		check_complement(t_datas *datas, char **tab, int j)
{
  while (*tab[j] != '\0')
    {
      if (datas->complements != NULL)
	{
	  if ((my_strncmp(datas->complements, tab[j], my_strlen(datas->complements))) == 0)
	    return (0);
	  else
	    j++;
	}
      else
	return (1);
    }
  return (1);
}

int		check_complements_list(t_list1 *list, char **tab)
{
  t_datas	*datas;
  int		j;

  j = 0;
  if ((datas = malloc(1 * sizeof (*datas))) == NULL)
    {
      my_putstr_error("[CHECK_LIST:8] Error: malloc() is fail.\n");
      my_putstr_error("The struct datas is NULL.\n");
    }
  else
    {
      datas = list->first;
      while (datas != NULL)
	{
	  if ((check_complement(datas, tab, j)) == 0)
	    return (0);
	  datas = datas->next;
	  j = 0;
	}
    }
  return (1);
}
