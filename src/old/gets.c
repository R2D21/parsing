#include "../includes/my.h"

void	get_verbes(t_AI *AI)
{
  char	*buff;

  if ((buff = malloc(4096 * sizeof (char))) == NULL)
    my_putstr_error("[CMD:9] Error: malloc is fail.\nbuff is NULL\n");
  else
    {
      read(open("datas/verbes", S_IRUSR), buff, 4095);
      AI->verbes = my_wordtab(buff, ';');
      //my_puttab(AI->verbes);
    }
}

void	get_sujets(t_AI *AI)
{
  char	*buff;

  if ((buff = malloc(4096 * sizeof (char))) == NULL)
    my_putstr_error("[CMD:9] Error: malloc is fail.\nbuff is NULL\n");
  else
    {
      read(open("datas/sujets", S_IRUSR), buff, 4095);
      AI->sujets= my_wordtab(buff, ';');
      //  my_puttab(AI->sujets);
    }
}
