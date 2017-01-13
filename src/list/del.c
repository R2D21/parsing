#include "../includes/my.h"

void	        del_list(t_list1 *list)
{
  t_datas	*datas;

  if ((datas = malloc(1 * sizeof(*datas))) == NULL)
    {
      my_putstr_error("[MY_LIST:32] Error: malloc() is fail.\n");
      my_putstr_error("The struct datas is NULL.\n");
      exit(1);
    }
  else if (list == NULL)
    {
      my_putstr_error("[MY_LIST:38] Error: the struct list is NULL.\n");
      exit(1);
    }
  else 
    {
      datas = list->first;
      while (datas != NULL)
	{
	  free(datas->verbes);
	  datas = datas->next;
	}
      free(datas);
      free(list->first);
      free(list);
    }
}

t_datas		*del_verbe_list(t_datas *prem, char *str)
{
  t_datas	*n;
  t_datas	*prec;

  if(prem != NULL){
    if(strcmp(prem->verbes,str) == 0){// si premier
      n = prem;
      prem = prem->next;
      free(n);
    }
    else{             // sinon voir les autres
      prec = prem;
      n = prem->next;
      while(n != NULL ){
	if (strcmp(n->verbes , str) == 0){
	  prec->next =n->next;
	  free(n);
	  break;
	}
	prec = n;
	n = n->next;
      }
    }
  }
  return prem;
}
