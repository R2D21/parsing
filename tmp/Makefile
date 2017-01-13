NAME	=	bin/parse

RM	=	rm -f

CC	=	gcc

CFLAGS	=	-I /usr/include/ -I includes/ -faggressive-loop-optimizations -W -Wall -Werror -ansi -pedantic -std=gnu99

GFLAGS	=	-I /usr/include/ -I includes/ -faggressive-loop-optimizations -g3 -ggdb -W -Wall -Werror -ansi -pedantic -std=gnu99

SRCS	=	src/main.c \
		src/cmd.c \
		src/init_list.c \
		src/gets_list.c \
		src/check_list.c \
		src/check_list1.c \
		src/my_list.c \
		src/del.c \
		src/aff_list.c \
		src/checkComplement_list.c \

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

debug	:	$(CC)  $(GFLAGS) $(OBJS) -o $(NAME) -lmy

.PHONY	: all clean fclean re
