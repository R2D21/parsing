#include "../includes/my.h"

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
	  while (tab[j][0] != '\0')
	    if ((strncmp(datas->complements, tab[j], my_strlen(datas->complements))) == 0)
	      return (0);
	    else
	      j++;
	  datas = datas->next;
	  j = 0;
	}
    }
  return (1);
}
