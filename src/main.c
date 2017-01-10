#include "../includes/my.h"

int	main()
{
  while (1)
    if ((cmd()) == 0)
      return (0);
  return (42);
}
