NAME		= printf_tester

CC			= gcc -g -fsanitize=address -Wall -Wextra -Werror
PRINTF_LIB	= ../printf/libftprintf.a
PRINTF_SRC	= ../printf/
OBJ			= main.o


all	: $(NAME)

$(NAME) : $(OBJ) make_lib
	${CC} -o $(@) main.c $(PRINTF_LIB) -I$(PRINTF_SRC).

make_lib:
	$(MAKE) -C $(PRINTF_SRC) 

clean:
	$(RM) $(NAME) $(OBJ)
	$(MAKE) -C $(PRINTF_SRC) fclean

re: clean all

.PHONY: ../ft_printf/libftprintf.a clean printf_tester all

# __my_srcs	= ft_printf

# TIMEOUT		= 10
# CFLAGS		= -g -fsanitize=address -Wall -Wextra -Werror
# STRICT		=
# UTILS 		= utils/malloc_mock.c utils/utils.c pf_utils.c
# PRINTF_LIB	= ../$(__my_srcs)/libftprintf.a
# TIMEOUT_ARG	= -D TIMEOUT=$(TIMEOUT)

# ifdef EXEC_STRICT
# STRICT		= -D STRICT_MEM
# endif

# build_m:
# 	-@$(MAKE) -C ../$(__my_srcs) fclean 1> /dev/null
# 	-@$(MAKE) -s -C ../$(__my_srcs) all 1> /dev/null
# 	-@clang $(CFLAGS) $(TIMEOUT_ARG) $(STRICT) $(UTILS) mandatory.c $(PRINTF_LIB) -ldl -o printf.out

# build_b:
# 	-@$(MAKE) -C ../$(__my_srcs) fclean 1> /dev/null
# 	-@$(MAKE) -s -C ../$(__my_srcs) bonus 1> /dev/null
# 	-@clang $(CFLAGS) $(TIMEOUT_ARG) $(STRICT) $(UTILS) bonus.c $(PRINTF_LIB) -ldl -o printf_b.out