#include "../includes/my.h"

int		check_conjugaison(t_list1 *list, char *buff)
{
  if ((check_verbe_list(list, my_wordtab(buff, ' '))) == 0)
    {
      if (check_verbe_G1(list, buff) == 0)
      	return (0);
      else if (check_verbe_G2(list, buff) == 0)
      	return (0);
      else
	return (1);
    }
  return (-1);
}

void		AI(t_list1 *list, char *buff)
{
  char		**tab;

  tab = NULL;
  tab = malloc_tab(tab);
  tab = my_wordtab(buff, ' ');
  get_verbe_list(list);
  if ((check_conjugaison(list, buff)) == 0)
    {
      get_complements_list(list);
      if ((check_complements_list(list, tab)) == 0)
      	my_putstr("Je reconnais la syntaxe de la phrase.\n");
      else
      	my_putstr("Je ne reconnais pas la syntaxe de la phrase.\n");
    }
}

int		cmd(/* t_AI *AI */)
{
  char		*buff;
  t_list1	*list;

  if ((buff = malloc(4096 * sizeof (char))) == NULL)
    my_putstr_error("[CMD:8] Error: malloc () is fail.\nbuff is NULL.\n");
  else
    {
      my_putstr("-->");
      if ((list = init_list()) == NULL)
	{
	  my_putstr_error("[GETS_LIST:] Error init_list() is fail.\n");
	  my_putstr_error("The struct list is NULL.\n");
	}
      else if ((read(0, buff, 4095)) == 0)
	{
	  my_putchar('\n');
	  del_list(list);
	  free(buff);
	  return (0);
	}
      else
	AI(list, buff);
    }
  return (42);
}
