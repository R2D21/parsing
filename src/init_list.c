#include "../includes/my.h"



t_list1		*init_list()
{
  t_list1	*list;
  t_datas	*datas;
  
  if ((list = malloc(1 * sizeof (*list))) == NULL)
    my_putstr_error("[INIT_LIST:6] Error: malloc is fail.\nStruct list is NULL.\n");
  else
    if ((datas = malloc(1 * sizeof (t_datas))) == NULL)
      {
	my_putstr_error("[INIT_LIST:12] Error: malloc() is fail.\n");
	my_putstr_error("The struct datas is NULL.\n");
      }
    else
      if ((datas->verbes = malloc(4096 * sizeof(*datas->verbes))) == NULL)
	{
	  my_putstr_error("[INIT_LIST:19] Error: malloc_tab() is fail.\n");
	  my_putstr_error("datas->verbes is NULL.\n");
	}
      else if ((datas->sujets = malloc(4096 * sizeof(*datas->sujets))) == NULL)
	{
	  my_putstr_error("[INIT_LIST:24] Error: malloc_tab() is fail.\n");
	  my_putstr_error("datas->sujets is NULL.\n");
	}
      else
	if ((datas->complements = malloc(4096 * sizeof (*datas->complements))) == NULL)
	{
	  my_putstr_error("[INIT_LIST:30] Error: malloc_tab() is fail.\n");
	  my_putstr_error("datas->complements is NULL.\n");
	}
	else
	  if ((datas->pronom = malloc(4096 * sizeof (char))) == NULL)
	    my_putstr_error("[INIT_LIST:37] Error: malloc() is fail.\n");
	  else if ((datas->terminaison = malloc(4096 *sizeof (char))) == NULL)
	    my_putstr_error("[INIT_LIST:39] Error: malloc() is fail.\n");
	  else
	    return (list);
  return (NULL);
}
