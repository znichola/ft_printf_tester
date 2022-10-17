NAME		= printf_tester

CC			= gcc
PRINTF_SRC	= ../ft_printf/libftprintf.a
OBJ			= main.o


all	: $(NAME)

$(NAME) : $(OBJ) $(PRINTF_SRC)
	$(MAKE) -C ../ft_printf/ libftprintf.a
	${CC} -o $(@) main.c $(PRINTF_SRC) -I../ft_printf/.

$(PRINTF_SRC):
	$(MAKE) -C ../ft_printf/ libftprintf.a

clean:
	$(RM) $(NAME) $(OBJ)
	$(MAKE) -C ../ft_printf/ fclean
