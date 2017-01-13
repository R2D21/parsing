#include "../includes/my.h"

/* on stockera str dans une liste doublement chainées */

void		update_historique(char *str)
{
  FILE	        *fichier;

  fichier = NULL;
  fichier = fopen("datas/historique", "a+");
  /* if (fd > 0) */
  /*   { */
  /* printf("%s\n", str); */
  fwrite(str, sizeof(char), my_strlen(str), fichier);
  /*   } */
  /* else */
  /*   my_putstr_error("[HISTORIQUE_LIST:16] Error open() is fail.\n"); */
}

void		delete_historique()
{
  FILE	        *fichier;

  fichier = NULL;
  fichier = fopen("datas/historique", "w");
  if (fichier != NULL)
    remove("datas/historique");
    /*   } */
  else
    my_putstr_error("[HISTORIQUE_LIST:16] Error fopen() is fail.\n");
}

char		**parse_historique(char *str)
{
  return (my_wordtab(str, '.'));
}
