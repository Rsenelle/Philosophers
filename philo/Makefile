NAME		=	philosophers

HEADER		=	philo.h

SRC			=	life_cycle.c	main.c	 init_struct.c	utils.c		philo_thread_create.c	ft_time.c

OBJ			=	$(SRC:.c=.o)

FLAGS		=	-Wall -Wextra -Werror

%.o: %.c	$(HEADER)
			@echo 'Some magic...'`gcc $(FLAGS) -o $@ -c $< -I $(HEADER) -o $(<:.c=.o)`''

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
			@echo 'Done'`gcc $(FLAGS) $(OBJ) -o $(NAME)`''

clean:
		@echo 'Cleaned'`rm -rf $(OBJ)`''


fclean:	clean
		@echo 'Cleaned all'`rm -rf $(NAME)`''

re:		fclean all

.PHONY:	all clean fclean re