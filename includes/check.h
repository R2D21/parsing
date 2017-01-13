#ifndef _CHECK_H
#define _CHECK_H_

int		check_verbe_list(t_list1 *list, char **tab); /* vérifie si le verbe entré est reconnu. src/check_list.c */
int		check_verbe_G1(t_list1 *list, char *str, t_gere *gere);    /*  Vérifie la conjugaison des verbes du premier groupe */
int		check_verbe_G2(t_list1 *list, char *str, t_gere *gere);    /* Vérifie la conjugaison des verbes du seconds groupe */
int		check_conjugaison(t_list1 *list,char *buff, t_gere *gere); /*  Récupère les valeurs retournées par check_verbe_G1
								et check_verbe_G2 */
int		check_complements_list(t_list1 *list, char **tab); /* Vérifie si le complément de la phrase est connu. */

#endif
