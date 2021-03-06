#ifndef	_LIST_H_
# define _LIST_H_

typedef struct	t_AI t_AI;

struct  t_AI
{
  char		*verbe;		/* le verbe de la phrase */
  char		*sujet;	/* le verbe de la phrase */
  char		*complement;	/* le complement de la phrase */
  char		*key;		/* le mot clef */
  t_AI		*next;		/* élement suivant */
}	        ;

typedef struct	s_keys
{
  t_AI		*first;		/* sauvegarde l'addresse du début de la liste */
}		t_keys;

typedef struct	t_datas t_datas;

struct  t_datas
{
  char		*verbes;	/* les verbes */
  char		*sujets;	/* les sujets */
  char		*complements;	/* les complements */
  char		*pronom;	/* pour vérifier la conjugaison du verbe */
  char		*terminaison;	/* terminaison du verbe pour pouvoir vérifier la congugaison de celui-ci */
  t_datas	*next;		/* élements suivant */
};

typedef struct	s_list1
{
  t_datas	*first;		/* sauvegarde l'addresse du début de la liste */
}		t_list1;

typedef	struct	s_gere
{
  t_list1	*list;
  char		**tab;
}		t_gere;

typedef struct s_param
{
  char  *flag;
  void  (*p)(t_gere*);
}		t_params;

typedef struct s_param1
{
  char  *flags;
  void  (*p1)(t_list1*, char *);
}		t_params1;

typedef struct s_aff
{
  char  *flags;
  void  (*aff)(t_list1*);
}		t_aff;

t_AI		*init_AI(t_AI *AI); /* Initialiise la structure AI. src/init.c */

t_gere		*init_gere(t_gere *gere);

t_datas		*del_verbe_list(t_datas *datas, char *str); /* supprime le verbe dans la liste chainée datas. src/list/del.c */

t_list1		*init_list();	/* Initialise la liste chainée qui contiendra les datas. src/init_list.c */

void	        del_list(t_list1 *list); /* détruit la liste chainée datas. src/list/del.c */
void		aff_list_complements(t_list1 *list);		/* affiche tout les complements stockés dans datas->complement. */
void		aff_list(t_list1 *list, char *str); /* Affiche la liste chainée datas. src/my_list.c */
void		add_list(t_gere *gere, char *str, char *s1); /* Ajoute les datas dans la liste chainée datas. src/my_list.c */
void		add_list_tem(t_gere *gere/* t_list1 *list, char **str */); /* Ajoute la terminaison des verbes dans la liste chainée datas.
							src/my_list.c */
void		add_list_pronom(t_gere *gere/* t_list1 *list, char **tab */); /* Ajoute la terminaison des verbes dans la liste chainée datas. src/my_								list.c */
void		aff_list_pronom(t_list1 *list); /* Affiche les terminaison des verbes de la liste chainée datas */
void		aff_list_term(t_list1 *list); /* Affiche les terminaison des verbes de la liste chainée datas */
void		add_list_complements(t_list1 *list, char *str); /* Ajoute les complements à la liste chainée datas */
void		gere_list(t_gere *gere, char *str,char *s1);
void		add_verbe(t_list1 *list, char *str);

#endif
