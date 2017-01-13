#include "../includes/my.h"

void		get_verbe_list(t_gere *gere)
{
  char		*str;
  int		i;

  i = 0;
  str = malloc(4096 * sizeof(char));
  read(open("datas/verbes", S_IRUSR), str, 4095);
  gere->tab = my_wordtab(str, ';');
  if (gere->list == NULL)
    my_putstr_error("Error\n");
  else
    {
      while (*gere->tab[i] != '\0')
        add_list(gere, "verbe", gere->tab[i++]);
    }
}

void		get_complements_list(t_gere *gere)
{
  char		*str;
  int		i;

  i = 0;
  str = malloc(4096 * sizeof(char));
  read(open("datas/complements", S_IRUSR), str, 4095);
  gere->tab = my_wordtab(str, ';');
  if (gere->list == NULL)
    my_putstr_error("Error\n");
  else
    {
      while (*gere->tab[i] != '\0')
	add_list(gere, "com", gere->tab[i++]);
    }
}
