#include "../includes/my.h"

int		check_conjugaison(t_list1 *list,char *buff, t_gere *gere)
{
  gere->list = list;
  if ((check_verbe_list(gere->list, my_wordtab(buff, ' '))) == 0)
    {
      if (check_verbe_G1(gere->list, buff, gere) == 0)
      	return (0);
      else if (check_verbe_G2(gere->list, buff, gere) == 0)
      	return (0);
      else
	return (1);
    }
  return (-1);
}

void		checks(t_gere *gere, char *buff, char **tab)
{
  if ((check_conjugaison(gere->list, buff, gere)) == 0)
    {
      get_complements_list(gere);
      if ((check_complements_list(gere->list, tab)) == 0)
	{
	  my_putstr("\033[31;32mJe reconnais la syntaxe de la phrase.\033[0m\n");
	  my_putchar('\n');
	  update_historique(buff);
	}
      else
	{
	  my_putstr("\033[0;31mJe ne reconnais pas la syntaxe de la phrase.\033[0m\n");
	  my_putchar('\n');
	}
    }
}

void	        IA(t_list1 *list, char *buff)
{
  char		**tab;
  t_gere	*gere;

  tab = NULL;
  gere = NULL;
  tab = malloc_tab(tab);
  tab = my_wordtab(buff, ' ');
  if ((gere = init_gere(gere)) == NULL)
    my_putstr_error("[CMD:28] Error: init_gere() is fail.\n");
  else
    {
      gere->list = list;
      get_verbe_list(gere);
      checks(gere, buff, tab);
    }
}

int		search(t_list1 *list)
{
  
  aff_list(list, "verbe");
  return (1);
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
	IA(list, buff);
    }
  return (42);
}
