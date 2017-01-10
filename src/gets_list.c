#include "../includes/my.h"

void		get_verbe_list(t_list1	*list)
{
  char		*str;
  char		**tab;
  int		i;

  i = 0;
  tab = NULL;
  tab = malloc_tab(tab);
  str = malloc(4096 * sizeof(char));
  read(open("datas/verbes", S_IRUSR), str, 4095);
  tab = my_wordtab(str, ';');
  if (list == NULL)
    my_putstr_error("Error\n");
  else
    {
      while (*tab[i] != '\0')
      	add_list(list, tab[i++]);
    }
}

void		get_complements_list(t_list1	*list)
{
  char		*str;
  char		**tab;
  int		i;

  i = 0;
  tab = NULL;
  tab = malloc_tab(tab);
  str = malloc(4096 * sizeof(char));
  read(open("datas/complements", S_IRUSR), str, 4095);
  tab = my_wordtab(str, ';');
  if (list == NULL)
    my_putstr_error("Error\n");
  else
    {
      while (*tab[i] != '\0')
      	add_list_complements(list, tab[i++]);
    }
}
