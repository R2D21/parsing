NAME	=	bin/parse

RM	=	rm -f

CC	=	/usr/bin/gcc

CFLAGS	=	-I /usr/include/ -I includes/ -faggressive-loop-optimizations -W -Wall -Werror -ansi -pedantic -std=gnu99

GFLAGS	=	-I /usr/include/ -I includes/-faggressive-loop-optimizations -g3 -ggdb -W -Wall -Werror -ansi -pedantic -std=gnu99

SRCS	=	src/main.c \
		src/cmd.c \
		src/init_list.c \
		src/gets_list.c \
		src/list/my_list.c \
		src/list/del.c \
		src/list/init.c \
		src/list/aff_list.c \
		src/checks/checkComplement_list.c \
		src/checks/check_list.c \
		src/checks/check_list1.c \
		src/historique_list.c \

OBJS	=	$(SRCS:.c=.o)

ECHO	=	echo -e

all	:	$(NAME)

$(NAME)	:	$(OBJS)

		$(CC)  $(CFLAGS) $(OBJS) -o $(NAME) -lmy

clean	:

		$(RM) $(OBJS)

fclean	:	$(clean)
		$(RM) $(NAME)

re	:	fclean all

debug	:	$(OBJS)

		$(RM) $(NAME)
		$(CC)  $(GFLAGS) $(OBJS) -o $(NAME) -lmy
		$(RM) $(OBJS)

.PHONY	: all clean fclean re
