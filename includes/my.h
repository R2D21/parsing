#ifndef _MY_H_
#define _MY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <libmy.h>
#include <string.h>
#include "list.h"
#include "check.h"

int		cmd();		/* src/cmd.c */

/* t_datas		*deleteNode (t_datas * L, char *val); */


void		get_verbe_list(t_gere *gere);	/* Récupère les verbes. src/gets_list.c */

void		get_complements_list(/* t_list1 *list */t_gere *gere);		/* récupère et stockes tout les complements dans datas */
void		update_historique(char *str); /* stocke toutes les phrases entrées par l'utilisateur. historique_list.c */
void		delete_historique();	      /* supprime l'historique */

#endif
