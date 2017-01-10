#include "../includes/my.h"

int		check_verbe_list(t_list1 *list, char **tab)
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
	  while (*tab[j] != '\0')
	    if (strncmp(datas->verbes, tab[j], my_strlen(datas->verbes)) == 0)
	      return (0);
	    else
	      j++;
	  datas = datas->next;
	  j = 0;
	}
    }
  return (1);
}

int	        conjugaison1(t_datas *datas,char **buff, int i)
{
  while (datas->pronom != NULL)
    {
      if (strcmp(buff[i], datas->pronom) == 0)
	{
	  i++;
	  if (buff[i][my_strlen(buff[i]) - 1] == datas->terminaison[0])
	    return (0);
        }
      else
      datas = datas->next;
    }
  return (1);
}

int	        conjugaison2(t_datas *datas,char **buff, int i)
{
  while (datas->pronom != NULL)
    {
      if (strcmp(buff[i], datas->pronom) == 0)
	{
	  i++;
	  if (buff[i][my_strlen(buff[i]) - 3] == datas->terminaison[0])
	    if (buff[i][my_strlen(buff[i]) - 2] == datas->terminaison[1])
	      if (buff[i][my_strlen(buff[i]) - 1] == datas->terminaison[2])
		return (0);
        }
      else
      datas = datas->next;
    }
  return (1);
}

int		func1(char **tab, t_list1 *list, char *str, int i)
{
  char		*tmp;
  t_datas	*datas;
  
  if ((tmp = malloc(4096 * sizeof(char))) == NULL)
    my_putstr_error("[CHECK_LIST:39] Error: malloc() is fail.\ntab is NULL.\n");
  else
    {
      if ((datas = malloc(1 * sizeof (*datas))) == NULL)
	my_putstr_error("[CHECK_LIST:57] Error: malloc() is fail.\nstruct datas is NULL.\n");
      else
	{
	  tab = my_wordtab(str, ' ');
	  do
	    {
	      my_strcpy(tab[i], tmp);
	      if ((conjugaison1((datas = list->first), tab, i)) == 0)
		return (0);
	      else if ((conjugaison2(datas, tab, i)) == 0)
		return (0);
	      else
		i++;
	    }while (tmp[i] != '\0');
	}
    }
  return (1);
}

int		check_verbe_G1(t_list1 *list, char *str)
{
  char		*buff;
  char		**tab;
  int		i;
  
  i = 0;
  tab = NULL;
  if ((buff = malloc(4096 * sizeof (char))) == NULL)
    my_putstr_error("[CHECK_LIST:36] Error: malloc() is fail.\nbuff is NULL.\n");
  else if ((tab = malloc_tab(tab)) == NULL)
    my_putstr_error("[CHECK_LIST:39] Error: malloc() is fail.\ntab is NULL.\n");
  else
    {
      read(open("datas/conjugaison", S_IRUSR), buff, 4095);
      tab = my_wordtab(buff, ';');
      add_list_tem(list, tab);
      add_list_pronom(list, tab);
      if ((func1(tab, list, str, i)) == 0)
	return (0);
    }
  return (-1);
}
