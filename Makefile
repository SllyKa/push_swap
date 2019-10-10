#
#	Debug compiler variables
#

DG_CC_FLAGS= -g -O0

#
#	Compiler variables
#

CC= gcc
CC_FLAGS= -Wall -Wextra -Werror

#
#	Checker release variables
#

NAME= checker
LIBDIR= libftprintf
LIB= libftprintf.a
LIBHEADER=libftprintf.h
LIBSHORT= ftprintf
HEADERDIR= includes
HEADER= ft_ps_checker.h
SRCS1= ft_stack.c \
		ft_ps_operations.c \
		ft_ps_operations_3.c \
		ft_ps_operations_2.c \
		ft_ps_checker.c \
		ft_ps_checker_free.c \
		ft_ps_checker_err_chk.c \
		ft_ps_avlt_service.c \
		ft_ps_avlt_integration.c
OBJ1= $(SRCS1:.c=.o)

all: $(NAME)

#
#	Debug mode settings
#

debug: CC_FLAGS += $(DG_CC_FLAGS)
debug: $(NAME)

#
#	Release mode
#

$(NAME): $(LIB) $(OBJ1)
	$(CC) $(CC_FLAGS) $(OBJ1) -L$(LIBDIR) -l$(LIBSHORT) -o $@

$(LIB):
	cd $(LIBDIR) && $(MAKE) -s #&& $(MAKE) clean

%.o: %.c $(HEADERDIR)/$(HEADER)
	$(CC) $(CC_FLAGS) -I$(HEADERDIR) -I$(LIBDIR)/$(HEADERDIR) -c $^

#
#	Clean
#

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all