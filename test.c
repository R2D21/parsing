#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bonjour ( char *str,  char *str1);
void adieu ( char *str, char *s);

void	bonjour (char *str, char *s)
{
  printf("%s\n", s);
}

void    adieu (char *str, char *s)
{
  printf("%s\n", str);
}

typedef struct s_param
{
  char  *flag;
  void  (*p)(char*, char*);
}		t_params;

int main ( void )
{
  int           i;
  char		*str = "bonjour";
  t_params       flags[]= {
    {"bonjour", bonjour},
    {"adieu", adieu},
  };

  i = 0;
  while (i < 2)
    {
      if (strcmp(str, flags[i].flag) == 0)
	flags[i].p(str, ".");
      i++;
    }
  return 0;
}
