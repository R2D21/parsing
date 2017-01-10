#include "../includes/my.h"

int	check(t_AI *AI, char **tab, int i)
{
  int	j;

  j = 0;
  while (*tab[j] != '\0')
    if (strcmp(AI->verbes[i],  tab[j]) == 0)
      return (0);
    else
      j++;
  return (1);
}

int	check_verbes(t_AI *AI, char *str)
{
  int	i;
  char	**tab;

  tab = NULL;
  tab = malloc_tab(tab);
  i = 0;
  if (*str == '\0')
    my_putstr_error("[CHECK:6] Error: str or AI->verbes is empty.\n");
  else
    {
      while (*AI->verbes[i] != '\0')
	if (check(AI, (tab = my_wordtab(str, ' ')), i) == 0)
	  return (0);
	else
	  i++;
      return (1);
    }
  return (-1);
}
